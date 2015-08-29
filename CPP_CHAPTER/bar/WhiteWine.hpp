#ifndef WHITEWINE_HPP_INCLUDED
#define WHITEWINE_HPP_INCLUDED

#include "wine.hpp"

class WhiteWine: public Wine {
    public:
        WhiteWine(char* name, int year): Wine(name, year) { }
        virtual void prepare();
};

#endif // WHITEWINE_HPP_INCLUDED
