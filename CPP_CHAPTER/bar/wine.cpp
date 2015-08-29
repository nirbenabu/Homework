#include "wine.hpp"
#include<iostream>
#include <stdio.h>

void Wine::prepare() {
    std::cout<<"Well, all tou need to do is pour it into a glass and serve."<<std::endl;
}

char* Wine::getName() {
    snprintf(name_buffer, MAX_NAME, "%s (year %d)", Drink::getName(), _year);

    return name_buffer;
}
