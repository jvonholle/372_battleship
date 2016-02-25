#include "bsboard.h"
#include <random>

//SHIP CTOR
ship::ship (char sdes){
}

//BOARD FUNCTIONS

//CTOR
board::board(){
    myBoard_.resize(100,0);
    theirBoard_.resize(100,0);

    ships_["Destroyer"] = ship('d');
    ships_["Cruiser"] = ship('c');
    ships_["Carrier"] = ship('a');
    ships_["Sub"] = ship('s');
    ships_["Battleship"] = ship('b');
    
    std::random_device gen;
    std::uniform_int_distribution<> pin(100,999);
    pin_ = pin(gen);
}

char board::takeFire(int coord){
}

bool board::place(string shipName, int coord, char rot){
}

void board::print(){
}
