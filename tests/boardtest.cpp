
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/bsboard.h"
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
}
TEST_CASE("Testing Ships"){
    board test;
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
TEST_CASE("Testing Place"){
    board test;
        //check success right
        SECTION("Check good place right"){
            REQUIRE(test.place("Sub", 13, 'R') == true);
            REQUIRE(test.getship("Sub").getpos().first == 13);
            REQUIRE(test.getship("Sub").getpos().second == 'R'); 
            REQUIRE(test.getship("Sub").gethealth() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.getmyBoard()[13] == 1);
            REQUIRE(test.getmyBoard()[14] == 1);
            REQUIRE(test.getmyBoard()[15] == 1);
        }  
        //check success left
        SECTION("Check good place left"){
            REQUIRE(test.place("Destroyer", 37, 'L') == true);
            REQUIRE(test.getship("Destroyer").getpos().first == 37);
            REQUIRE(test.getship("Destroyer").getpos().second == 'L'); 
            REQUIRE(test.getship("Destroyer").gethealth() == 2);
            REQUIRE(test.getship("Destroyer").getsunk() == false);
            REQUIRE(test.getmyBoard()[37] == 1);
            REQUIRE(test.getmyBoard()[36] == 1);
        } 
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
            REQUIRE(test.getmyBoard()[49] == 1);
        }
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
            REQUIRE(test.getmyBoard()[73] == 1);
        }
        SECTION("Check fail because of overlap"){
            REQUIRE(test.place("Battleship", 43, 'D') == true);
            REQUIRE(test.getship("Battleship").getpos().first == 43);
            REQUIRE(test.getship("Battleship").getpos().second == 'D'); 
            REQUIRE(test.getship("Battleship").gethealth() == 4);
            REQUIRE(test.getship("Battleship").getsunk() == false);
            REQUIRE(test.getmyBoard()[43] == 1);
            REQUIRE(test.getmyBoard()[53] == 1);
            REQUIRE(test.getmyBoard()[63] == 1);  
            REQUIRE(test.getmyBoard()[73] == 1);
            REQUIRE(test.place("Cruiser", 52, 'L') == false);
            REQUIRE(test.getship("Cruiser").getpos().first == -1);
            REQUIRE(test.getship("Carrier").getpos().second == 'N'); 
            REQUIRE(test.getship("Cruiser").gethealth() == 3);
            REQUIRE(test.getship("Cruiser").getsunk() == false);
            REQUIRE(test.getmyBoard()[52] == 0);
            REQUIRE(test.getmyBoard()[53] == 1);
            REQUIRE(test.getmyBoard()[54] == 0);
        }
        //check fail because already placed
        SECTION("Check fail because already placed"){
            REQUIRE(test.place("Sub", 13, 'R') == true);
            REQUIRE(test.getship("Sub").getpos().first == 13);
            REQUIRE(test.getship("Sub").getpos().second == 'R'); 
            REQUIRE(test.getship("Sub").gethealth() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.getmyBoard()[13] == 1);
            REQUIRE(test.getmyBoard()[14] == 1);
            REQUIRE(test.place("Sub", 7, 'L') == false);
            REQUIRE(test.getship("Sub").getpos().first == 13);
            REQUIRE(test.getship("Sub").getpos().second == 'R'); 
            REQUIRE(test.getship("Sub").gethealth() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.getmyBoard()[13] == 1);
            REQUIRE(test.getmyBoard()[14] == 1);
            REQUIRE(test.getmyBoard()[15] == 1);
        } 
        //check fail because bad position
        SECTION("Check fail bad place UP"){
            REQUIRE(test.place("Cruiser", 100, 'U') == false);
            REQUIRE(test.getship("Cruiser").getpos().first == -1);
            REQUIRE(test.getship("Carrier").getpos().second == 'N'); 
            REQUIRE(test.getship("Cruiser").gethealth() == 3);
            REQUIRE(test.getship("Cruiser").getsunk() == false);
        }
        //check fail because bad position
        SECTION("Check fail bad place DOWN"){
            REQUIRE(test.place("Cruiser", 99, 'D') == false);
            REQUIRE(test.getship("Cruiser").getpos().first == -1);
            REQUIRE(test.getship("Carrier").getpos().second == 'N'); 
            REQUIRE(test.getship("Cruiser").gethealth() == 3);
            REQUIRE(test.getship("Cruiser").getsunk() == false);
        }
        //check fail because bad position
        SECTION("Check fail bad place RIGHT"){
            REQUIRE(test.place("Cruiser", 9, 'R') == false);
            REQUIRE(test.getship("Cruiser").getpos().first == -1);
            REQUIRE(test.getship("Carrier").getpos().second == 'N'); 
            REQUIRE(test.getship("Cruiser").gethealth() == 3);
            REQUIRE(test.getship("Cruiser").getsunk() == false);
        }
        //check fail because bad position
        SECTION("Check fail bad place LEFT"){
            REQUIRE(test.place("Cruiser", 0, 'L') == false);
            REQUIRE(test.getship("Cruiser").getpos().first == -1);
            REQUIRE(test.getship("Carrier").getpos().second == 'N'); 
            REQUIRE(test.getship("Cruiser").gethealth() == 3);
            REQUIRE(test.getship("Cruiser").getsunk() == false);
        }
}
TEST_CASE("Testing takefire"){    
    board test;
        //check hit
        SECTION("Check hit"){
            test.place("Sub", 13, 'R');
            REQUIRE(test.takeFire(13) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 2);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.getmyBoard()[13] == 2);
        }
        //check miss
        SECTION("Check miss"){
            REQUIRE(test.takeFire(56) == 'M');
            REQUIRE(test.getmyBoard()[56] == -1);
        }
        //check bad shot
        SECTION("Check bad shot"){
            REQUIRE(test.takeFire(1000) == 'R');
            REQUIRE(test.takeFire(-1) == 'R');
            REQUIRE(test.takeFire(101) == 'R');
        }
        //check shoot same spot
        SECTION("Check same spot"){
            test.place("Sub", 13, 'R');
            REQUIRE(test.takeFire(13) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 2);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.takeFire(13) == 'R');
            REQUIRE(test.getmyBoard()[13] == 2);
            REQUIRE(test.getship("Sub").gethealth() == 2);
            REQUIRE(test.getship("Sub").getsunk() == false);
        }
        //check another shot
        SECTION("Check another hit, same ship"){
            test.place("Sub", 13, 'R');
            REQUIRE(test.takeFire(13) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 2);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.takeFire(14) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 1);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.getmyBoard()[14] == 2);
        }
        //check sink
        SECTION("Check sink"){
            test.place("Sub", 13, 'R');
            REQUIRE(test.takeFire(13) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 2);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.takeFire(14) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 1);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == false);
            REQUIRE(test.getmyBoard()[14] == 2);
            REQUIRE(test.takeFire(15) == 'H');
            REQUIRE(test.getship("Sub").gethealth() == 0);
            REQUIRE(test.getship("Sub").getsize() == 3);
            REQUIRE(test.getship("Sub").getsunk() == true);
            REQUIRE(test.getmyBoard()[15] == 2);
        }
}

