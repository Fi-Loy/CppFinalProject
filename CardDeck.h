#pragma once
#include "DeckFactory.h"
#include "Card.h"
#include <vector>

class CardDeck : public DeckFactory<Card>{
    public:
        static CardDeck& makeCardDeck();
        void shuffle() override;
        Card* getNext() override;
        bool isEmpty() const override;
        static void resetState();//for testing, remove before submission
    private:
        CardDeck() {}
        static int top;
        //static Card deck[25];
        static std::vector<Card> deck;
        static std::vector<Card> makeDeck();
        
};