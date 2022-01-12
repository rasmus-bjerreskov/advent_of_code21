#include "freader.h"

using namespace std;

freader::freader() : _fname("input.txt")
{
}

freader::freader(string fname) : _fname(fname)
{
}

freader::operator vector<int>()
{
	vector<int> tmp;
	ifstream infile;

	infile.open(_fname);
	istream_iterator<int> ifit(infile);

	copy(ifit, istream_iterator<int>(), back_inserter(tmp));

	return tmp;
}
