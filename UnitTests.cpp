#include <sstream>
#include <string>
#include <iostream>

#include "Player.h"
#include "RubisDeck.h"
#include "Board.h"
#include "Game.h"

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

bool GameClassTest(){
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
    stringstream inactiveGameOutput;
    inactiveGameOutput << myGame;

    myGame.getPlayer(Side(0)).setActive(true);
    myGame.getPlayer(Side(1)).setActive(true);
    myGame.getPlayer(Side(2)).setActive(true);
    myGame.getPlayer(Side(3)).setActive(true);

    stringstream activeGameOutput;
    inactiveGameOutput << myGame;

    bool t1 = inactiveGameOutput.str().compare(
        
"        zzz  zzz  zzz  zzz  zzz  "
"A       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
""
"        zzz  zzz  zzz  zzz  zzz  "
"B       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
""
"        zzz  zzz       zzz  zzz  "
"C       zzz  zzz       zzz  zzz  "
"        zzz  zzz       zzz  zzz  "
""
""
"        zzz  zzz  zzz  zzz  zzz  "
"D       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
""
"        zzz  zzz  zzz  zzz  zzz  "
"E       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
"         1    2    3    4    5"
"David: 0 (inactive)"
"Mack: 1 (inactive)"
"Daniel: 2 (inactive)"
"Zach: 3 (inactive)");
bool t2 = activeGameOutput.str().compare(
        
"        zzz  zzz  zzz  zzz  zzz  "
"A       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
""
"        zzz  zzz  zzz  zzz  zzz  "
"B       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
""
"        zzz  zzz       zzz  zzz  "
"C       zzz  zzz       zzz  zzz  "
"        zzz  zzz       zzz  zzz  "
""
""
"        zzz  zzz  zzz  zzz  zzz  "
"D       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
""
"        zzz  zzz  zzz  zzz  zzz  "
"E       zzz  zzz  zzz  zzz  zzz  "
"        zzz  zzz  zzz  zzz  zzz  "
""
"         1    2    3    4    5"
"David: 0 (active)"
"Mack: 1 (active)"
"Daniel: 2 (active)"
"Zach: 3 (active)");

    return t1 && t2;
}


int main(){
    cout << "PlayerClassTest: " << PlayerClassTest() << endl;
    cout << "RubisDeckTest: " << RubisDeckTest() << endl;
    cout << "GameClassTest: " << GameClassTest() << endl;
    BoardTest();
}