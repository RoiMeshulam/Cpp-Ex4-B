#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"
#include "Contessa.hpp"

using namespace std;

namespace coup{
    void Contessa::block(const Player& player){
        if (player._lastAction != blockable_coup){
            throw std::invalid_argument("Contessa can only block assassination");
        }
        pgame->_playerList.at((unsigned int)player._lastVictim->_playerID)->_isDead=false;
        pgame->updatePlayerList();


    }
    string Contessa::role(){
        return "Contessa";
    }
}