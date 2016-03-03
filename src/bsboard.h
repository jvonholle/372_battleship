#ifndef BSBOARD_H_INCLUDED
#define BSBOARD_H_INCLUDED

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
#include <utility>
using std::pair;
using std::make_pair;
#include <cstddef>
using std::size_t;

//struct ship
//pair<int, char>for coord and orientation(ori)
//bool for sunk, ints for size & health
//functions defined in bsboard.cpp
//      **INVARIANT** if not placed coord == -1 and ori == N

class ship{
    public:
        ship()
        {}
        //one param ctor
        //takes char, sets stats according to ship
        ship(char sdes);

        //member functions
        pair<int, char> getpos(){
           return coord_;}
        void setpos(int i, char c){
            coord_ = make_pair(i,c);}
        int gethealth(){
           return health_;}
        int getsize(){
           return size_;}
        bool getsunk(){
            return sunk_;}
        void sink(){
            sunk_ = true;
        }
        const ship& operator--(){
            health_ = health_-1;
        }
    private:
        pair<int, char> coord_;
        int health_;
        int size_;
        bool sunk_;
};

//class board
//vector for player's board, knows where ships are
//vector for other player's board, does not know where ships are
//      **INVARIANT** vector theirBoard cannot have 1 as a value
//functions defined in bsboard.cpp
class board{
    public:
        //Default ctor
        //defines everything according to standard rules
        board();

        //Using built in Copy op, copy ctor and dtor

        //accessor functions
        vector<int> getmyBoard(){
            return myBoard_;}
        vector<int> gettheirBoard(){
            return theirBoard_;}
        void settheirBoard(int coord, char stat){
            switch(stat){
                case 'H' : theirBoard_[coord] = 2; break;
                case 'M' : theirBoard_[coord] = -1; break;
                default  : theirBoard_[coord] = 0;
            }
        }
        int getPin(){
            return pin_;}
        map<string, ship> getships(){
            return ships_;
        }
        ship getship(string shipName){
            return ships_[shipName];}

        //member functions
        char takeFire(int coord);

        bool place(const string & shipName, const int & coord, const char & rot);

        void print(int i);
        void print();

    private:
        map<string, ship> ships_;
        vector<int> myBoard_;
        vector<int> theirBoard_;
        int pin_;
}; //END CLASS BOARD

//EOF
#endif
