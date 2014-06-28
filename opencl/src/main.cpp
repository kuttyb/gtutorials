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
