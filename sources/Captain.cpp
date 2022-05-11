#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"

using namespace std;

namespace coup{
    int const maxRaise= 10;
    void Captain::steal(const Player& player){
        if (pgame->turn()!= _name){
            throw std::invalid_argument("Someone play and it is not his turn");
        }
        if (_numOfCoins>=maxRaise){
            throw std::invalid_argument("The player has 10 coins and has to coup");
        }
        _lastVictim=pgame->_playerList.at((unsigned int)player._playerID);
        if (player._numOfCoins==0){
            _stealCoins=0;
            pgame->_turn++;
            _lastAction=stealing;
        }
        else if(player._numOfCoins==1){
            pgame->_playerList.at((unsigned int)player._playerID)->_numOfCoins--;
            _numOfCoins++;
            _stealCoins=1;
            pgame->_turn++;
            _lastAction=stealing;
        }
        else{
            pgame->_playerList.at((unsigned int)player._playerID)->_numOfCoins-=2;
            _numOfCoins+=2;
            _stealCoins=2;
            pgame->_turn++;
            _lastAction=stealing;
        }
    }
    void Captain::block(Player player){
        if (player._lastAction!= stealing || player.role()!="Captain"){
            throw std::invalid_argument("Captain can not block an action that is not steal");
        }
        player._lastVictim->_numOfCoins+=player._stealCoins;
        pgame->_playerList.at((unsigned int)player._playerID)->_numOfCoins-=_stealCoins;

    }
    string Captain::role(){
        return "Captain";
    }

}
