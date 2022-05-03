#pragma once
#include <bitset>
#include <vector>
#include <list>
class subdiag
{
public:
	subdiag(std::vector<std::bitset<12>> v);
	int gamma() const;
	int epsilon() const;
	int o2_rate() const;
	int co2_rate() const;

private:
	void calc_gamma();
	void calc_epsilon();
	unsigned long calc_air_qual(bool(*bit_to_keep)(int bit_count, int size));
	std::vector<std::bitset<12>> _input;
	std::vector<int> _bitfreq; //count of 1s in each bit position
	const int _half_length;
	std::bitset<12> _gamma;
	std::bitset<12> _epsilon;
	std::bitset<12> _o2_genrate;
	std::bitset<12> _co2_genrate;

};

