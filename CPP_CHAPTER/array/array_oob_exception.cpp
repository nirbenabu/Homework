#include "array_oob_exception.hpp"
#include<iostream>

void ArrayOutOfBoundsException::printInfo() {
    ArrayException::printInfo();
    std::cerr<<"\tIndex: "<<_iIndex<<"  Bounds: "<< _iBounds<<std::endl;
}
