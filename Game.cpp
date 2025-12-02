//NOTES
// - setCurrentCard() always sets the previous card to the 
//   current card before changing the current card. this may
//   not be how it is supposed to behave during a game.

//TODO
// - (DONE) replace cout in addPlayer with proper exception throw

#include "Game.h"

//Output operator for the game object
std::ostream &operator<<(std::ostream& os, const Game& game){
    os << game.gameBoard;
    for(int i = 0; i < 4; i++){
        if (game.players[i].getName() != "empty")
            os << game.players[i] << std::endl;
    }
    return os;
}

//Returns current round
int Game::getRound() const{
    return round;
}

//Adds player to the game
void Game::addPlayer(const Player& player){
    if(players[player.getSide()].getName() != "empty")
        throw OccupiedIndexError("Side of board already occupied");
    else
        players[int(player.getSide())] = player;
    
}

//Returns the player at the given side of the board
Player& Game::getPlayer(Side side){
    return players[int(side)];
}

//Returns the previous card
const Card* Game::getPreviousCard(){
    return previousCard;
}

//Returns the current card
const Card* Game::getCurrentCard(){
    return currentCard;
}

//Sets the current card;
void Game::setCurrentCard(const Card* curCard){
    *previousCard = *currentCard; // <- NOTE: this may not be how the game works, make sure to review this
    *currentCard = *curCard;
}

//Gets a card from the board
Card* Game::getCard(const Letter& letter, const Number& number){
    return gameBoard.getCard(letter, number);
}

//Sets a card on the board
void Game::setCard(const Letter& letter, const Number& number, Card* card){
    gameBoard.setCard(letter, number, card);
}

/* testing artifact
int main(){
    Game myGame;
    Player david("David", Side::top);
    myGame.addPlayer(david);
    Player daniel("Daniel", Side::top);
    try{
        myGame.addPlayer(daniel);
    }catch(OccupiedIndexError){
        daniel.setSide(Side::left);
        myGame.addPlayer(daniel);
    } 
    Player zach("Zach",Side::right);
    myGame.addPlayer(zach);
    Player mack("Mack", Side::bottom);
    myGame.addPlayer(mack);
    std::cout << myGame;

    myGame.getPlayer(Side(0)).setActive(true);
    myGame.getPlayer(Side(1)).setActive(true);
    myGame.getPlayer(Side(2)).setActive(true);
    myGame.getPlayer(Side(3)).setActive(true);

    std::cout << myGame;
}
    */