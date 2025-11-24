// TODO
// "The method has to always reutrn the same 
//  CardDeck during the execution of the program"
//  ^clarify with the TA what this means exactly
#include "DeckFactory.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

class CardDeck : public DeckFactory<Card>{
    public:
        static CardDeck& makeCardDeck();
        void shuffle() override;
        Card* getNext() override;
        bool isEmpty() const override;
    private:
        CardDeck() {}
        static int top;
        //static Card deck[25];
        static vector<Card> deck;
        static vector<Card> makeDeck();
        
};

//Initializing static members
int CardDeck::top = 25;
//Card CardDeck::deck[25];
vector<Card> CardDeck::deck = CardDeck::makeDeck();

//Static method for inilizining the static deck
vector<Card> CardDeck::makeDeck(){
    vector<Card> deck;
    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            //deck[(i*5)+j] = Card(FaceAnimal(i), FaceBackground(j));
            deck.push_back(Card(FaceAnimal(i), FaceBackground(j)));
        }
    }
    return deck;
}

//Returns a reference to a CardDeck
//Singleton for acces to the CardDeck
//interface.
CardDeck& CardDeck::makeCardDeck(){
    static CardDeck singleton;
    return singleton;
}

//Shuffles the deck of cards in a 
//random order
void CardDeck::shuffle(){
    //TODO
    random_device rd;
    mt19937 g(rd());

    std::shuffle(deck.begin(),deck.end(),g);
}

//Returns the card pointed to by the 
//top of the deck
Card* CardDeck::getNext(){
    if (top > 0){
        Card* rCard = &deck[top-1];
        top--;
        return  rCard;  
    }
    else
        return nullptr;
    
}

//Returns True if the deck is empty
//and there are no mare cards to be
//returned.
bool CardDeck::isEmpty() const{
    //TODO: check if this actually works
    return top > 0 ? false : true;
}

int main(){
    CardDeck myDeck = CardDeck::makeCardDeck();
    myDeck.shuffle();
    Card *myCard = myDeck.getNext();
    myCard->flipFace();
    cout << *myCard;
}





