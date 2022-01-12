#include <iostream>
#include <vector>
#include <algorithm>
#include "freader.h"
using namespace std;

void ex1_1(vector<int>& v);
void ex1_2(vector<int>& v);

int main() {
	vector<int> input(freader<int>("input.txt"));
	ex1_1(input);
	ex1_2(input);

	return 0;
}

void ex1_1(vector<int>& v)
{
	int last = 0, count = 0;

	for_each(v.begin(), v.end(), [&](int& n) {
		if (n > last)
			++count;
		last = n;
		});
	//accounting for there being no measurement before first value
	--count;

	cout << "Times increased: " << count << endl;
}

void ex1_2(vector<int>& v)
{
	int rolling_sum = 0, last_sum = 0, count = 0, i;

	for_each(v.begin(), v.begin() + 3, [&](int& n) {rolling_sum += n; });
	last_sum = rolling_sum;
	i = 3;
	for_each(v.begin() + 3, v.end(), [&](int& n)
		{
			rolling_sum += n - v[i++ - 3];
			if (rolling_sum > last_sum)
				++count;
			last_sum = rolling_sum;
		});

	cout << "Times increased with rolling sum: " << count << endl;
}