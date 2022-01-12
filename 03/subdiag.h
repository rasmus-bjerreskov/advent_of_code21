#pragma once
#include <bitset>
#include <vector>
class subdiag
{
public:
	subdiag(std::vector<std::bitset<12>> v);
	int delta() const;
	int epsilon() const;

private:
	void calc_delta();
	void calc_epsilon();
	void calc_o_genrate();
	void calc_co2_genrate();
	std::vector<std::bitset<12>> _input;
	std::vector<int> _bitfreq; //count of 1s in each bit position
	const int _half_length;
	std::bitset<12> _delta;
	std::bitset<12> _epsilon;
	std::bitset<12> _o_genrate;
	std::bitset<12> _co2_genrate;

};

