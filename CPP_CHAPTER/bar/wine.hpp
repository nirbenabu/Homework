#ifndef WINE_HPP
#define WINE_HPP

#include "drink.hpp"

#define MAX_NAME 50

class Wine: public Drink {

private:
    int _year;
    char name_buffer[MAX_NAME]; //

public:
    Wine(char* name, int year): Drink(name), _year(year) { }
    virtual void prepare();
    virtual char* getName();
};

#endif // WINE_HPP
