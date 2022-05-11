#ifndef EX4_PARTA_DUKE_H
#define EX4_PARTA_DUKE_H

#endif //EX4_PARTA_DUKE_H

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Duke : public Player{
    public:
        Duke(Game& game,string name): Player(game,name){

        }
        void tax();
        void block(const Player& player);
        string role();
    };
}