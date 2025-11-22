//TODO
// - Make the constructor private and a friend function
//   of the CardDeck class
// - (DONE) Conversion operator to type FaceAnimal
// - (DONE) Conversion operator to type FaceBackground

#include <iostream>
using namespace std;

enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
enum FaceBackground {Red, Green, Purple, Blue, Yellow};

class Card{
    friend ostream &operator<<(ostream&, const Card&);
    public:
        Card(FaceAnimal animal, FaceBackground background) //TODO: make constructor private and a friend function of CardDeck
            : face(animal), background(background) {}
        int getNRows() const {return rows;} 
        string getRow(int);
        bool flipFace() { return faceUp = faceUp ? false : true;}
        operator FaceAnimal() const {return face;}
        operator FaceBackground() const {return background;}
        char enumMap(FaceAnimal) const;
    private:
        FaceAnimal face;
        FaceBackground background;
        int rows = 3;
        bool faceUp = false;
        
        char enumMap(FaceBackground) const;
};

ostream &operator<<(ostream &os, const Card &card){
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
string Card::getRow(int i){
    char CardFace = enumMap(face);
    char CardBack = enumMap(background);
    
    if (faceUp == false)
        return {'z', 'z', 'z'};
    else if ( i % 2 == 1)
        return {CardBack, CardFace, CardBack};
    else
        return {CardBack, CardBack, CardBack};

}