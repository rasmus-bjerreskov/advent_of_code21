#include "sub_pos.h"
using namespace std;

sub_pos::sub_pos() : _forward(0), _depth(0), _cmd(mov_fwd)
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
        move(mov_fwd, val);
    else if (cmd == "down")
        move(mov_down, val);
    else if (cmd == "up")
        move(mov_up, val);
}

void sub_pos::move(command cmd, int val)
{
    switch (cmd)
    {
    case mov_fwd:
        _forward += val;
        break;

    case mov_up:
        _depth -= val;
        break;

    case mov_down:
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
