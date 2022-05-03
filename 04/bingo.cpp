#include "bingo.h"

using namespace std;
bingo::bingo(const vector<string>& input) : _board_vals(), _board_state(), _row_matches(), _clm_matches(), _match(false)
{
	int i = 0;
	for (const string& str : input)
	{
		stringstream ss(str);
		for (int j = 0; ss >> _board_vals[i][j]; ++j);
		++i;
	}
}

bool bingo::call(const int& callval)
{
	int y, x = 0;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 5; x++)
		{
			if (_board_vals[y][x] == callval)
			{
				_board_state[y][x] = true;
				_clm_matches[x]++;
				_row_matches[y]++;

				if (_clm_matches[x] == 5 || _row_matches[y] == 5)
				{
					_match = true;
				}
			}
		}
	}
	return _match;
}

int bingo::sum_unmatched()
{
	int sum = 0;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			sum += _board_vals[y][x] * !_board_state[y][x];
		}
	}
	return sum;
}

void bingo::reset()
{
	_match = false;
	fill_n(*_board_state, 25, 0);
	fill_n(_row_matches, 5, 0);
	fill_n(_clm_matches, 5, 0);
}

bool bingo::is_finished()
{
	return _match;
}
