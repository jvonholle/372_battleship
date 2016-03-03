all: ascii

#Tests
btest: tests/boardtest.cpp
	g++ -std=c++11 tests/boardtest.cpp src/bsboard.cpp src/bsboard.h
ptest: tests/printtest.cpp
	g++ -std=c++11 tests/printtest.cpp src/bsboard.cpp src/bsboard.h

#Playable versions
sdl: scr/main_sdl.cpp
	g++ -std=c++11 src/main_sdl.cpp src/bsboard.cpp src/bsboard.h -lSDL2 -lSDL2_image
ascii: src/main_ascii.cpp
	g++ -std=c++11 src/main_ascii.cpp src/bsboard.cpp src/bsboard.h
