#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    int const coupCost=7;
    int const maxRaise= 10;
    int const maxPlayersSize=6;

    Player::Player(Game& game,const string& name){
        _numOfCoins=0;
        _name=name;
        _lastAction=None;
        _stealCoins=0;
        _lastVictim=0;
        pgame=&game;
        if (pgame->_isPlaying){
            throw std::invalid_argument("can not add players in the middle of the game");
        }
        if (pgame->players().size()==maxPlayersSize){
            throw std::invalid_argument("The game is full");
        }
        _isDead= false;
        _playerID = game.addPlayerToList(*this);

    }

    Player::~Player(){}

    void Player::income(){
        if (pgame->players().size()<2){
            throw std::invalid_argument("There are no enough players in the game");
        }
        if (pgame->turn()!= _name){
            throw std::invalid_argument("Someone play and it is not his turn");
        }
        if (_numOfCoins>=maxRaise){
            throw std::invalid_argument("The player has 10 coins and has to coup");
        }
        _numOfCoins++;
        if (pgame->_turn==0){
            pgame->_isPlaying=true;
        }
        pgame->_turn++;
        _lastAction = inc;
    }
    void Player::foreign_aid(){
        if (pgame->players().size()<2){
            throw std::invalid_argument("There are no enough players in the game");
        }
        if (pgame->turn()!= _name){
            throw std::invalid_argument("Someone play and it is not his turn");
        }
        if (_numOfCoins>=maxRaise){
            throw std::invalid_argument("The player has 10 coins and has to coup");
        }
        _numOfCoins += 2;
        if (pgame->_turn==0){
            pgame->_isPlaying=true;
        }
        pgame->_turn++;
        _lastAction = foreign;
    }
    void Player::coup(const Player& player){
        if (pgame->turn()!= _name){
            throw std::invalid_argument("Someone play and it is not his turn");
        }
        if (pgame->players().size()<2){
            throw std::invalid_argument("There are no enough players in the game");
        }
        if (_numOfCoins < coupCost){
            throw std::invalid_argument("There weren't enough coins in order to coup someone");
        }
        if (pgame->_playerList.at((unsigned int)player._playerID)->_isDead){
            throw std::invalid_argument("can not coup player who already dead");
        }
        pgame->_playerList.at((unsigned int)player._playerID)->_isDead=true; // update in vector of pointers that the player is dead
        pgame->updatePlayerList();
        _numOfCoins-=coupCost;
        _lastAction = unblockable_coup;
        pgame->_turn++;
    }
    string Player::role(){
        return "Player";
    }
    int Player::coins(){
        return _numOfCoins;
    }

    void Player::setIsDead() {
//        if (_isDead){
//            _isDead=false;
//        }
//        else{
//            _isDead=true;
//        }
        _isDead=!(_isDead);
    }

}