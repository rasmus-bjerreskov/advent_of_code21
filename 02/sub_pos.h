#pragma once
#include <string>
#include <sstream>
#include <iostream>
class sub_pos
{
public:
	enum class command {mov_fwd, mov_up, mov_down};

	sub_pos();
	void parse_cmd(const std::string& s);
	int forward();
	int depth();

protected:
	void virtual move(command cmd, int val);
	command _cmd;
	int _forward;
	int _depth;
};

