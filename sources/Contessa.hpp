#ifndef EX4_PARTA_CONTESSA_H
#define EX4_PARTA_CONTESSA_H

#endif //EX4_PARTA_CONTESSA_H

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    class Contessa : public Player{
    public:
        Contessa(Game& game,string name): Player(game,name){

        }
        void block(const Player& player);
        string role();
    };
}