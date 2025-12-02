//TODO - Talk to TA about OutOfRange exception, and if thats built in or one we have to make.

#include "Board.h"

//Updates the board display. To be called after every
//change to board state
void Board::updateDisplay() {
    char letter[] = {'A', 'B', 'C', 'D', 'E'};
    int ldex = 0;
    for(int i = 0; i < 20; i++){
        std::string line;
        if(i % 4 == 3){//space between cards
            line = '\n';
        }
        else{//cards
            if(i % 4 == 1){//adding letters to the right
                line += letter[ldex++];
                line += '\t';
            }
            else
                line += '\t';
            for (int j = 0; j < 5; j++){
            if ((i == 9 || i == 10 || i == 8) && j == 2)
                line += "     ";
            else
                line += cardsOnTheBoard[i/4][j]->getRow(i) += "  ";
        }
        }
        display[i] = line;
    }
    display[20] = "\t 1    2    3    4    5";
}

//Board output operator overload
std::ostream &operator<<(std::ostream& os, const Board& board){
    for(int i = 0; i < 21; i++){
        os << board.display[i] << std::endl;
    }
    return os;
}

//Helper function for easily changing acceptable indices
bool Board::isValidIndex(const Letter& letter, const Number& number) const{
    bool isValid = int(letter) < 0; 
    isValid |= int(letter) > 4;
    isValid |= int(number) < 0;
    isValid |= int(number) > 4;
    isValid |= (int(letter) == 2 && int(number) == 2);

    return !isValid;
}

//Sets all cards on the board face down
void Board::allFacesDown(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cardsOnTheBoard[i][j]->setFaceUp(false);
        }
    }
    this->updateDisplay();
}

//Sets all cards on the board face up
void Board::allFacesUp(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cardsOnTheBoard[i][j]->setFaceUp(true);
        }
    }
    this->updateDisplay();
}

//Sets the card on the board at the given location to the card argument passed
// - Throws OutOfBounds
void Board::setCard(const Letter& letter, const Number& number, Card* pCard){
    if(!isValidIndex(letter, number))
        throw OutOfRange("Invalid board indices", letter, number); //done know if we have to make this or if its supposed to be out_of_range
    cardsOnTheBoard[int(letter)][int(number)] = pCard;
    this->updateDisplay();
}

//Returns the card found at the given location
// - Throws OutOfBounds
Card* Board::getCard(const Letter& letter, const Number& number) const{
    if(!isValidIndex(letter, number))
        throw OutOfRange("Invalid board indices", letter, number); //done know if we have to make this or if its supposed to be out_of_range
    return cardsOnTheBoard[int(letter)][int(number)];
}

//Sets the card at the given location to face down
// - Throws OutOfBounds
bool Board::turnFaceDown(const Letter& letter, const Number& number){
    if(!isValidIndex(letter, number))
        throw OutOfRange("Invalid board indices", letter, number); //done know if we have to make this or if its supposed to be out_of_range
    bool rBool = cardsOnTheBoard[int(letter)][int(number)]->setFaceUp(false);
    this->updateDisplay();
    return rBool;
}

//Sets the card at the given location to face up
// - Throws OutOfBounds
bool Board::turnFaceUp(const Letter& letter, const Number& number){
    if(!isValidIndex(letter, number))
        throw OutOfRange("Invalid board indices", letter, number); //done know if we have to make this or if its supposed to be out_of_range
    bool rBool = cardsOnTheBoard[int(letter)][int(number)]->setFaceUp(true);
    this->updateDisplay();
    return rBool;
    
}

//Returns whether or not the card at the given location is face up
// - Throws OutOfBounds 
bool Board::isFaceUp(const Letter& letter, const Number& number) const{
    if(!isValidIndex(letter, number))
        throw OutOfRange("Invalid board indices", letter, number); //done know if we have to make this or if its supposed to be out_of_range
    return cardsOnTheBoard[int(letter)][int(number)]->isFaceUp();
}


//Board constructor
// - Throws NoMoreCards
Board::Board() {
    CardDeck boardsDeck = CardDeck::makeCardDeck();
    CardDeck::resetState();

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Card* card = boardsDeck.getNext();
            try{
                if(card == nullptr)
                    throw NoMoreCards("Deck has no more cards.");
                else
                    cardsOnTheBoard[i][j] = card;
            } catch (NoMoreCards){
                CardDeck::resetState();
            }
            
        }
    }
    this->updateDisplay();

}

/* class testing artifact
int main(){
    Board myBoard;
    myBoard.allFacesUp();
    std::cout << myBoard;
    myBoard.allFacesDown();
    std::cout << myBoard;
    std::cout << "Is card at (1,1) flipped?: " << myBoard.isFaceUp(Letter(1),Number(1)) << std::endl;//0
    myBoard.turnFaceUp(Letter(1),Number(1));
    std::cout << "Is card at (1,1) flipped?: " << myBoard.isFaceUp(Letter(1),Number(1)) << std::endl;//1
    myBoard.turnFaceUp(Letter(4),Number(4));
    std::cout << myBoard;
    Card* temp = myBoard.getCard(Letter(1),Number(1));
    myBoard.setCard(Letter(1),Number(1),myBoard.getCard(Letter(4),Number(4)));
    myBoard.setCard(Letter(4),Number(4), temp);
    std::cout << myBoard;

}
*/