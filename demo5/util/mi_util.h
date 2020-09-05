#ifndef MI_UTIL_H
#define MI_UTIL_H

#include <boost/thread/mutex.hpp>

class Util {
public:
    Util();
    ~Util();
    void parallel_print();
private:
    boost::mutex _mutex;
};

#endif