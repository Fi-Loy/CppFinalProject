//TODO
// - Make rubis constructor private and friend function of RubisDeck
#pragma once
#include <iostream>

class Rubis{
    //friend functions
    friend std::ostream &operator<<(std::ostream&, const Rubis&);
    public:
        Rubis(int val);
        operator int() const {return value;}
    private:
        int value;
};