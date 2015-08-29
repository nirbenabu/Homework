#ifndef BEER_HPP_INCLUDED
#define BEER_HPP_INCLUDED

#include "drink.hpp"

class Beer: public Drink {

public:
    Beer(char* name): Drink(name) { }
    virtual void prepare();
};

#endif // BEER_HPP_INCLUDED
