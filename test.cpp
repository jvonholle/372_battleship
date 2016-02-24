
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bsboard.h"
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;

TEST_CASE("Testing Board, Standard Rules"){
    board test;
    
    SECTION("Checking myBoard"){
        REQUIRE(test.getmyBoard().size() == 100);
        for(int i =0; i<100; ++i){
            REQUIRE(test.getmyBoard()[i] >=-1);
            REQUIRE(test.getmyBoard()[i] <= 2);
        }
            
    }
    SECTION("Check theirBoard"){
        REQUIRE(test.gettheirBoard().size() == 100);
        for(int i =0; i<100; ++i){
            REQUIRE(test.getmyBoard()[i] >=-1);
            REQUIRE(test.getmyBoard()[i] <= 2);
            REQUIRE(test.getmyBoard()[i] != 1);
        }
    }
    SECTION("Check pin"){
        REQUIRE(test.getPin() >= 100);
        REQUIRE(test.getPin() <= 999);
    }
    SECTION("Check Ships"){
        SECTION("Checking Carrier"){
            REQUIRE(test.getship("Carrier").getsize() == 5);
            REQUIRE(test.getship("Carrier").getpos().first == -1);
            REQUIRE(test.getship("Carrier").getpos().second == 'N');
            REQUIRE(test.getship("Carrier").gethealth() == 5);
            REQUIRE(test.getship("Carrier").getsunk() == false);
        }
        SECTION("Check Battleship"){
            REQUIRE(test.getship("Battleship").getsize() == 4);
            REQUIRE(test.getship("Battleship").getpos().first == -1);
            REQUIRE(test.getship("Battleship").getpos().second == 'N'); 
            REQUIRE(test.getship("Battleship").gethealth() == 4);
            REQUIRE(test.getship("Battleship").getsunk() == false);
        }
        SECTION("Check Sub"){
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getpos().first == -1);
            REQUIRE(test.getship("Sub").getpos().second == 'N'); 
            REQUIRE(test.getship("Sub").gethealth() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
        }
        SECTION("Check Cruiser"){
            REQUIRE(test.getship("Cruiser").getsize() == 3);
            REQUIRE(test.getship("Cruiser").getpos().first == -1);
            REQUIRE(test.getship("Cruiser").getpos().second == 'N'); 
            REQUIRE(test.getship("Cruiser").gethealth() == 3);
            REQUIRE(test.getship("Cruiser").getsunk() == false);
        }
        SECTION("Check Destroyer"){
            REQUIRE(test.getship("Destroyer").getsize() == 2);
            REQUIRE(test.getship("Destroyer").getpos().first == -1);
            REQUIRE(test.getship("Destroyer").getpos().second == 'N');
            REQUIRE(test.getship("Destroyer").gethealth() == 2);
            REQUIRE(test.getship("Destroyer").getsunk() == false);
        }
    }
    SECTION("Check place()"){
        //check success right
        SECTION("Check good place right"){
        REQUIRE(test.place("Sub", 13, 'R') == true);
        REQUIRE(test.getship("Sub").getpos().first == 13);
        REQUIRE(test.getship("Sub").getpos().second == 'R'); 
        REQUIRE(test.getship("Sub").gethealth() == 3);
        REQUIRE(test.getship("Sub").getsunk() == false);
        REQUIRE(test.getmyBoard()[13] == 1);
        REQUIRE(test.getmyBoard()[14] == 1);
        REQUIRE(test.getmyBoard()[15] == 1);}  
        //check success left
        SECTION("Check good place left"){
        REQUIRE(test.place("Destroyer", 37, 'L') == true);
        REQUIRE(test.getship("Destroyer").getpos().first == 37);
        REQUIRE(test.getship("Destroyer").getpos().second == 'L'); 
        REQUIRE(test.getship("Destroyer").gethealth() == 2);
        REQUIRE(test.getship("Destroyer").getsunk() == false);
        REQUIRE(test.getmyBoard()[37] == 1);
        REQUIRE(test.getmyBoard()[36] == 1);} 
        //check success up
        SECTION("Check good place up"){
        REQUIRE(test.place("Carrier", 89, 'U') == true);
        REQUIRE(test.getship("Carrier").getpos().first == 89);
        REQUIRE(test.getship("Carrier").getpos().second == 'U'); 
        REQUIRE(test.getship("Carrier").gethealth() == 5);
        REQUIRE(test.getship("Carrier").getsunk() == false);
        REQUIRE(test.getmyBoard()[89] == 1);
        REQUIRE(test.getmyBoard()[79] == 1);
        REQUIRE(test.getmyBoard()[69] == 1);  
        REQUIRE(test.getmyBoard()[59] == 1); 
        REQUIRE(test.getmyBoard()[49] == 1);}
        //check success down
        SECTION("Check good place down"){
        REQUIRE(test.place("Battleship", 43, 'D') == true);
        REQUIRE(test.getship("Battleship").getpos().first == 43);
        REQUIRE(test.getship("Battleship").getpos().second == 'D'); 
        REQUIRE(test.getship("Battleship").gethealth() == 4);
        REQUIRE(test.getship("Battleship").getsunk() == false);
        REQUIRE(test.getmyBoard()[43] == 1);
        REQUIRE(test.getmyBoard()[53] == 1);
        REQUIRE(test.getmyBoard()[63] == 1);  
        REQUIRE(test.getmyBoard()[73] == 1);}
        //check fail because already placed
        SECTION("Check fail becase already placed"){
        REQUIRE(test.place("Sub", 7, 'L') == false);
        REQUIRE(test.getship("Sub").getpos().first == 13);
        REQUIRE(test.getship("Sub").getpos().second == 'R'); 
        REQUIRE(test.getship("Sub").gethealth() == 3);
        REQUIRE(test.getship("Sub").getsunk() == false);
        REQUIRE(test.getmyBoard()[13] == 1);
        REQUIRE(test.getmyBoard()[14] == 1);
        REQUIRE(test.getmyBoard()[15] == 1); } 
        //check fail because bad position
        SECTION("Check fail bad place"){
        REQUIRE(test.place("Cruiser", 0, 'L') == false);
        REQUIRE(test.getship("Cruiser").getpos().first == -1);
        REQUIRE(test.getship("Carrier").getpos().second == 'N'); 
        REQUIRE(test.getship("Cruiser").gethealth() == 3);
        REQUIRE(test.getship("Cruiser").getsunk() == false);}
    }
    SECTION("Check takeFire()"){
        //check hit
        SECTION("Check hit"){
        REQUIRE(test.takeFire(13) == 'H');
        REQUIRE(test.getship("Sub").gethealth() == 2);
        REQUIRE(test.getship("Sub").getsize() == 3);
        REQUIRE(test.getship("Sub").getsunk() == false);
        REQUIRE(test.getmyBoard()[13] == 2);}
        //check miss
        SECTION("Check miss"){
        REQUIRE(test.takeFire(56) == 'M');
        REQUIRE(test.getmyBoard()[56] == -1);}
        //check shoot same spot
        SECTION("Check same spot"){
        REQUIRE(test.takeFire(13) == 'R');
        REQUIRE(test.getmyBoard()[13] == 2);
        REQUIRE(test.getship("Sub").gethealth() == 2);
        REQUIRE(test.getship("Sub").getsunk() == false);}
        //check another shot
        SECTION("Check another hit, same ship"){
        REQUIRE(test.takeFire(14) == 'H');
        REQUIRE(test.getship("Sub").gethealth() == 1);
        REQUIRE(test.getship("Sub").getsize() == 3);
        REQUIRE(test.getship("Sub").getsunk() == false);
        REQUIRE(test.getmyBoard()[14] == 2);}
        //check sink
        SECTION("Check sink"){
        REQUIRE(test.takeFire(15) == 'H');
        REQUIRE(test.getship("Sub").gethealth() == 0);
        REQUIRE(test.getship("Sub").getsize() == 3);
        REQUIRE(test.getship("Sub").getsunk() == true);
        REQUIRE(test.getmyBoard()[15] == 2);}
    }
    SECTION("Check print()"){
       //not sure what to put here, might just check visually 
    }    

}
