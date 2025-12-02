#pragma once
#include "Rubis.h"
#include <iostream>

enum Side {top, right, bottom, left};

class Player{
    friend std::ostream &operator<<(std::ostream&, const Player&);
    public:
        Player(std::string name, Side side);
        std::string getName() const;
        void setActive(bool);
        bool isActive() const; //changed to const
        int getNRubis() const;
        void addRubis(const Rubis&);
        void setDisplayMode(bool endOfGame); 
        bool getDisplayMode() const;
        Side getSide() const; //changed to const
        void setSide(Side);
    private:
        std::string name;
        Side side;
        bool active = false;
        bool displayMode = false;
        int rubisCount = 0; 
};

/* main method for testing
int main(){
    Player player ("David", bottom);
    player.addRubis(Rubis(4));

    cout << player.getName() << endl; // David
    cout << player.isActive()<< endl; // 0
    player.setActive(true); 
    cout << player.isActive()<< endl; // 1
    cout << player.getNRubis()<< endl; // 4
    cout << player.getSide()<< endl; // bottom
    player.setSide(top);
    cout << player.getSide()<< endl; // top
    cout << player << endl;
    player.setDisplayMode(true);
    cout << player << endl;
}
*/