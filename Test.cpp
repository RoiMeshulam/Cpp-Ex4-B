
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "doctest.h"

TEST_CASE("Winner") {
    Game game_8{}; // build game . add players
    Duke duke{game_8, "Moshe"};
    CHECK_THROWS(game_8.winner());
    Assassin assassin{game_8, "Yossi"};
    Ambassador ambassador{game_8, "Meirav"};
    Captain captain{game_8, "Reut"};
    Contessa contessa{game_8, "Gilad"};
    cout<< game_8.players().size()<<endl;

    for (int i=0 ; i<7 ; i++){
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }
    // each one has 7 coins, enough for using coup()
    duke.coup(assassin);
    ambassador.coup(contessa);
    captain.coup(ambassador);

    cout<< game_8.turn()<<endl;
    for (int i=0 ; i<7 ; i++){
        duke.income();
        captain.income();
    }
//    // each one has 7 coins, enough for using coup()
//    duke.coup(captain);
//
//    CHECK_EQ(game_8.winner(),"Moshe"); // the only one to stay in gane

}
//TEST_CASE("Roi"){
//    Game scenario3{};
//
//    Ambassador PlayerONE{scenario3, "Player ONE"};
//    Contessa PlayerTWO{scenario3, "Player TWO"};
//    Duke PlayerTHREE{scenario3, "Player THREE"};
//    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE};
//    PlayerONE.foreign_aid();
//    PlayerTWO.foreign_aid();
//    cout<<PlayerTWO.coins()<<endl;
//    PlayerTHREE.block(PlayerTWO);
//    cout<<PlayerTWO.coins()<<endl;
//    PlayerTHREE.foreign_aid();
//    PlayerONE.foreign_aid();
//    PlayerTWO.foreign_aid();
//    PlayerTHREE.foreign_aid();
//    PlayerONE.foreign_aid();
//    PlayerTWO.foreign_aid();
//    PlayerTHREE.foreign_aid();
//    PlayerONE.foreign_aid();
//    PlayerTWO.foreign_aid();
//    PlayerTHREE.foreign_aid();
//    cout<<PlayerONE.coins()<<endl;
//    cout<<PlayerTWO.coins()<<endl;
//    cout<<PlayerTHREE.coins()<<endl;
//    cout<<scenario3.turn()<<endl;
//
//    PlayerONE.coup(PlayerTWO);
//    vector<string> players = scenario3.players();
//    cout<<players.size()<< "players remain"<<endl;
//    for(string name : players){
//        cout << name << endl;
//    }





//}