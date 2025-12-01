#include "Player.h"
#include "Board.h"

class Game{
    friend std::ostream &operator<<(std::ostream&, const Game&);
    public:
        Game() {};
        int getRound();
        void addPlayer(const Player&);
        Player& getPlayer(Side);
        const Card* getPreviousCard();
        const Card* getCurrentCard();
        void setCurrentCard(const Card*);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
    private:
        Board gameBoard;
        int round = 0;
        Player players[4] = {Player("empty", Side::top),Player("empty", Side::bottom),Player("empty", Side::left),Player("empty", Side::right)};
        Card* previousCard;
        Card* currentCard;
};

class OccupiedIndexError : public std::logic_error{
    public:
        OccupiedIndexError(const std::string& s) : std::logic_error(s) {}
};