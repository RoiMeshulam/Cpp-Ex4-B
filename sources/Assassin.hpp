#ifndef EX4_PARTA_ASSASSIN_H
#define EX4_PARTA_ASSASSIN_H

#endif //EX4_PARTA_ASSASSIN_H
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    class Assassin : public Player{
    public:
        Assassin(Game& game,string name): Player(game,name){

        }
        void coup(const Player& player);
        string role();
    };
}