#include "mi_util.h"
#include <iostream>

Util::Util() {

}


Util::~Util() {

}

void Util::parallel_print() {
    boost::mutex::scoped_lock locker(_mutex);
    std::cout << "in parallel print\n";
}
