#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "freader.h"
#include "sub_pos.h"
#include "sub_pos_aim.h"
using namespace std;

int main()
{
	vector<string> input(freader<string>("input.txt"));
	vector<string> test = { "forward 5",
		"down 5",
		"forward 8",
		"up 3",
		"down 8",
		"forward 2" };

	sub_pos sub;
	sub_pos_aim sub2;
	
	for (auto& s : input)
	{
		sub.parse_cmd(s);
		sub2.parse_cmd(s);
	}
	
	cout << "Depth * distance: " << sub.depth() * sub.forward() << endl;
	cout << "Depth * aim: " << sub2.depth() * sub2.forward() << endl;
	return 0;
}