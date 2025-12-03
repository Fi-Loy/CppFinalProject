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
        bool setFaceUp(bool val) { return faceUp = val;}
        bool isFaceUp() const {return faceUp;}
        operator FaceAnimal() const {return face;}
        operator FaceBackground() const {return background;}
        char enumMap(FaceAnimal) const;
        bool match(const Card&) const;
        bool match(const Card*) const;
    private:
        FaceAnimal face;
        FaceBackground background;
        int rows = 3;
        bool faceUp = false;
        Card(FaceAnimal animal, FaceBackground background) 
            : face(animal), background(background) {}  
        Card()
            : face(FaceAnimal::Crab), background(FaceBackground::Blue) {}      
        char enumMap(FaceBackground) const;
};