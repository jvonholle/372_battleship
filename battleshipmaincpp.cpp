#include <vector>
#include <iostream>
#include "battleshipheader.h"

using namespace std;

int main()
{
	//test 1 pullboard for player1
		board player1;
		if (player1.board_size() == 100)
			cout << "hunned" << endl;
		char exit = 'b';
		while (exit != 'x')
		{
			cin >> exit;
		}



	//Future tests
	//Place ships


	return 0;
}