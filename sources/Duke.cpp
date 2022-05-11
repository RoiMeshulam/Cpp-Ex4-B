
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"

using namespace std;

namespace coup{
    int const maxRaise= 10;
    void Duke::tax(){
        if (pgame->_turn==0){
            pgame->_isPlaying=true;
        }
        if (_numOfCoins>=maxRaise){
            throw std::invalid_argument("The player has 10 coins and has to coup");
        }
        _numOfCoins+=3;
        pgame->_turn++;

    }
    void Duke::block(const Player& player){
        if (player._lastAction!=foreign){
            throw std::invalid_argument("Duke can not block an action that is not foreign_aid");
        }
        pgame->_playerList.at((unsigned int)player._playerID)->_numOfCoins-=2;
    }
    string Duke::role(){
        return "Duke";
    }
}
