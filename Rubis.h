//TODO
// - Make rubis constructor private and friend function of RubisDeck
#include <iostream>
using namespace std;

class Rubis{
    //friend functions
    friend ostream &operator<<(ostream&, const Rubis&);
    public:
        Rubis(int val);
        operator int() const {return value;}
    private:
        int value;
};

Rubis::Rubis(int val){
    //ensure value is between 1 and 4
    if (val > 4)
        value = 4;
    else if (val < 1)
        value = 1;
    else
        value = val;
}

ostream &operator<<(ostream &os, const Rubis &rCard){
    os << rCard.value;
    return os;
}