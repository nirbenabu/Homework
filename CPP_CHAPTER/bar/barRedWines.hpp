#ifndef BARREDWINES_HPP_INCLUDED
#define BARREDWINES_HPP_INCLUDED

#include "RedWine.hpp"

class Chianti: public RedWine {
    public:
        Chianti(int year): RedWine("Chianti", year) { }
};

class YardenHermonRed: public RedWine {
    public:
        YardenHermonRed(int year): RedWine("Yarden Har Hermon Red", year) { }
};

class YardenCabernetSauvignon: public RedWine {
    public:
        YardenCabernetSauvignon(int year): RedWine("Yarden Cabernet Sauvignon", year) { }
};

class ChadeauMargot: public RedWine {
    public:
        ChadeauMargot(int year): RedWine("Chadeau Margot", year) { }
};

#endif // BARREDWINES_HPP_INCLUDED
