#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup{
    int const maxPlayers = 10;
//    class player;
    Game::Game() {
        _turn=0;
        _id=0;
        _isPlaying= false;
    }
    Game::~Game(){}
    string Game::turn(){
        while (true){
            unsigned int index = (unsigned int)_turn % _playerList.size();
            if (_playerList.at(index)->_isDead){
                _turn++;
            }else{
                return _playerList.at(index)->_name;
            }
        }
    }
    vector<string>Game::players()const{
        return _activePlayers;
    }
    string Game::winner(){
        if (!_isPlaying){
            throw std::invalid_argument("The game doesn't begin yet");
        }
        if (_activePlayers.size()!=1){
            throw std::invalid_argument("Nobody won yet");
        }
        return _activePlayers.at(0);
    }

    int Game::addPlayerToList(Player& player){
        if (_playerList.size()==maxPlayers){
            throw std::invalid_argument("Too much players in game");
        }
        _playerList.push_back(&player);
        updatePlayerList();
//        player._playerID=_id++;
        return _id++;

    }

    void Game::updatePlayerList() {
        vector<string> temp;
        for (unsigned int i = 0; i < _playerList.size() ; ++i) {
            if(!_playerList.at(i)->_isDead){
                temp.push_back(_playerList.at(i)->_name);
            }
        }
        _activePlayers=temp;
    }

}