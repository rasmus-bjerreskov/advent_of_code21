#include <bitset>
#include <vector>
#include <iostream>
#include "freader.h"
#include "subdiag.h"

using namespace std;
int main()
{
	subdiag sub(vector<bitset<12>>(freader<bitset<12>>("input.txt")));
	
	cout << "Power consumption: " << sub.gamma() * sub.epsilon() << endl;
	cout << "Product of O2 and CO2 rate: " << sub.o2_rate() * sub.co2_rate() << endl;
	return 0;
}