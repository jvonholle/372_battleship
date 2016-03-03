#include "bsboard.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;

//System specific terminal tools
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
const bool nux = true;
const bool win = false;

#elif __WIN32
#include <windows.h>
const bool nux = false;
const bool win = true;

#else
const bool nux = false;
const bool win = false;
#endif

//deCoord
//takes a char and an int
//returns an int
//turns battle ship style coordinates eg. (A,8)
//  into an int, which the place function takes
//returns -1 on invalid coordinate
int deCoord(string xi, string yi){
    try{
          char x = xi[0];
          int y = stoi(yi);
          if(y >0 && y<11){
              switch(x){
                  case 'A' : return ((y-1)*10)+0;
                  case 'B' : return ((y-1)*10)+1;
                  case 'C' : return ((y-1)*10)+2;
                  case 'D' : return ((y-1)*10)+3;
                  case 'E' : return ((y-1)*10)+4;
                  case 'F' : return ((y-1)*10)+5;
                  case 'G' : return ((y-1)*10)+6;
                  case 'H' : return ((y-1)*10)+7;
                  case 'I' : return ((y-1)*10)+8;
                  case 'J' : return ((y-1)*10)+9;
                  default : return -1;
              }
          }
          else
              return -1;
    }catch(std::invalid_argument){
          return -1;
    }
}

//singleplayer
//takes nothing
//returns nothing
//produces single player game loop
void singleplayer(){
    cout << "SINGLEPLAYER!!" << endl;
}

