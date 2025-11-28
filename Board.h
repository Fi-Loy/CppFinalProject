// Class requirements
// - must hold an array of strings corresponding to the screen display
// - Cards are held in an array accessed by the enums
// - maybe? the array should be of Card*, not Card objects
// - should be printable with << operator
// - constructor should throw NoMoreCards Exception if there are no more cards to construct a board
#include "Card.h"
#include "CardDeck.h"
#include <stdexcept>
#include <iostream>

enum Letter {A, B, C, D, E};
enum Number {one, two, three, four, five};

class Board{
    friend std::ostream &operator<<(std::ostream&, const Board&);
    public:
        Board();
        bool isFaceUp(const Letter&, const Number&) const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown(const Letter&, const Number&);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void allFacesDown();
        void allFacesUp();
    private:
        void updateDisplay();
        std::string display[21];
        Card* cardsOnTheBoard[5][5];
};