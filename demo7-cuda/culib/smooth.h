#ifndef MI_SMOOTH_H
#define MI_SMOOTH_H

class Smooth {
public:
    Smooth();
    ~Smooth();
    int compute(unsigned char* rgb, int w, int h, int iterator);
};

#endif