//twoplayer
//takes nothing
//returns nothing
//launches and runs two player game of battle ship
void twoplayer(){
    board boardP1;
    board boardP2;
    cout << "TWO PLAYER!!" << endl;
    string player1;
    string player2;
    cout << "Player 1, enter your name now: ";
    getline(cin,  player1);
    cout << "Okay! " << player1 << ", let Player 2 enter their name now: ";
    getline(cin,  player2);
   
    string check = "n"; 
    string ship;
    string xcoord;
    string ycoord;
    int pos;
    string rot;
    bool allplaced = false;
    bool nomatch = true;
    //player one turn one
    cout << player1 << " it's your turn to place your ships! " << player2 << " please look away." << endl;
    while(check != "y"){
         cout << "Is " << player2 << " looking away from the screen? (y,n) ";
         getline(cin,  check);
    }
    check = 'n';
    while(check != "y"){
        cout << player1 << " your pin is: " << boardP1.getPin() << " don't forget it!" << endl;
        cout << "Do you have it memorized? (y,n) ";
        getline(cin,  check);
    }
    while(!allplaced){
        cout << "-----SHIP PLACEMENT FOR " << player1 << "-----" << endl;
        cout << "> "; 
        getline(cin,  ship);
        nomatch = true;
        if(ship == "skip"){
            break;
        }
        for(auto& i : boardP1.getships())
            if(i.first == ship){
                while(true){
                    cout << player1 << " you are placing your " << ship << " it is " << boardP1.getship(ship).getsize() << " long" << endl;
                    cout << "Here is the current board:" << endl;
                    boardP1.print(1);
                    cout << "Where would you like your " << ship << " to be placed?  " << endl << "Letter: ";
                    getline(cin,  xcoord);
                    cout << "Number: ";
                    getline(cin,  ycoord);
                    pos = deCoord(xcoord, ycoord);
                    cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                    getline(cin, rot);
                    if(boardP1.place(ship, pos, rot.front()))
                        break;
                    else
                        cout << "Placement failed! Please try again." << endl;
                }
                nomatch = false;
            }
        if(ship == "help"){
           cout << "list -- list of ships and their status" << endl <<
              "help -- display this text" << endl <<
              "\"shipname\" -- enter place menu for named ship" << endl;
           nomatch = false;
        }else if(ship == "list"){
            for(auto& i : boardP1.getships()){
                cout << i.first << " : " ;
                if(i.second.getpos().first == -1){
                    cout << "not placed" << endl;
                    allplaced = false;
                }else{
                    cout << "placed" << endl;
                    allplaced = true;
                }
            }
           nomatch = false;
        }else if(nomatch){
            cout << "Unrecognized command! Type help for commands." << endl;
        }
        allplaced = true;
        for(auto& i : boardP1.getships())
            if(i.second.getpos().first == -1)
                allplaced = false;
    }//end player 1 turn 1

    cout << "Please hit enter when you are ready to pass to the next player";
    while(cin.get() != '\n');
    for(int i = 0; i< 1000; ++i)
        cout << endl;

    //player two turn one
    check = "n";
    cout << player2 << " it's your turn to place your ships! " << player1 << " please look away." << endl;
    while(check != "y"){
         cout << "Is " << player1 << " looking away from the screen? (y,n) ";
         getline(cin,  check);
    }
    check = 'n';
    while(check != "y"){
        cout << player2 << " your pin is: " << boardP2.getPin() << " don't forget it!" << endl;
        cout << "Do you have it memorized? (y,n) ";
        getline(cin,  check);
    }
    allplaced = false;
    while(!allplaced){
        cout << "-----SHIP PLACEMENT FOR " << player2 << "-----" << endl;
        cout << "> "; 
        nomatch = true;
        getline(cin,  ship);
        if(ship == "skip"){
            break;
        }
        for(auto& i : boardP2.getships())
            if(i.first == ship){
                while(true){
                    cout << player2 << " you are placing your " << ship << " it is " << boardP2.getship(ship).getsize() << " long" << endl;
                    cout << "Here is the current board:" << endl;
                    boardP2.print(1);
                    cout << "Where would you like your " << ship << " to be placed?  " << endl << "Letter: ";
                    getline(cin,  xcoord);
                    cout << "Number: ";
                    getline(cin,  ycoord);
                    pos = deCoord(xcoord, ycoord);
                    cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                    getline(cin, rot);
                    if(boardP2.place(ship, pos, rot.front()))
                        break;
                    else
                        cout << "Placement failed! Please try again." << endl;
                }
                nomatch = false;
            }
        if(ship == "help"){
           cout << "list -- list of ships and their status" << endl <<
              "help -- display this text" << endl <<
              "\"shipname\" -- enter place menu for named ship" << endl;
           nomatch = false;
        }else if(ship == "list"){
            for(auto& i : boardP2.getships()){
                cout << i.first << " : " ;
                if(i.second.getpos().first == -1){
                    cout << "not placed" << endl;
                }else{
                    cout << "placed" << endl;
                }
            }
           nomatch = false;
        }else if(nomatch){
            cout << "Unrecognized command! Type help for commands." << endl;
        }else if(ship == "skip"){
            break;
        }
        allplaced = true;
        for(auto& i : boardP2.getships())
            if(i.second.getpos().first == -1)
                allplaced = false;
    }//end player 2 turn 1
    int intpin;
    char shoot;  
    //main game loop
    while(true){
        bool victory = true;
        string pin;
//Player 1 turn
        for(int i = 0; i< 1000; ++i)
            cout << endl;

        cout << player1 << "'s turn" << endl;
        cout << player1 << " please input your pin: ";
        if(win){
            cout << "THIS IS WINDOWS" << endl;
        }else if(nux){
            termios oldt; 
            tcgetattr(STDIN_FILENO, &oldt);
            termios newt = oldt;
            newt.c_lflag &= ~ECHO;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            getline(cin, pin);
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        }
        while(true){
            try{
                intpin = stoi(pin);
            }catch(std::invalid_argument){
                intpin = 0;
            }
            if(stoi(pin) == boardP1.getPin()){
                cout << endl << "Welcome Admiral " << player1 << ", we've been waing for you." << endl;
                cout << "We've got the enemy on the run, where should we strike?" << endl;
                boardP1.print();
                cout << "Letter: ";
                getline(cin, xcoord); 
                cout << "Number: ";
                getline(cin, ycoord);
                shoot = boardP2.takeFire(deCoord(xcoord, ycoord));
                if(shoot == 'R'){
                    cout << "I'm sorry, we cannot fire there Admiral. Please try again." << endl;
                    continue;
                }else{
                    if(shoot == 'H')
                        cout << "It's a hit sir!" << endl;
                    else
                        cout << "I'm sorry sir it looks like we missed." << endl;

                    boardP1.settheirBoard(deCoord(xcoord, ycoord), shoot);
                    break;
                }
            }else{
                cout << endl << "Are you sure you're " << player1 <<"? I have orders to shoot on site if you're not." << endl
                    << "Try your pin again: ";
                if(win){
                    cout << "THIS IS WINDOWS" << endl;
                }else if(nux){
                    termios oldt; 
                    tcgetattr(STDIN_FILENO, &oldt);
                    termios newt = oldt;
                    newt.c_lflag &= ~ECHO;
                    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
                    getline(cin, pin);
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                }
            }
        }
//Check for Player 1 win
        for(auto&i : boardP2.getships())
	     if(!i.second.getsunk())
                 victory = false;
        if(victory){
            cout << player1 << " WINS!!";
            break;
        }
    cout << "Please hit enter when you are ready to pass to the next player";
    while(cin.get() != '\n');
    for(int i = 0; i< 1000; ++i)
        cout << endl;
//Player 2 turn
        cout << player2 << "'s turn" << endl;
        cout << player2 << " please input your pin: ";
        if(win){
        }else if(nux){
            termios oldt; 
            tcgetattr(STDIN_FILENO, &oldt);
            termios newt = oldt;
            newt.c_lflag &= ~ECHO;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            getline(cin, pin);
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        }
        while(true){
            try{
                intpin = stoi(pin);
            }catch(std::invalid_argument){
                intpin = 0;
            }
            if(intpin == boardP2.getPin()){
                cout << endl << "Welcome Admiral " << player2 << ", we've been waing for you." << endl;
                cout << "We've got the enemy on the run, where should we strike?" << endl;
                boardP2.print();
                cout << "Letter: ";
                getline(cin, xcoord); 
                cout << "Number: ";
                getline(cin, ycoord);
                shoot = boardP1.takeFire(deCoord(xcoord, ycoord));
                if(shoot == 'R'){
                    cout << "I'm sorry, we cannot fire there Admiral. Please try again." << endl;
                    continue;
                }else{
                    if(shoot == 'H')
                        cout << "Confirmed hit! Good shooting sir." << endl;
                    else
                        cout << "Damn! We missed sir, we'll get them next time." << endl;
                    boardP2.settheirBoard(deCoord(xcoord, ycoord), shoot);
                    break;
                }
            }else{
                cout << endl << "Are you sure you're " << player2 <<"? I have orders to shoot on site if you're not." << endl
                    << "Try your pin again: ";
                if(win){
                    cout << "THIS IS WINDOWS" << endl;
                }else if(nux){
                    termios oldt; 
                    tcgetattr(STDIN_FILENO, &oldt);
                    termios newt = oldt;
                    newt.c_lflag &= ~ECHO;
                    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
                    getline(cin, pin);
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                }
            }
        }
//Check for Player 1 win
//Check for Player 2 win
        for(auto&i : boardP1.getships())
	     if(!i.second.getsunk())
                 victory = false;
        if(victory){
            cout << player2 << " WINS!!";
            break;
        }
    cout << "Please hit enter when you are ready to pass to the next player";
    while(cin.get() != '\n');
    for(int i = 0; i< 1000; ++i)
        cout << endl;

    }
}


