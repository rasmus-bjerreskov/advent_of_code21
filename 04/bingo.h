#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class bingo
{
public:
	bingo(const std::vector<std::string>& input);
	bool call(const int&);
	int sum_unmatched();
	void reset();
	bool is_finished();

private:
	int _board_vals[5][5];
	bool _board_state[5][5];
	int _row_matches[5];
	int _clm_matches[5];
	bool _match;
};