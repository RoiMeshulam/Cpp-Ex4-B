#ifndef EX4_PARTA_GAME_H
#define EX4_PARTA_GAME_H

#endif //EX4_PARTA_GAME_H

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup{

    class player;
    class Game {
    public:
        vector<string> _activePlayers;
        vector<Player*> _playerList;
        int _turn;
        int _id;
        bool _isPlaying;
        Game();
        ~Game();
        string turn();
        vector<string> players() const;
        string winner();

        //private functions
        int addPlayerToList(Player& player);
        void updatePlayerList();
    };
}