int main(){
    cout << ".______        ___      .___________..___________. __       _______      _______. __    __   __  .______   " << endl;
    cout << "|   _  \\      /   \\     |           ||           ||  |     |   ____|    /       ||  |  |  | |  | |   _  \\  " << endl;
    cout << "|  |_)  |    /  ^  \\    `---|  |----``---|  |----`|  |     |  |__      |   (----`|  |__|  | |  | |  |_)  | " << endl;
    cout << "|   _  <    /  /_\\  \\       |  |         |  |     |  |     |   __|      \\   \\    |   __   | |  | |   ___/  " << endl;
    cout << "|  |_)  |  /  _____  \\      |  |         |  |     |  `----.|  |____ .----)   |   |  |  |  | |  | |  |      " << endl;
    cout << "|______/  /__/     \\__\\     |__|         |__|     |_______||_______||_______/    |__|  |__| |__| | _|      " << endl;
   

    string input; 
    string quit;
    while(true){
      cout << endl << "------MAIN MENU-----" << endl;
      cout << "> ";
      getline(cin,  input);
          if(input == "singleplayer"){
              singleplayer(); 
          }else if(input == "twoplayer"){
              twoplayer();
          }else if(input == "help"){
              cout << "singleplayer - launch single player mode"<<endl<<
                  "twoplayer - launch two player mode"<<endl<<
                  "help - display this text"<<endl<<
                  "quit - exit game"<<endl;
          }else if(input == "quit"){
             cout << "Are you sure you want to quit? (y,n) ";
             getline(cin,  quit);
            if(quit == "y")
               break; 
          }else{
              cout << "Unrecognized command. Type help for commands." << endl;
          }
    }  
   return 0; 
}
