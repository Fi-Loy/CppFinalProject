#include <sstream>
#include <string>
#include <iostream>

#include "Player.h"
#include "RubisDeck.h"
#include "Board.h"

using namespace std;

bool PlayerClassTest(){
    Player player ("David", bottom);
    RubisDeck playersDeck = RubisDeck::makeRubisDeck();
    player.addRubis(*(playersDeck.getNext()));
    player.addRubis(*(playersDeck.getNext()));

    bool t1 = "David" == player.getName(); // David
    bool t2 = 0 == player.isActive(); // 0
    player.setActive(true); 
    bool t3 = 1 == player.isActive(); // 1
    bool t4 = 7 == player.getNRubis(); // 7
    bool t5 = 1 == player.getSide(); // bottom
    player.setSide(top);
    bool t6 = 0 == player.getSide(); // top
    stringstream activeOutput;
    activeOutput << player;
    bool t7 = 0 == activeOutput.str().compare("David: 0 (active)");
    player.setDisplayMode(true);
    stringstream inactiveOutput;
    inactiveOutput << player;
    bool t8 = 0 == inactiveOutput.str().compare("David: 7 rubis");

    playersDeck.resetState();

    return t1 && t2 && t3 && t4 && t5 && t6 && t7 && t8;
}

bool RubisDeckTest(){
    RubisDeck myDeck = RubisDeck::makeRubisDeck();

    bool t1 = 0 == myDeck.isEmpty();

    int values[] = {4,3,2,2,1,1,1};
    bool t2 = true;

    for (int i = 0; i < 7; i++){
        Rubis* myCard = myDeck.getNext();
        t2 &= values[i] == *myCard; 
        //cout << "array val: " << values[i] << " Rubis val: " << int(*myCard) << endl;
    } 
    bool t3 = 1 == myDeck.isEmpty();

    //cout << "test1: " << t1 << endl;
    //cout << "test2: " << t2 << endl;
    //cout << "test3: " << t3 << endl;
    //cout << "True: " << true << endl;

    return t1 && t2 && t3;
}

bool BoardTest(){
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
    return true;
}


int main(){
    cout << "PlayerClassTest: " << PlayerClassTest() << endl;
    cout << "RubisDeckTest: " << RubisDeckTest() << endl;
    BoardTest();
}