//TODO
// - (DONE) Make the constructor private and a friend function
//   of the CardDeck class
// - (DONE) Conversion operator to type FaceAnimal
// - (DONE) Conversion operator to type FaceBackground

#include <iostream>
#pragma once

enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
enum FaceBackground {Red, Green, Purple, Blue, Yellow};

class Card{
    friend std::ostream &operator<<(std::ostream&, const Card&);
    friend class CardDeck;
    public:
        int getNRows() const {return rows;} 
        std::string getRow(int);
        bool flipFace() { return faceUp = faceUp ? false : true;}
        operator FaceAnimal() const {return face;}
        operator FaceBackground() const {return background;}
        char enumMap(FaceAnimal) const;
    private:
        FaceAnimal face;
        FaceBackground background;
        int rows = 3;
        bool faceUp = false;
        Card(FaceAnimal animal, FaceBackground background) //TODO: make constructor private and a friend function of CardDeck
            : face(animal), background(background) {}  
        Card()
            : face(FaceAnimal::Crab), background(FaceBackground::Blue) {}      
        char enumMap(FaceBackground) const;
};