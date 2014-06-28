//
//  main.cpp
//  opencl
//
//  Created by kuttyb on 6/28/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#include <iostream>
#include <OpenCL/OpenCL.h>

char * program_buffer = " __kernel void add_numbers(__global float4* data,\n"
    "__local float* local_result, __global float* group_result) {\n"
    "float sum;\n"
    "float4 input1, input2, sum_vector;\n"
    "uint global_addr, local_addr;\n"
    "global_addr = get_global_id(0) * 2;\n"
    "input1 = data[global_addr];\n"
    "input2 = data[global_addr+1];\n"
    "sum_vector = input1 + input2;\n"
    "local_addr = get_local_id(0);\n"
    "local_result[local_addr] = sum_vector.s0 + sum_vector.s1 +\n"
    "sum_vector.s2 + sum_vector.s3;\n"
    "barrier(CLK_LOCAL_MEM_FENCE);\n"
    "if(get_local_id(0) == 0) {\n"
    "    sum = 0.0f;\n"
    "    for(int i=0; i<get_local_size(0); i++) {\n"
    "        sum += local_result[i];\n"
    "    }\n"
    "    group_result[get_group_id(0)] = sum;\n"
    "}\n"
"}\n";

int main(int argc, const char * argv[]) {
    cl_platform_id platform;
    clGetPlatformIDs(1, &platform, NULL);
    
    cl_device_id device;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
    
    cl_int err;
    cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
    
    size_t program_size = sizeof(program_buffer);
    cl_program program = clCreateProgramWithSource(context, 1,
                                                   (const char**)&program_buffer, &program_size, &err);
    clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    
    cl_kernel kernel = clCreateKernel(program, "add_numbers", &err);
    
    cl_command_queue queue = clCreateCommandQueue(context, device, 0, &err);
    
    const size_t global_size = 8;
    const size_t local_size = 4;
    clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
