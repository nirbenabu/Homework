#ifndef DRINK_HPP
#define DRINK_HPP

class Drink {

private:
    char* _name;

public:
    Drink(char* name): _name(name) { }
    virtual char* getName();
    virtual void prepare() = 0;
};

#endif // DRINK_HPP_INCLUDED
