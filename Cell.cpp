//Aaron Nicanor
//anicanor

#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell()
{
        isWall = false;
        isGoal = false;
        isPath = false;
        beenVisited = false;
}

//Sets the cell as a wall or as not a wall
void Cell::setIsWall( bool state )
{
        isWall = state;
}

//Sets the cell as visited or not visited
void Cell::setVisited( bool state )
{
        beenVisited = state;
}

//Sets the cell as a goal or as not a goal
void Cell::setIsGoal( bool state )
{
        isGoal = state;
}

//Sets the cell as the correct path
void Cell::setIsPath( bool state )
{
        isPath = state;
}

//returns if the cell is a wall
bool Cell::getIsWall()
{
        return isWall;
}

//returns if the cell is a goal
bool Cell::getIsGoal()
{
        return isGoal;
}

//returns if the cell is the correct path
bool Cell::getIsPath()
{
        return isPath;
}

//returns if the cell has been visited already
bool Cell::getBeenVisited()
{
        return beenVisited;
}
