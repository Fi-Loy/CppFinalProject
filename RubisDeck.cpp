#include "RubisDeck.h"

#include <algorithm>
#include <random>
using namespace std;

int RubisDeck::top = 7;
vector<Rubis> RubisDeck::deck = {Rubis(1), Rubis(1), Rubis(1), Rubis(2), Rubis(2), Rubis(3), Rubis(4)};

RubisDeck& RubisDeck::makeRubisDeck(){
    static RubisDeck singleton;
    return singleton;
}

void RubisDeck::shuffle(){
    random_device rd;
    mt19937 g(rd());

    std::shuffle(deck.begin(),deck.end(),g);
}

Rubis* RubisDeck::getNext(){
    if (top > 0){
        Rubis* rCard = &deck[top-1];
        top--;
        return rCard;
    }
    else
        return nullptr;
}

bool RubisDeck::isEmpty() const{
    return top > 0 ? false : true;
}