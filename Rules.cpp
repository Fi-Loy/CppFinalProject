#include "Rules.h"

bool Rules::isValid(const Game& game){
    bool m1 = false;
    bool m2 = false;
    if (game.getPreviousCard() == nullptr)
        return true;
    else{
        return game.getCurrentCard()->match(game.getPreviousCard());
    }
}

bool Rules::gameOver(const Game& game){
    return game.getRound()  > 6;
}

bool Rules::roundOver(const Game& game){
    int activePlayers = 0;
    for (int i = 0; i < 4; i++){
        if (game.getPlayer(Side(i)).isActive())
            activePlayers++;
    }
    return activePlayers < 2;
}