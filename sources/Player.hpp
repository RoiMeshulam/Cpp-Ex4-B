#ifndef EX4_PARTA_PLAYER_H
#define EX4_PARTA_PLAYER_H

#endif //EX4_PARTA_PLAYER_H

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
//#include "Game.hpp"

using namespace std;

namespace coup{

    enum Action{
       None=-1 ,  inc = 0 , foreign=1 , blockable_coup = 2, unblockable_coup = 3, transfer = 4 ,stealing = 5
    };


    class Game;
    class Player {
    public:
        //variables
        Game* pgame;
        int _numOfCoins;
        Action _lastAction;
        bool _isDead;
        string _name;
        int _playerID;
        int _stealCoins;
        Player* _lastVictim;

        //methods
        Player(Game& game,const string& name);
        ~Player();
        virtual void income();
        virtual void foreign_aid();
        virtual void coup(const Player& player);
        virtual string role();
        virtual int coins();

        void setIsDead();

    };



}
