#include "sub_pos.h"
using namespace std;

sub_pos::sub_pos() : _forward(0), _depth(0), _cmd(command::mov_fwd)
{
}

void sub_pos::parse_cmd(const string& input)
{
    stringstream ss;
    string cmd;
    int val;
    ss << input;
    ss >> cmd >> val;

    if (cmd == "forward")
        move(command::mov_fwd, val);
    else if (cmd == "down")
        move(command::mov_down, val);
    else if (cmd == "up")
        move(command::mov_up, val);
}

void sub_pos::move(command cmd, int val)
{
    switch (cmd)
    {
    case command::mov_fwd:
        _forward += val;
        break;

    case command::mov_up:
        _depth -= val;
        break;

    case command::mov_down:
        _depth += val;
        break;

    default:
        break;
    }
}

int sub_pos::forward()
{
    return _forward;
}

int sub_pos::depth()
{
    return _depth;
}
