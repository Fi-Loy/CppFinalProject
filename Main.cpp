//TODO:
// - set up expert display mode

#include <iostream>
#include <cstdlib>

#include "Board.h"
#include "Player.h"
#include "Rules.h"

using namespace std;

void gameLoop(){
    int gameMode;
    int displayMode;
    int numPlayers;
    bool validPlayerSelection = false;

    //start of game/set game mode
    cout << "Welcome to Memoarrr!\
            \nWhat game mode would you like to play?\
            \n (1) normal\
            \n (2) expert\
            \n: ";
    cin >> gameMode;
    switch (gameMode){
        case (1):   Rules gameRules(RuleSet(0)); break;
        case (2):   Rules gameRules(RuleSet(1)); break;
    }

    //Set display mode
    cout << "What display mode would you like to use? \
            \n (1) normal\
            \n (2) expert\
            \n: ";
    cin >> displayMode;

    //Set num of players
    cout << "Enter number of players: ";
    while (!validPlayerSelection){
        cin >> numPlayers;
        if (numPlayers < 2 || numPlayers > 4)
            cout << "Invalid number of players, must be between 2 and 4.";
        else
            validPlayerSelection = true;
    }

    //Assign players to game
    Game game;
    for (int i = 0; i < numPlayers; i++){
        string playerName;
        cout << "Enter a player " << i+1 << "'s name: ";
        cin >> playerName;
        game.addPlayer(Player(playerName, Side(i)));
    }
    
    while()
}

int main(){
    gameLoop();
}