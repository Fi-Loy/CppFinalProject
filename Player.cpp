#include "Player.h"

#include <iostream>
#include <string>
using namespace std;

ostream &operator<<(ostream& os, const Player& player){
    if (!(player.getDisplayMode())){
        string activeStatus = player.isActive() ? "active" : "inactive";
        os << player.getName() << ": " << player.getSide() + 1 << " (" << activeStatus << ")";
    }
    else
        os << player.getName() << ": " << player.getNRubis() << " rubis";
    return os;
}

//Set the Side of a player
void Player::setSide(Side side){
    this->side = side;
}

//Get the Side of a player
Side Player::getSide() const{
    return side;
}

//Get the display mode of a player
bool Player::getDisplayMode() const{
    return displayMode;
}

//Set the display mode of a player
void Player::setDisplayMode(bool endOfGame){
    this->displayMode = endOfGame;
}

//Add Rubis to the player's Rubis count
void Player::addRubis(const Rubis &rubis){
    rubisCount += int(rubis);
}

//Get the player's Rubis count
int Player::getNRubis() const{
    return rubisCount;
}

//Get the activity of the player
bool Player::isActive() const{
    return active;
}

//Get the name of the player
string Player::getName() const{
    return name;
}

//Set the activity of the player
void Player::setActive(bool active){
    this->active = active;
}

//Player constructor
Player::Player(string name, Side side){
    this->name = name;
    this->side = side;
}