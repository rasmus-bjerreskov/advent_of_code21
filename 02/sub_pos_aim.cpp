#include "sub_pos_aim.h"

sub_pos_aim::sub_pos_aim() : sub_pos(), _aim(0)
{
}

void sub_pos_aim::move(command cmd, int val)
{
	switch (cmd)
	{
    case mov_fwd:
        _forward += val;
        _depth += val * _aim;
        break;

    case mov_up:
        _aim -= val;
        break;

    case mov_down:
        _aim += val;
        break;

    default:
        break;
	}
}
