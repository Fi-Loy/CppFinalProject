// TODO
// "The method has to always reutrn the same 
//  CardDeck during the execution of the program"
//  ^clarify with the TA what this means exactly
#include <DeckFactory.h>
#include <Card.h>
#include <random>
#include <algorithm>
using namespace std;

class CardDeck : public DeckFactory<Card>{
    public:
        static CardDeck& makeCardDeck();
        void shuffle() override;
        Card* getNext() override;
        bool isEmpty() const override;
    private:
        CardDeck();
        int top = 0;
        Card deck[25];
};

//Randomizes the positions of cards within the deck
//array
void CardDeck::shuffle(){
    random_device rd;
    mt19937 g(rd());

    std::shuffle(deck[0], deck[25], g);
}

