#ifndef BARWHITEWINES_HPP_INCLUDED
#define BARWHITEWINES_HPP_INCLUDED

#include "WhiteWine.hpp"

class CarmelEmeraldRiesling: public WhiteWine {
    public:
        CarmelEmeraldRiesling(int year): WhiteWine("Carmel Emerald Riesling", year) { }
};

class GolanSmadar: public WhiteWine {
    public:
        GolanSmadar(int year): WhiteWine("Golan Smadar", year) { }
};

class YardenSherdona: public WhiteWine {
    public:
        YardenSherdona(int year): WhiteWine("Yarden Sherdona", year) { }
};

#endif // BARWHITEWINES_HPP_INCLUDED
