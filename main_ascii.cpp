#include "bsboard.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <random>

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
void singleplayer() {
	cout << "SINGLEPLAYER!!" << endl;
	board boardPlayer;
	board boardBot;
	cout << "You wiil be facing a computer controlled player enemy" << endl;
	cout << "What difficulty Do you want to face?" << endl;
	char x;
	cin >> x;
	cout << "this doesnt work yet" << endl;

	/*
	switch (x);
	case '1': return 0;
	case '2': return 1;
	case '3': return 2;
	*/
	cout << " it's your turn to place your ships!" << endl;

	string check = "n";
	string ship;
	string xcoord;
	string ycoord;
	int pos;
	string rot;
	bool allplaced = false;

	while (!allplaced) {
		cout << "-----SHIP PLACEMENT-----" << endl;
		cout << "> ";
		getline(cin, ship);
		if (ship == "help") {
			cout << "list -- list of ships and their status" << endl <<
				"help -- display this text" << endl <<
				"\"shipname\" -- enter place menu for named ship" << endl;
		}
		else if (ship == "list") {
			for (auto& i : boardPlayer.getships()) {
				cout << i.first << " : ";
				if (i.second.getpos().first == -1) {
					cout << "not placed" << endl;
					allplaced = false;
				}
				else {
					cout << "placed" << endl;
					allplaced = true;
				}
			}
		}
		else if (ship == "Cruiser") {
			while (true) {
				cout << " you are placing your " << ship << " it is " << boardPlayer.getship(ship).getsize() << " long" << endl;
				cout << "Here is the current board:" << endl;
				boardPlayer.print(1);
				cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
				getline(cin, xcoord);
				cout << "N: ";
				getline(cin, ycoord);
				pos = deCoord(xcoord, ycoord);
				cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
				getline(cin, rot);
				if (boardPlayer.place(ship, pos, rot.front()))
					break;
				else
					cout << "Placement failed! Please try again." << endl;
			}
		}
		else if (ship == "Sub") {
			while (true) {
				cout << " you are placing your " << ship << " it is " << boardPlayer.getship(ship).getsize() << " long" << endl;
				cout << "Here is the current board:" << endl;
				boardPlayer.print(1);
				cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
				getline(cin, xcoord);
				cout << "N: ";
				getline(cin, ycoord);
				pos = deCoord(xcoord, ycoord);
				cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
				getline(cin, rot);
				if (boardPlayer.place(ship, pos, rot.front()))
					break;
				else
					cout << "Placement failed! Please try again." << endl;
			}
		}
		else if (ship == "Destroyer") {
			while (true) {
				cout << " you are placing your " << ship << " it is " << boardPlayer.getship(ship).getsize() << " long" << endl;
				cout << "Here is the current board:" << endl;
				boardPlayer.print(1);
				cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
				getline(cin, xcoord);
				cout << "N: ";
				getline(cin, ycoord);
				pos = deCoord(xcoord, ycoord);
				cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
				getline(cin, rot);
				if (boardPlayer.place(ship, pos, rot.front()))
					break;
				else
					cout << "Placement failed! Please try again." << endl;
			}
		}
		else if (ship == "Battleship") {
			while (true) {
				cout << " you are placing your " << ship << " it is " << boardPlayer.getship(ship).getsize() << " long" << endl;
				cout << "Here is the current board:" << endl;
				boardPlayer.print(1);
				cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
				getline(cin, xcoord);
				cout << "N: ";
				getline(cin, ycoord);
				pos = deCoord(xcoord, ycoord);
				cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
				getline(cin, rot);
				if (boardPlayer.place(ship, pos, rot.front()))
					break;
				else
					cout << "Placement failed! Please try again." << endl;
			}
		}
		else if (ship == "Carrier") {
			while (true) {
				cout << " you are placing your " << ship << " it is " << boardPlayer.getship(ship).getsize() << " long" << endl;
				cout << "Here is the current board:" << endl;
				boardPlayer.print(1);
				cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
				getline(cin, xcoord);
				cout << "N: ";
				getline(cin, ycoord);
				pos = deCoord(xcoord, ycoord);
				cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
				getline(cin, rot);
				if (boardPlayer.place(ship, pos, rot.front()))
					break;
				else
					cout << "Placement failed! Please try again." << endl;
			}
		}
		else {
			cout << "Unrecognized command! Type help for commands." << endl;
		}
		allplaced = true;
		for (auto& i : boardPlayer.getships())
			if (i.second.getpos().first == -1)
				allplaced = false;
	}//end player 1 turn 1

	/////////////////////////BOT SETUP///////////////////////////////////////
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 99);
	int dice_roll = distribution(generator);  // generates number in the range 0..99
	cout << "Computer player is placing it ships" << endl;

	//Coordinagtes
	xcoord = dice_roll;
	dice_roll = distribution(generator);
	ycoord = dice_roll;

	//Facing
	int facing = distribution(generator);
	if (0 == facing%4)
	{
		rot = 'U';
	}
	else if (1 == facing % 4)
	{
		rot = 'R';
	}
	else if (2 == facing % 4)
	{
		rot = 'L';
	}
	else if (3 == facing % 4)
	{
		rot = 'D';
	}
}
///////////////////////////////////////////////////////////////////////////////////////


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
        if(ship == "help"){
           cout << "list -- list of ships and their status" << endl <<
              "help -- display this text" << endl <<
              "\"shipname\" -- enter place menu for named ship" << endl;
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
        }else if(ship == "Cruiser"){
            while(true){
                cout << player1 << " you are placing your " << ship << " it is " << boardP1.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP1.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP1.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Sub"){
            while(true){
                cout << player1 << " you are placing your " << ship << " it is " << boardP1.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP1.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP1.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Destroyer"){
            while(true){
                cout << player1 << " you are placing your " << ship << " it is " << boardP1.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP1.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP1.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Battleship"){
            while(true){
                cout << player1 << " you are placing your " << ship << " it is " << boardP1.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP1.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP1.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Carrier"){
            while(true){
                cout << player1 << " you are placing your " << ship << " it is " << boardP1.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP1.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP1.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else{
            cout << "Unrecognized command! Type help for commands." << endl;
        }
        allplaced = true;
        for(auto& i : boardP1.getships())
            if(i.second.getpos().first == -1)
                allplaced = false;
    }//end player 1 turn 1

    cout << player1 << ", please hit enter and pass to " << player2 << "." <<endl;
    while(cin.get() != '\n');

    for(int i = 0; i< 1000; ++i)
        cout << endl;

    //player two turn one
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
    allplaced = false;
    while(!allplaced){
        cout << "-----SHIP PLACEMENT FOR " << player2 << "-----" << endl;
        cout << "> "; 
        getline(cin,  ship);
        if(ship == "help"){
           cout << "list -- list of ships and their status" << endl <<
              "help -- display this text" << endl <<
              "\"shipname\" -- enter place menu for named ship" << endl;
        }else if(ship == "list"){
            for(auto& i : boardP2.getships()){
                cout << i.first << " : " ;
                if(i.second.getpos().first == -1){
                    cout << "not placed" << endl;
                }else{
                    cout << "placed" << endl;
                }
            }
        }else if(ship == "Cruiser"){
            while(true){
                cout << player2 << " you are placing your " << ship << " it is " << boardP2.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP2.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP2.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Sub"){
            while(true){
                cout << player2 << " you are placing your " << ship << " it is " << boardP2.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP2.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP2.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Destroyer"){
            while(true){
                cout << player2 << " you are placing your " << ship << " it is " << boardP2.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP2.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP2.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Battleship"){
            while(true){
                cout << player2 << " you are placing your " << ship << " it is " << boardP2.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP2.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot); 
                if(boardP2.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else if(ship == "Carrier"){
            while(true){
                cout << player2 << " you are placing your " << ship << " it is " << boardP2.getship(ship).getsize() << " long" << endl;
                cout << "Here is the current board:" << endl;
                boardP2.print(1);
                cout << "Where would you like your " << ship << " to be placed? (LETTER, NUMBER) " << endl << "L: ";
                getline(cin,  xcoord);
                cout << "N: ";
                getline(cin,  ycoord);
                pos = deCoord(xcoord, ycoord);
                cout << "Which direction should your " << ship << " face? (U,D,L,R) ";
                getline(cin, rot);
                if(boardP2.place(ship, pos, rot.front()))
                    break;
                else
                    cout << "Placement failed! Please try again." << endl;
            }
        }else{
            cout << "Unrecognized command! Type help for commands." << endl;
        }
        allplaced = true;
        for(auto& i : boardP2.getships())
            if(i.second.getpos().first == -1)
                allplaced = false;
    }//end player 2 turn 1

    //main game loop
    while(true){
        cout << player1 << "'s turn" << endl;
        break;
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
