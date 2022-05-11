#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup{
    int const coupCost = 7;
    int const cheapCoup = 3;
    void Assassin::coup(const Player& player){
        if (pgame->_playerList.at((unsigned int)player._playerID)->_isDead){
            throw std::invalid_argument("can not coup player who already dead");
        }
        if (_numOfCoins<cheapCoup){
            throw std::invalid_argument("There is no enough coins to coup");
        }
        if(_numOfCoins>=cheapCoup && _numOfCoins<coupCost){
            pgame->_playerList.at((unsigned int)player._playerID)->_isDead=true;
            _lastVictim=pgame->_playerList.at((unsigned int)player._playerID);
            _lastAction = blockable_coup;
            _numOfCoins-=cheapCoup;
            pgame->updatePlayerList();
            pgame->_turn++;
        }
        else{
            pgame->_playerList.at((unsigned int)player._playerID)->_isDead=true;
            _lastVictim=pgame->_playerList.at((unsigned int)player._playerID);
            _lastAction = unblockable_coup;
            _numOfCoins-=coupCost;
            pgame->updatePlayerList();
            pgame->_turn++;
        }
    }
    string Assassin::role() {
        return "Assassin";
    }
}