#include <bitset>
#include <vector>
#include <iostream>
#include "freader.h"
#include "subdiag.h"

using namespace std;
int main()
{
	subdiag sub(vector<bitset<12>>(freader<bitset<12>>("input.txt")));

	cout << "Power consumption: " << sub.delta() * sub.epsilon() << endl;
	return 0;
}