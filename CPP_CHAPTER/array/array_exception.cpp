#include <iostream>
#include "array_exception.hpp"

#if !defined (NULL)
#define NULL ((void*)0)
#endif

void ArrayException::printInfo() {
    if(_info!=NULL)
        std::cerr<<"SAFE_ARRAY_ERROR: "<<_info<<std::endl;
    else
        std::cerr<<"SAFE_ARRAY_ERROR: UNKNOWN ERROR!"<<std::endl;
}
