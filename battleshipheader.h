#pragma once

#include <vector>
#include <iostream>

using namespace std;


//board is 10 by 10
#ifndef BATTLESHIP_H_INCLUDED
#define BATTLESHIP_H_INCLUDED


class board
{
	public:
		board()
		{
			for (int i = 0; i < 100; ++i)
				board_.push_back(0);
		}
		int board_size()
		{
			return board_.size();
		}
		void printGhettoBoard();

	private:
		vector<int> board_;
		bool turn;
};





void createboard()
{
	vector<bool> board[100];
}


void printGhettoBoard()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "cat ";
		}
		cout << endl;
	}
}


#endif