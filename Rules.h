#include "Game.h"

enum RuleSet {normal, expert};

class Rules{
    public:
        Rules(RuleSet ruleSet) : ruleSet(ruleSet) {}
        bool isValid(const Game&);
        bool gameOver(const Game&);
        bool roundOver(const Game&);
        const Player& getNextPlayer(const Game&);
    private:
        RuleSet ruleSet;
};

