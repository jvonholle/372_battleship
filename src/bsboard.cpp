#include "bsboard.h"
#include <iostream>
using std::cout;
using std::endl;
#include <cstddef>
using std::size_t;
#include <random>//for pin generation and ai things, random_device and uniform_int_distribuition<>
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

    ships_["Battleship"] = ship('b');
    ships_["Carrier"] = ship('a');
    ships_["Cruiser"] = ship('c');
    ships_["Destroyer"] = ship('d');
    ships_["Sub"] = ship('s');
    
    std::random_device gen;
    std::uniform_int_distribution<> pin(100,999);
    pin_ = pin(gen);
}

//takeFire
char board::takeFire(int coord){
    if(coord < 0 || coord > 100)
        return 'R';
    if (myBoard_[coord] == 1) //hits a boat
    {
        myBoard_[coord] = 2;
        for(auto& i : ships_){
                if(i.second.getpos().first == coord){
                    --i.second;
                    break;
                }else{
                    switch(i.second.getpos().second){
                        case 'U' : {
                                        for(int j = 0; j < i.second.getsize(); ++j)
                                            if(coord + (j*10) == i.second.getpos().first)
                                                --i.second;
                                        if(i.second.gethealth() == 0)
                                            i.second.sink();
                                        break;
                                   }
                        case 'D' : {
                                        for(int j = 0; j < i.second.getsize(); ++j)
                                            if(coord - (j*10) == i.second.getpos().first)
                                                --i.second;
                                        if(i.second.gethealth() == 0)
                                            i.second.sink();
                                        break;
                                   }
                        case 'L' : {
                                        for(int j = 0; j < i.second.getsize(); ++j)
                                            if(coord + j == i.second.getpos().first)
                                                --i.second;
                                        if(i.second.gethealth() == 0)
                                            i.second.sink();
                                        break;

                                   }
                        case 'R' : {
                                        for(int j = 0; j < i.second.getsize(); ++j)
                                            if(coord - j == i.second.getpos().first)
                                                --i.second;
                                        if(i.second.gethealth() == 0)
                                            i.second.sink();
                                        break;
                                   }
                    }
                }
            }
        return 'H';
    }
    else if (myBoard_[coord] == 0) //open water
    {
        myBoard_[coord] = -1;
        return 'M';
    }
    return 'R'; // they chose something wrong
}

//place
bool board::place(const string & shipName, const int & coord, const char & rot){
    if(coord < 0 || coord >99){
        ships_[shipName].setpos(-1,'N');
        return false;
    }
    if(ships_[shipName].getpos().first == -1 && ships_[shipName].getpos().second == 'N'){
    switch(rot){
        case 'U' : {
                       if(coord < ships_[shipName].getsize() * 10 ){
                           ships_[shipName].setpos(coord,rot);
                           return false;
                       }
                       else{
                           for(int i = 0; i < ships_[shipName].getsize(); ++i){
                               if(myBoard_[coord-(i*10)] != 0){
                                   ships_[shipName].setpos(-1,'N');
                                   return false;
                               }
                              myBoard_[coord-(i*10)] = 1;
                           } 
                           ships_[shipName].setpos(coord,rot);
                           return true;
                       }
                   }
        case 'R' : {
                       for(int i = 1; i < ships_[shipName].getsize()+1; ++i)
                           if((coord+i)%10 == 0){
                               ships_[shipName].setpos(coord,rot);
                               return false;
                           }
                       for(int i = 0; i < ships_[shipName].getsize(); ++i){
                           if(myBoard_[coord+i] != 0){
                               ships_[shipName].setpos(-1,'N');
                               return false;
                           }
                           myBoard_[coord+i] = 1;
                       }
                       ships_[shipName].setpos(coord,rot);
                       return true;
                   }
        case 'L' : {
                       for(int i = 0; i < ships_[shipName].getsize(); ++i)
                           if((coord-i)%10 == 0){
                               ships_[shipName].setpos(coord,rot);
                               return false;
                           }
                       for(int i = 0; i < ships_[shipName].getsize(); ++i){
                           if(myBoard_[coord-i] != 0){
                               ships_[shipName].setpos(coord,rot);
                               return false;
                           }
                           myBoard_[coord-i] = 1; 
                       }
                       ships_[shipName].setpos(coord,rot);
                       return true;
                   }
        case 'D' : {
                       if(coord + ships_[shipName].getsize() * 10 > 100){
                           ships_[shipName].setpos(coord,rot);
                           return false;
                       }
                       else{
                           for(int i = 0; i < ships_[shipName].getsize(); ++i){
                               if(myBoard_[coord+(i*10)] != 0){
                                   ships_[shipName].setpos(coord,rot);
                                   return false;
                               }
                              myBoard_[coord+(i*10)] = 1; 
                           }
                           ships_[shipName].setpos(coord,rot);
                           return true;
                       }
                   }
        default :  ships_[shipName].setpos(-1,'N'); return false;
        }
    }
    ships_[shipName].setpos(-1,'N'); 
    return false;
}

