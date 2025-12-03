#include "Card.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Card &card){
    char face = card.enumMap(card.face);
    char back = card.enumMap(card.background);
    const char t[] = {back, back, back, '\0'};
    const char m[] = {back, face, back, '\0'};
    const char b[] = {back, back, back, '\0'};
    os << t << "\n"
        << m << '\n'
        << b << "\n";
    return os;
}

//Get the first letter of an enum as a char
char Card::enumMap(FaceBackground back) const{
    switch(back){
        case Red:       return 'R';
        case Green:     return 'G';
        case Purple:    return 'P';
        case Blue:      return 'B';
        case Yellow:    return 'Y';
        default:        return 'Z';
    }
}
//Get the first letter of an enum as a char
char Card::enumMap (FaceAnimal face) const{
    switch (face){
        case Crab:      return 'C';
        case Penguin:   return 'P';
        case Octopus:   return 'O';
        case Turtle:    return 'T';
        case Walrus:    return 'W';
        default:        return 'Z';   
    }
}

//Return the appropriate char array depending on row number
//and flipped status.
std::string Card::getRow(int i){
    char CardFace = enumMap(face);
    char CardBack = enumMap(background);
    
    if (faceUp == false)
        return {'z', 'z', 'z'};
    else if ( i % 2 == 1)
        return {CardBack, CardFace, CardBack};
    else
        return {CardBack, CardBack, CardBack};

}

bool Card::match(const Card& card) const{
    return this->face == card.face || this->background == card.background;
}
bool Card::match(const Card* card) const{
    return this->face == card->face || this->background == card->background;
}
