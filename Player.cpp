#include <iostream>
#include "Rubis.h"

enum Side {top, bottom, left, right};

class Player{
    friend ostream &operator<<(ostream&, const Player&);
    public:
        Player(string name, Side side);
        string getName() const;
        void setActive(bool);
        bool isActive() const; //changed to const
        int getNRubies() const;
        void addRubis(const Rubis&);
        void setDisplayMode(bool endOfGame); 
        bool getDisplayMode() const;
        Side getSide() const; //changed to const
        void setSide(Side);
    private:
        string name;
        Side side;
        bool active = false;
        bool displayMode = false;
        int rubisCount = 0; 
};

ostream &operator<<(ostream& os, const Player& player){
    if (!(player.getDisplayMode())){
        string activeStatus = player.isActive() ? "active" : "inactive";
        os << player.getName() << ": " << player.getSide() << " (" << activeStatus << ")";
    }
    else
        os << player.getName() << ": " << player.getNRubies();
    return os;
}

void Player::setSide(Side side){
    this->side = side;
}

Side Player::getSide() const{
    return side;
}

bool Player::getDisplayMode() const{
    return displayMode;
}

void Player::setDisplayMode(bool endOfGame){
    this->displayMode = endOfGame;
}

void Player::addRubis(const Rubis &rubis){
    rubisCount += int(rubis);
}

int Player::getNRubies() const{
    return rubisCount;
}

bool Player::isActive() const{
    return active;
}

string Player::getName() const{
    return name;
}

void Player::setActive(bool active){
    this->active = active;
}

Player::Player(string name, Side side){
    this->name = name;
    this->side = side;
}

int main(){
    Player player ("David", bottom);
    player.addRubis(Rubis(4));

    cout << player.getName() << endl; // David
    cout << player.isActive()<< endl; // 0
    player.setActive(true); 
    cout << player.isActive()<< endl; // 1
    cout << player.getNRubies()<< endl; // 4
    cout << player.getSide()<< endl; // bottom
    player.setSide(top);
    cout << player.getSide()<< endl; // top
    cout << player << endl;
    player.setDisplayMode(true);
    cout << player << endl;
}