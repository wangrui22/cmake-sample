#include <vector_types.h>
#include <cuda_runtime.h>

__global__ void kernel_smooth(unsigned char *rgb, int w, int h, unsigned char *rgb_out) {
    unsigned int x = blockDim.x * blockIdx.x + threadIdx.x;
    unsigned int y = blockDim.y * blockIdx.y + threadIdx.y;

    if (x < 1 || x > w-1 || y < 1 || y > h-3){
        return;
    }
    
    unsigned int x0 = x - 1;
    unsigned int y0 = y - 1;
    unsigned int x1 = x;
    unsigned int y1 = y;
    unsigned int x2 = x + 1;
    unsigned int y2 = y + 1;

    unsigned int i00 = y0*w + x0;
    unsigned int i01 = y1*w + x0;
    unsigned int i02 = y2*w + x0;
    unsigned int i10 = y0*w + x1;
    unsigned int i11 = y1*w + x1;
    unsigned int i12 = y2*w + x1;
    unsigned int i20 = y0*w + x2;
    unsigned int i21 = y1*w + x2;
    unsigned int i22 = y2*w + x2;

    int r = (int)rgb[3*i00] + (int)rgb[3*i01] + (int)rgb[3*i02] +
            (int)rgb[3*i10] + 2*(int)rgb[3*i11] + (int)rgb[3*i12] +
            (int)rgb[3*i20] + (int)rgb[3*i21] + (int)rgb[3*i22];
    r /= 10;

    int g = (int)rgb[3*i00+1] + (int)rgb[3*i01+1] + (int)rgb[3*i02+1] +
            (int)rgb[3*i10+1] + 2*(int)rgb[3*i11+1] + (int)rgb[3*i12+1] +
            (int)rgb[3*i20+1] + (int)rgb[3*i21+1] + (int)rgb[3*i22+1];
    g /= 10;

    int b = (int)rgb[3*i00+2] + (int)rgb[3*i01+2] + (int)rgb[3*i02+2] +
            (int)rgb[3*i10+2] + 2*(int)rgb[3*i11+2] + (int)rgb[3*i12+2] +
            (int)rgb[3*i20+2] + (int)rgb[3*i21+2] + (int)rgb[3*i22+2];
    b /= 10;
    
    rgb_out[i11*3] = r;
    rgb_out[i11*3+1] = g;
    rgb_out[i11*3+2] = b;
}

extern "C" 
cudaError_t smooth(unsigned char *rgb, int w, int h, unsigned char *rgb_out) {
    dim3 block(16, 16, 1);
    dim3 grid(w / 16, h / 16, 1);

    kernel_smooth<<<grid, block>>>(rgb, w, h, rgb_out);
    

    return cudaDeviceSynchronize();
}