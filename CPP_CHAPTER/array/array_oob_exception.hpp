#ifndef ARRAY_OOB_EXCEPTION_HPP
#define ARRAY_OOB_EXCEPTION_HPP

#include "array_exception.hpp"

class ArrayOutOfBoundsException: public ArrayException {
    private:
        int _iBounds, _iIndex;
    public:
        ArrayOutOfBoundsException(int size, int index): ArrayException("Out of bounds array exception!"), _iBounds(size), _iIndex(index) { }
        virtual void printInfo();
};

#endif // ARRAY_OOB_EXCEPTION_HPP
