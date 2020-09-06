#include "smooth.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {

    std::ifstream in("/data0/data/test/img_1920_1080.raw", std::ios::in | std::ios::binary);
    if (!in.is_open()) {
        std::cout << "open failed.\n";
        return -1;
    }

    int w = 1920;
    int h = 1080;
    unsigned char * rgb = new unsigned char[3*w*h];
    in.read((char*)rgb, w*h*3);
    in.close();

    Smooth smooth;
    smooth.compute(rgb, w, h, 5);
    
    std::ofstream out("/data0/data/test/img_1920_1080_out.raw", std::ios::out | std::ios::binary);
    if (!out.is_open()) {
        std::cout << "open failed 2.\n";
        return -1;
    }

    out.write((char*)rgb, w*h*3);
    out.close();

    delete [] rgb;

    return 0;
}