// Class requirements
// - must hold an array of strings corresponding to the screen display
// - Cards are held in an array accessed by the enums
// - maybe? the array should be of Card*, not Card objects
// - should be printable with << operator
// - constructor should throw NoMoreCards Exception if there are no more cards to construct a board
#pragma once
#include "Card.h"
#include "CardDeck.h"
#include <stdexcept>
#include <iostream>

enum Letter {A, B, C, D, E};
enum Number {one, two, three, four, five};
enum DisplayMode {bNormal, bExpert};

class Board{
    friend std::ostream &operator<<(std::ostream&, const Board&);
    public:
        Board(DisplayMode DisplayMode);
        bool isFaceUp(const Letter&, const Number&) const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown(const Letter&, const Number&);
        Card* getCard(const Letter&, const Number&) const; //recent change, not sure if it will fuck everything up
        void setCard(const Letter&, const Number&, Card*);
        void allFacesDown();
        void allFacesUp();
    private:
        DisplayMode displayMode;
        void updateDisplay();
        bool isValidIndex(const Letter&, const Number&) const;
        std::string display[21];
        Card* cardsOnTheBoard[5][5];
};

//Exception thrown when pulling from empty Deck
class NoMoreCards : public std::out_of_range{
    public:
        NoMoreCards(const std::string& s) : std::out_of_range(s) {}
};

//Exception thrown with trying to acces invalid index
class OutOfRange : public std::out_of_range{
    public:
        OutOfRange(const std::string& s, const Letter& letter, const Number& number) 
            : std::out_of_range(s + ": " + char(int(letter) + 65) + ", " + char(int(number) + 48)) , inValidLetter(letter), inValidNumber(number) {};
        Letter inValidLetter;
        Number inValidNumber;
};