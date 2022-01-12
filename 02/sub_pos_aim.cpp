#include "sub_pos_aim.h"

sub_pos_aim::sub_pos_aim() : sub_pos(), _aim(0)
{
}

void sub_pos_aim::move(command cmd, int val)
{
	switch (cmd)
	{
    case command::mov_fwd:
        _forward += val;
        _depth += val * _aim;
        break;

    case command::mov_up:
        _aim -= val;
        break;

    case command::mov_down:
        _aim += val;
        break;

    default:
        break;
	}
}
