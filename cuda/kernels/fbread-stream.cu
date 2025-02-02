#include <cuda_runtime.h>
#include <iostream>

#define BLOCK_SIZE 256

__global__ void peak_bw_kernel(const float * __restrict__ d_input, float * __restrict__ d_output, int N) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    // Use a loop to ensure sustained memory bandwidth utilization
    float sum = 0.0f;
    for (int i = idx; i < N; i += gridDim.x * blockDim.x) {
        sum += d_input[i];  // Coalesced global memory access
    }

    d_output[idx] = sum;  // Write back to global memory
}

void runKernel(int N) {
    float *d_input, *d_output;
    cudaMalloc(&d_input, N * sizeof(float));
    cudaMalloc(&d_output, N * sizeof(float));

    dim3 blockSize(BLOCK_SIZE);
    dim3 gridSize((N + BLOCK_SIZE - 1) / BLOCK_SIZE);

    peak_bw_kernel<<<gridSize, blockSize>>>(d_input, d_output, N);
    cudaDeviceSynchronize();

    cudaFree(d_input);
    cudaFree(d_output);
}

int main() {
    int N = 1 << 26;  // Large enough to saturate memory bandwidth
    runKernel(N);
    return 0;
}
