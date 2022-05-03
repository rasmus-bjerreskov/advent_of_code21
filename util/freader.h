#pragma once

/**
* File reader template
* Used to construct a vector of objects from a text file of line-separated values
* Undefined behaviour if lines contain whitespace other than line break and used on T other than std::string
* 
*/

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>

template<class T>
class freader
{
public:
	freader(std::string fname = "input.txt");
	operator std::vector<T>();

private:
	const std::string _fname;
};

template<class T>
freader<T>::freader(std::string fname) : _fname(fname)
{
}

template<class T>
freader<T>::operator std::vector<T>()
{
	std::vector<T> tmp;
	std::ifstream infile;
	infile.open(_fname);
	
	//strings require special handling because of streams treating any whitespace as delimiter
	//constexpr to choose at compile time
	if constexpr (std::is_same<T, std::string>::value)
	{
		std::string str;
		while (getline(infile, str))
		{
			tmp.push_back(str);
		}
	}
	else
	{ 
		std::istream_iterator<T> ifit(infile);	
		std::copy(ifit, std::istream_iterator<T>(), std::back_inserter(tmp));
	}
	return tmp; //vector has move constructor, does not return copy (stop looking this up)
}
