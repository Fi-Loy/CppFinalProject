//TODO:
// - set up expert display mode                                            

#include <iostream>
#include <cstdlib>

#include "Board.h"
#include "Player.h"
#include "Rules.h"

using namespace std;

//Helper functions
void cardPeek(const Player& player, Game& game){
    int indices1[] = {0,0,0};
    int indices2[] = {4,4,4};
    int indices3[] = {1,2,3};

    int* lIndeices;
    int* rIndecies;

    Card* cardsForPeek[3];

    switch (int(player.getSide())){
        case (0):   lIndeices = indices1;
                    rIndecies = indices3;
                    break;
        case (1):   lIndeices = indices3;
                    rIndecies = indices2;
                    break;
        case (2):   lIndeices = indices2;
                    rIndecies = indices3;
                    break;
        case (3):   lIndeices = indices3;
                    rIndecies = indices1;
                    break;
    }

    for(int i = 0; i < 3; i ++){
        cardsForPeek[i] = game.gameBoard.getCard(Letter(lIndeices[i]), Number(rIndecies[i]));
    }

    cout << "The 3 cards in front of you:";
    game.gameBoard.allFacesUp();
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << (*cardsForPeek[j]).getRow(i) << " ";
        }
        cout << endl;
    }
    
}

void gameLoop(){
    int gameMode;
    int displayMode;
    int numPlayers;
    bool validPlayerSelection = false;

    Rules* gameRules;

    //start of game/set game mode
    cout << "Welcome to Memoarrr!\
            \nWhat game mode would you like to play?\
            \n (1) normal\
            \n (2) expert\
            \n: ";
    cin >> gameMode;
    switch (gameMode){
        case (1):   gameRules = new Rules(RuleSet(0)); break;
        case (2):   gameRules = new Rules(RuleSet(1)); break;
    }

    //Set display mode 
    //Does nothing atm
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
        
        bool validPlayerName = false;
        while (!validPlayerName){
            cout << "Enter player " << i+1 << "'s name: ";
            if(!playerName.compare("empty"))
                cout << "Invalid player name.";
            else{
                cin >> playerName;
                validPlayerName = true;
            }
        }
        game.addPlayer(Player(playerName, Side(i)));
    }
    
    //main game loop
    while(!(gameRules->gameOver(game))){

        //set all cards face down and set all players to active
        game.gameBoard.allFacesDown();
        for (int i = 0; i < numPlayers; i++){
            Player curPlayer = game.getPlayer(Side(i));
            if (game.getPlayer(Side(i)).getName().compare("empty") != 0)
               game.getPlayer(Side(i)).setActive(true); 
        }

        //initial card reveal
        system("clear"); //For Grader: switch to system("cls") if using a Windows machine
        cout << game.gameBoard << endl;
        cout << "The game will begin by each player seeing the 3\
                 \ncenter cards on their side of the table. Be sure\
                 \nto remember these cards!" << endl;
        
        for(int i = 0; i < numPlayers; i++){
            cout << "Player " << i+1 << ", ensure no one else can see your cards.\
                     \nWhen you are ready to see your cards, press any key: ";
            cin.get();
            cardPeek(game.getPlayer(Side(numPlayers)), game);
        }
    }
}

int main(){
    gameLoop();
}