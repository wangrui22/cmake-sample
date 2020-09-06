#include <cuda_runtime.h>
#include <iostream>
#include "smooth.h"

extern "C" 
cudaError_t smooth(unsigned char *rgb, int w, int h, unsigned char *rgb_out);

Smooth::Smooth() {

}

Smooth::~Smooth() {

}

int Smooth::compute(unsigned char* rgb, int w, int h, int iterator) {
    if (iterator < 1) {
        std::cout << "invalid iterator.\n";
        return -1;
    }
    unsigned char* d_rgb[2] = {nullptr,nullptr};
    const size_t len = w*h*3;
    cudaError_t err = cudaMalloc(&(d_rgb[0]), len);
    if (err != cudaSuccess) {
        std::cout << "cuda malloc failed\n";
        return -1;
    }
    err = cudaMalloc(&(d_rgb[1]), len);
    if (err != cudaSuccess) {
        std::cout << "cuda malloc failed\n";
        return -1;
    }

    err = cudaMemcpy(d_rgb[0], rgb, len, cudaMemcpyHostToDevice);
    if (err != cudaSuccess) {
        std::cout << "cuda memcpy failed\n";
        return -1;
    }

    int src = 0;
    for (int i=0; i<iterator; ++i) {
        err = smooth(d_rgb[src], w, h, d_rgb[1-src]);
        if (err != cudaSuccess) {
            std::cout << "cuda smooth failed\n";
            return -1;
        }
        src = 1 - src;
        std::cout << "smooth iterator: " << i+1 << std::endl;
    }
    
    err = cudaMemcpy(rgb, d_rgb[src], len, cudaMemcpyDeviceToHost);
    if (err != cudaSuccess) {
        std::cout << "cuda smooth failed\n";
        return -1;
    }
    
    cudaFree(d_rgb[0]);
    cudaFree(d_rgb[1]);

    return 0;
}

