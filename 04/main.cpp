#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <array>

#include "bingo.h"

using namespace std;

int main()
{
	ifstream finput;
	finput.open("input.txt");

	string raw_csv; //raw csv of drawn numbers
	getline(finput, raw_csv); 
	string tmp;
	vector<int> num_draw;
	istringstream csv_ss(raw_csv);
	while (getline(csv_ss, tmp, ','))
	{
		num_draw.push_back(stoi(tmp));
	}

	vector<string> board_str;
	vector<bingo> boards;
	while (getline(finput, tmp))
	{
		if (tmp.length() != 0)
		{
			board_str.push_back(move(tmp));
			tmp.clear(); //satisfying VSC complaining about using a moved container

			if (board_str.size() == 5)
			{
				boards.push_back(bingo(board_str));
				board_str.clear();
			}
		}
	}
	
	for (auto& i : num_draw)
	{
		for (auto& board : boards)
		{
			if (!board.is_finished() && board.call(i))
			{
				cout << "Solution: " << board.sum_unmatched() * i << endl;
			}
		}
	}


	return 0;
}