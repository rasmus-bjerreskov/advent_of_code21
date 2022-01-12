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
}

int subdiag::delta() const
{
	return _delta.to_ulong();
}

int subdiag::epsilon() const
{
	return _epsilon.to_ulong();
}

void subdiag::calc_delta()
{
	for (int i = 0; i < _bitfreq.size(); ++i)
	{
		_delta.set(i, _bitfreq[i] > _half_length);
	}
}

void subdiag::calc_epsilon()
{
	_epsilon = ~_delta;
}

void subdiag::calc_o_genrate()
{

}
