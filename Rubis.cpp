#include "Rubis.h"
#include <iostream>
using namespace std;

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