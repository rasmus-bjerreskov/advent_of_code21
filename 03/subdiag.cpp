#include "subdiag.h"

using namespace std;

subdiag::subdiag(vector<bitset<12>> v) : _input(v), _bitfreq(12, 0), _half_length(v.size() / 2)
{
	for (auto& n : _input)
	{
		for (int i = 0; i < n.size(); ++i)
		{
			_bitfreq[i] += n.test(i);
		}
	}
	calc_gamma();
	calc_epsilon();
	_o2_genrate = calc_air_qual([](int bit_count, int size) { return bit_count >= (size + 1) / 2; });
	_co2_genrate = calc_air_qual([](int bit_count, int size) { return bit_count < (size + 1) / 2; });
}

void subdiag::calc_gamma()
{
	for (int i = 0; i < _bitfreq.size(); ++i)
	{
		_gamma.set(i, _bitfreq[i] > _half_length);
	}
}

void subdiag::calc_epsilon()
{
	_epsilon = ~_gamma;
}

unsigned long subdiag::calc_air_qual(bool(*bit_to_keep)(int bit_count, int size))
{
	list <bitset<12>> o_list(_input.begin(), _input.end());

	//start with MSB then move right each pass
	//each pass, keep items with most common bit. Keep values with 1s in bit position if tie
	//Recalculate most common bit on each pass
	bool keep_bit = bit_to_keep(_bitfreq[_bitfreq.size() - 1], _half_length);
	int n = _bitfreq.size() - 1; //bit to test
	auto rmv_lambda = [&](auto bits) 
	{ 
		return bits.test(n) != keep_bit; 
	};

	//first pass, the bit frequency is already known
	o_list.remove_if(rmv_lambda);

	for (n = _bitfreq.size() - 2; n >= 0 && o_list.size() > 1; --n)
	{
		int tmp_bit_freq = 0;
		for (auto &i : o_list)
		{
			tmp_bit_freq += i.test(n);
		}
		keep_bit = bit_to_keep(tmp_bit_freq, o_list.size());
		o_list.remove_if(rmv_lambda);
	}
	
	return o_list.front().to_ulong();
}

int subdiag::gamma() const
{
	return _gamma.to_ulong();
}

int subdiag::epsilon() const
{
	return _epsilon.to_ulong();
}

int subdiag::o2_rate() const
{
	return _o2_genrate.to_ulong();
}

int subdiag::co2_rate() const
{
	return _co2_genrate.to_ulong();
}