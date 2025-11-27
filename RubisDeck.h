#include "Rubis.h"
#include "DeckFactory.h"
#include <vector>

class RubisDeck : public DeckFactory<Rubis>{
    public:
        static RubisDeck& makeRubisDeck();
        void shuffle() override;
        Rubis* getNext() override;
        bool isEmpty() const override;
        static void resetState();//for testing, remove before submission
    private:
        static int top;
        static std::vector<Rubis> deck;
        RubisDeck() {}
};

/* main method for testing
int main(){
    RubisDeck myDeck = RubisDeck::makeRubisDeck();
    myDeck.shuffle();

    cout << myDeck.isEmpty() << endl;
    for (int i =0; i < 7; i++){
        Rubis* myCard = myDeck.getNext();
        cout << *myCard << endl;
    } 
    cout << myDeck.isEmpty() << endl;
}
*/