#pragma once
#include "sub_pos.h"
class sub_pos_aim :
    public sub_pos
{
public:
    sub_pos_aim();
    
    
private:
    void move(command cmd, int val);
    int _aim;
};

