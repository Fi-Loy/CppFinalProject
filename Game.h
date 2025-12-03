#include "Player.h"
#include "Board.h"

class Game{
    friend std::ostream &operator<<(std::ostream&, const Game&);
    public:
        Game() {};
        int getRound() const;
        void addPlayer(const Player&);
        Player& getPlayer(Side) const;
        const Card* getPreviousCard() const;
        const Card* getCurrentCard() const;
        void setCurrentCard(const Card*);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void incrementRound() {round++;}

        Board gameBoard;
    private:
        int displayMode;
        int round = 0;
        // ^ use of mutable is potentially sketchy
        mutable Player players[4] = {Player("empty", Side::top),Player("empty", Side::bottom),Player("empty", Side::left),Player("empty", Side::right)};
        mutable const Card* previousCard = nullptr;
        mutable const Card* currentCard = nullptr;
};

class OccupiedIndexError : public std::logic_error{
    public:
        OccupiedIndexError(const std::string& s) : std::logic_error(s) {}
};
