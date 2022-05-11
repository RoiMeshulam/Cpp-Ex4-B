#ifndef EX4_PARTA_AMBASSADOR_H
#define EX4_PARTA_AMBASSADOR_H

#endif //EX4_PARTA_AMBASSADOR_H

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(Game& game,string name): Player(game,name){

        }
        void transfer(const Player& player1,const Player& player2);
        void block(const Player& player);
        string role();
    };
}