void board::print(int i){
    for(int i = 0; i < 11; ++i){
        if(i > 0 && i < 10)
            cout << i << " ";
        else if(i == 10) 
            cout << i; 
        for(int j = 0; j < 10; ++j){
            if(i == 0){
               switch(j){
                    case 0 : cout << "   A";  break;
                    case 1 : cout << " B";  break;
                    case 2 : cout << " C";  break;
                    case 3 : cout << " D";  break;
                    case 4 : cout << " E";  break;  
                    case 5 : cout << " F";  break; 
                    case 6 : cout << " G";  break; 
                    case 7 : cout << " H";  break; 
                    case 8 : cout << " I";  break; 
                    case 9 : cout << " J";  break; 
                    default : cout << "error";
                }
            }
            else{
            switch(getmyBoard()[((i-1)*10)+j]){
                case 0 : cout << " ~"; break;
                case 1 : cout << " |"; break;
                default : cout << "ERROR";
            }
            }
        }
        cout << endl;
    }
}


void board::print(){
    for(int i = 0; i < 11; ++i){
        if(i > 0 && i < 10)
            cout << i << " ";
        else if(i == 10) 
            cout << i; 
        for(int j = 0; j < 10; ++j){
            if(i == 0){
               switch(j){
                    case 0 : cout << "   A";  break;
                    case 1 : cout << " B";  break;
                    case 2 : cout << " C";  break;
                    case 3 : cout << " D";  break;
                    case 4 : cout << " E";  break;  
                    case 5 : cout << " F";  break; 
                    case 6 : cout << " G";  break; 
                    case 7 : cout << " H";  break; 
                    case 8 : cout << " I";  break; 
                    case 9 : cout << " J";  break; 
                    default : cout << "error";
                }
            }
            else{
            switch(gettheirBoard()[((i-1)*10)+j]){
                case 0 : cout << " ~"; break;
                case 2 : cout << " o"; break;
                case -1 : cout << " x"; break;
                default : cout << "ERROR";
            }
            }
        }
        cout << endl;
    }
    for(int i = 0; i < 11; ++i){
        if(i > 0 && i < 10)
            cout<< "                       " << i << " ";
        else if(i == 10) 
            cout << "                       " << i ; 
        for(int j = 0; j < 10; ++j){
            if(i == 0){
               switch(j){
                    case 0 : cout << "                          A";  break;
                    case 1 : cout << " B";  break;
                    case 2 : cout << " C";  break;
                    case 3 : cout << " D";  break;
                    case 4 : cout << " E";  break;  
                    case 5 : cout << " F";  break; 
                    case 6 : cout << " G";  break; 
                    case 7 : cout << " H";  break; 
                    case 8 : cout << " I";  break; 
                    case 9 : cout << " J";  break; 
                    default : cout << "error";
                }
            }
            else{
            switch(getmyBoard()[((i-1)*10)+j]){
                case 0 : cout << " ~"; break;
                case 1 : cout << " |"; break;
                case 2 : cout << " o"; break;
                case -1 : cout << " x"; break;
                default : cout << "ERROR";
            }
            }
        }
        cout << endl;
    }
}

pair<int, int> board::go(pair<int, int> state, board & enemy){
    std::random_device gen;
    std::uniform_int_distribution<> pos(0,99);
    char shoot = 'b';
    int shot = state.second;
    while(true){
        if(state.first == 0){
            shot = pos(gen);
            shoot = enemy.takeFire(shot);
            if(shoot == 'R')
                continue;
            else if(shoot == 'H')
                return make_pair(1, shot+1);
            else
                return make_pair(0, 0);
        }else if(state.first == 1){
            shoot = enemy.takeFire(state.second);
            if(shoot == 'R'){
                state.first = 0;
                continue;
            }else if(shoot == 'H')
                return make_pair(1, shot+1);
            else
                return make_pair(2, shot-2);
        }else if(state.first == 2){
            shoot = enemy.takeFire(state.second);
            if(shoot == 'R'){
                state.first = 0;
                continue;
            }else if(shoot == 'H')
                return make_pair(2, shot-1);
            else
                return make_pair(3, shot+11);
        }else if(state.first == 3){
            shoot = enemy.takeFire(state.second);
            if(shoot == 'R'){
                state.first = 0;
                continue;
            }else if(shoot == 'H')
                return make_pair(3, shot+10);
            else
                return make_pair(4, shot-20);
        }else if(state.first == 4){
            shoot = enemy.takeFire(state.second);
            if(shoot == 'R'){
                state.first = 0;
                continue;
            }else if(shoot == 'H')
                return make_pair(4, shot-10);
            else
                return make_pair(0,0);
        }else{
            return make_pair(0,0);
        }
    }
}

void board::init(){
    std::random_device gen;
    std::uniform_int_distribution<> pos(0,99);
    std::uniform_int_distribution<> rot(0,3);
    char ori;
    int temp;
    bool placed;
    for(auto & i : ships_){
        placed = false;
        while(!placed){
            temp = rot(gen); 
            switch(temp){
                case 0 : ori = 'U'; break;
                case 1 : ori = 'L'; break;
                case 2 : ori = 'R'; break;
                case 3 : ori = 'D'; break;
                default : ori = 'z';
            }
            temp = pos(gen);
            placed = place(i.first, temp, ori);
        }
    }
}
