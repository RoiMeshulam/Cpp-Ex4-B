#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"
#include "Ambassador.hpp"
using namespace std;

namespace coup{
    int const maxRaise= 10;
    void Ambassador::transfer(const Player& player1,const Player& player2){
        if (pgame->_playerList.at((unsigned int)player1._playerID)->_numOfCoins==0){
            throw std::invalid_argument("not enough money to transfer");
        }
        if (_numOfCoins>=maxRaise){
            throw std::invalid_argument("The player has 10 coins and has to coup");
        }
        pgame->_playerList.at((unsigned int)player1._playerID)->_numOfCoins--;
        pgame->_playerList.at((unsigned int)player2._playerID)->_numOfCoins++;
        pgame->_turn++;
    }
    void Ambassador::block(const Player& player){
        if(player._lastAction!=stealing){
            throw std::invalid_argument("Ambassador can not block action that is not steal");
        }
        player._lastVictim->_numOfCoins+=player._stealCoins;
        pgame->_playerList.at((unsigned int)player._playerID)->_numOfCoins-=player._stealCoins;

    }
    string Ambassador::role(){
        return "Ambassador";
    }
}

