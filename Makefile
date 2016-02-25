all: sdl

test: tests/test.cpp
	g++ -std=c++11 tests/test.cpp src/bsboard.cpp src/bsboard.h

sdl: scr/main_sdl.cpp
	g++ -std=c++11 src/main_sdl.cpp src/bsboard.cpp src/bsboard.h -lSDL2 -lSDL2_image

ascii: src/main_ascii.cpp
	g++ -std=c++11 src/main_ascii.cpp src/bsboard.cpp src/bsboard.h
