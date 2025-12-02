#include "Game.h"

enum RuleSet {normal, expert};

class Rules{
    public:
        Rules(RuleSet ruleSet) : ruleSet(ruleSet) {}
        bool isValid(const Game&);
        bool gameOver(const Game&);
        bool roundOVer(const Game&);
        const Player& Rules::getNextPlayer(const Game&);
    private:
        RuleSet ruleSet;
};

