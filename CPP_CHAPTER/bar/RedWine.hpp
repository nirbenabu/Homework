#ifndef REDWINE_HPP_INCLUDED
#define REDWINE_HPP_INCLUDED

#include "wine.hpp"

class RedWine: public Wine {
    public:
        RedWine(char* name, int year): Wine(name, year) { }
        virtual void prepare();
};

#endif // REDWINE_HPP_INCLUDED
