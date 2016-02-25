#include "bsboard.h"
#include <random>//for pin generation, random_device and uniform_int_distribuition<>
#include <utility>
using std::make_pair;

//SHIP CTOR
ship::ship(char sdes):sunk_(false),coord_(make_pair(-1, 'N')){
    switch(sdes){
        case 'd' : health_ = 2; size_ = 2; break;
        case 'c' : health_ = 3; size_ = 3; break;
        case 'a' : health_ = 5; size_ = 5; break;
        case 's' : health_ = 3; size_ = 3; break;
        case 'b' : health_ = 4; size_ = 4; break;
        default : health_ = 0; size_ = 0; 
        }
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
