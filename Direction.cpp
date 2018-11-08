//Aaron Nicanor

#include<iostream>
#include"Direction.h"

using namespace std;

Direction::Direction()
{
        dir = 'N'; //defaults the direction to be north
        checkAll = true; //if all the directions were checked, then it'll be false
}

//returns the current direction
char Direction::get() const
{
        return dir;
}

//will change the direction clockwise. If it's west, then all directions would've been checked, and it'll return false.
bool Direction::change()
{
    if( dir == 'W' )
            checkAll = false;
    else
    {
            if( dir == 'N' )
                    dir = 'E';
            else if( dir == 'E' )
                    dir = 'S';
            else
                    dir = 'W';
    }
    return checkAll;
}
