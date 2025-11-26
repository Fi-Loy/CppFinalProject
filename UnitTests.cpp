#include <sstream>
#include <string>
#include <iostream>

#include "Player.h"
#include "RubisDeck.h"

using namespace std;

bool PlayerClassTest(){
    Player player ("David", bottom);
    player.addRubis(Rubis(4));

    bool t1 = "David" == player.getName(); // David
    bool t2 = 0 == player.isActive(); // 0
    player.setActive(true); 
    bool t3 = 1 == player.isActive(); // 1
    bool t4 = 4 == player.getNRubis(); // 4
    bool t5 = 1 == player.getSide(); // bottom
    player.setSide(top);
    bool t6 = 0 == player.getSide(); // top
    stringstream activeOutput;
    activeOutput << player;
    bool t7 = 0 == activeOutput.str().compare("David: 0 (active)");
    player.setDisplayMode(true);
    stringstream inactiveOutput;
    inactiveOutput << player;
    bool t8 = 0 == inactiveOutput.str().compare("David: 4 rubis");

    return t1 && t2 && t3 && t4 && t5 && t6 && t7 && t8;
}

bool RubisDeckTest(){
    RubisDeck myDeck = RubisDeck::makeRubisDeck();

    bool t1 = 0 == myDeck.isEmpty();

    int values[] = {1,1,1,2,2,3,4};
    bool t2 = true;

    for (int i = 0; i < 7; i++){
        Rubis* myCard = myDeck.getNext();
        t2 &= values[i] == *myCard; 
    } 
    bool t3 = 1 == myDeck.isEmpty();

    cout << t1 << "test1" << endl;
    cout << t2 << "test2" << endl;
    cout << t3 << "test3" << endl;
    cout << "True: " << true << endl;

    return t1 && t2 && t3;
}

int main(){
    cout << "PlayerClassTest: " << PlayerClassTest() << endl;
    cout << "RubisDeckTest: " << RubisDeckTest() << endl;
}