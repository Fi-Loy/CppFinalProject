//TODO:
// - set up expert display mode                                            

#include <iostream>
#include <cstdlib>
#include <limits>

#include "Board.h"
#include "Player.h"
#include "Rules.h"
#include "RubisDeck.h"

using namespace std;

//Helper functions
//Function for displaying the cards the players are allowed to peak
//at the start of the game
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

    cout << "The 3 cards in front of you:\n";
    game.gameBoard.allFacesUp();
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << (*cardsForPeek[j]).getRow(i) << " ";
        }
        cout << endl;
    }
    cout << static_cast<char>(lIndeices[0] + 65) << rIndecies[0] + 1 << "  "
         << static_cast<char>(lIndeices[1] + 65) << rIndecies[1] + 1 << "  "
         << static_cast<char>(lIndeices[2] + 65) << rIndecies[2] + 1 << "  ";
    game.gameBoard.allFacesDown();
}

Card* validateCardSelection(Game& game){

    bool validSelection = false;
    int number;
    char letter;

    while(!validSelection){
        cout << "Enter a location: ";
        cin >> letter;
        cin >> number;

        letter = tolower(letter) - 'a';
        number--;

        try{
            Card* selection = game.gameBoard.getCard(Letter(letter), Number(number));
            if (selection->isFaceUp())
                cout << "Card is already face up!" << endl;
            else
                validSelection = true;
                game.gameBoard.turnFaceUp(Letter(letter), Number(number));
                return selection;
        } catch (OutOfRange){
            cout << "Invalid Selection." << endl;
        } 
    }
    
}

void gameLoop(){
    int gameMode;
    int displayMode;
    int numPlayers;
    bool validPlayerSelection = false;

    Rules* gameRules;
    RubisDeck gameRubisDeck = RubisDeck::makeRubisDeck();
    gameRubisDeck.shuffle();

    //start of game/set game mode
    cout << "Welcome to Memoarrr!\
            \nWhat game mode would you like to play?\
            \n (1) normal\
            \n (2) expert (not implemented)\
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

    //set all cards face down and set all players to active
    game.gameBoard.allFacesDown();
    for (int i = 0; i < numPlayers; i++){
        Player curPlayer = game.getPlayer(Side(i));
        if (game.getPlayer(Side(i)).getName().compare("empty") != 0)
           game.getPlayer(Side(i)).setActive(true); 
    }

    //initial card reveal
    system("clear"); //For Grader: switch to system("cls") if using a Windows machine
    cout << game << endl;
    cout << "The game will begin by each player seeing the 3\
             \ncenter cards on their side of the table. Be sure\
             \nto remember these cards!" << endl;
    
    cin.get(); //empty out cin  
    system("clear"); //For Grader: switch to system("cls") if using a Windows machine
    
    for(int i = 0; i < numPlayers; i++){
        cout << "\nPlayer " << i+1 << ", ensure no one else can see your cards.\
                 \nWhen you are ready to see your cards, hit any key." << endl;
        //pressEnterToContinue();
        cin.get();
        cardPeek(game.getPlayer(Side(i)), game);
        cout << endl << "When you have commited these to memory. Hit any key to clear the cards and  pass it to the\
                        \nnext player." << endl;
        cin.get();
        system("clear"); //For Grader: switch to system("cls") if using a Windows machine
    }
    
    //main game loop
    int activeInt = 0;
    while(!(gameRules->gameOver(game))){
        //Round Loop
        system("clear"); //For Grader: switch to system("cls") if using a Windows machine
        while(!gameRules->roundOver(game)){
            cout << "Round " << game.getRound()+1 << endl;
            cout << game;
            while(!gameRules->roundOver(game)){
                Player& targetPlayer = game.getPlayer(Side(activeInt));
                if(targetPlayer.isActive() && (targetPlayer.getName().compare("empty") != 0)){
                    cout << "Player " << activeInt + 1 << ": Select a card to flip up:" << endl;
                    game.setCurrentCard(validateCardSelection(game));
                    if(!gameRules->isValid(game)){
                        cout << "Selection does not match with the previous card!\
                                 \nYou are out of the round!" << endl;
                        targetPlayer.setActive(false);
                    }
                    system("clear"); //For Grader: switch to system("cls") if using a Windows machine
                    cout << "Round " << game.getRound()+1 << endl;
                    cout << game << endl;
                }
                if(!gameRules->roundOver(game))
                    activeInt = (activeInt + 1) % 4;
            }
        }
        cout << "Round Over!" << endl;
        game.setCurrentCard(nullptr);
        game.incrementRound();

        //Find round winner
        Player* roundWinner;
        for (int i = 0; i < 4; i++){
            Player& targetPlayer = game.getPlayer(Side(i));
            if (targetPlayer.isActive() && (targetPlayer.getName().compare("empty") != 0))
                roundWinner = &targetPlayer;
        }
        Rubis* roundPrize = gameRubisDeck.getNext();
        roundWinner->addRubis(*roundPrize);
        
        cout << "Player " << int(roundWinner->getSide())+1 <<" has been awarded " << *roundPrize << " Rubis!" << endl;
        if(game.getRound() < 7){
            cout << "All cards will now be flipped down and the next round will start." << endl << endl;
        }  

        game.gameBoard.allFacesDown();
        for (int i = 0; i < 4; i++){
            Player& targetPlayer = game.getPlayer(Side(i));
            if (targetPlayer.getName().compare("empty") != 0)
                targetPlayer.setActive(true);
        }

        cin.get();
        cin.get();
    }

    //print all players and declare the winner
    cout << "Game Over!" << endl;
    int winIndex = 0;
     for (int i = 0; i < 4; i++){
        Player& targetPlayer = game.getPlayer(Side(i));
        if (targetPlayer.getName().compare("empty") != 0){
            targetPlayer.setDisplayMode(true);
            if(targetPlayer.getNRubis() > game.getPlayer(Side(winIndex)).getNRubis())
                winIndex = i;
            cout << targetPlayer << endl;
        }
    }

    cout << endl << "Player " << winIndex + 1 << " is the winner with " << game.getPlayer(Side(winIndex)).getNRubis() << " Rubis!" << endl;
    exit(0);
}

int main(){
    gameLoop();
}