#include <stdio.h>

__global__ void printKernel() {
    printf("Hello from CUDA kernel! Block: %d, Thread: %d\n", blockIdx.x, threadIdx.x);
}

int main() {
    printKernel<<<2, 4>>>();

    cudaDeviceSynchronize();

    return 0;
}
