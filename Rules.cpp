#include "Rules.h"

bool Rules::gameOver(const Game& game){
    return game.getRound()  > 6;
}