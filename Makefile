all: sdl

test: test.cpp
	g++ -std=c++11 test.cpp bsboard.cpp bsboard.h

sdl: main_sdl.cpp
	g++ -std=c++11 main_sdl.cpp bsboard.cpp bsboard.h -lSDL2 -lSDL2_image

ascii: main_ascii.cpp
	g++ -std=c++11 main_ascii.cpp bsboard.cpp bsboard.h
