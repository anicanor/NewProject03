//Aaron Nicanor

#include <iostream>

#include "Direction.h"
#include "Location.h"

using namespace std;

Location::Location()
{
        row = 0;
        col = 0;
}

Location::Location( int r, int c, Direction d )
{
        row = r;
        col = c;
        dir = d;
}

//sets the row and col of the Location
void Location::set( int r, int c )
{
        row = r;
        col = c;
}

void Location::setRow( int r )
{
        row = r;
}

void Location::setCol( int c )
{
        col = c;
}

void Location::setDir( Direction d )
{
        dir = d;
}

int Location::getRow() const
{
        return row;
}

int Location::getCol() const
{
        return col;
}

Direction Location::getDir() const
{
        return dir;
}

//Checks if the given location if within bounds
bool Location::inBounds( int lx, int ux, int ly, int uy ) const
{
        bool result = true;
        if ( lx > row || ux < row )
                result = false;
        if ( ly > col || uy < col )
                result = false;
        return result;
}

//returns a location. Will be used for the step location in the aMazing.cpp file
Location Location::Go() const
{
        Location step;
        if ( dir.get() == 'N' )
        {
                step.set( row, col - 1 );
                return step;
        }
        else if ( dir.get() == 'E' )
        {
                step.set( row + 1, col );
                return step;
        }
        else if ( dir.get() == 'S' )
        {
                step.set( row,  col - 1 );
                return step;
        }
        else
        {
                step.set( row - 1, col );
                return step;
        }
}

//will change the location clockwise. If all the locations were checked, then it'll return false
bool Location::Turn()
{
        return dir.change();
}
