//Aaron Nicanor

#include<iostream>
#include<string>
#include<vector>

#include"Maze.h"
#include"Direction.h"
#include"Location.h"
#include"Cell.h"

using namespace std;

const int ZERO = 0;

Maze::Maze()
{
    row = 10;
    col = 10;
}

Location Maze::getStart()
{
        return start;
}

//Checks if the cell is ok to move into
bool Maze::isValid( Location loc )
{
        bool check = false;
        if( loc.inBounds( ZERO, row, ZERO, col ) )
        {
                int x = loc.getRow();
                int y = loc.getCol();
                if( maze[x][y].getIsWall() == false || maze[x][y].getBeenVisited() == false )
                        check = true;
        }
        return check;
}

//Checks if the cell is the goal
bool Maze::isGoal( Location loc )
{
        if( loc.inBounds(ZERO, row, ZERO, col) )
        {
                int x = loc.getRow();
                int y = loc.getCol();               
                return maze[x][y].getIsGoal();
        }
        return false;
}

//Checks if the cell has been visited
bool Maze::isVisited( Location loc )
{
        int x = loc.getRow();
        int y = loc.getCol();
        return maze[x][y].getBeenVisited();
}

//Sets the given cell as visited
void Maze::setIsVisited( Location loc )
{
        int x = loc.getRow();
        int y = loc.getCol();
        bool state = true;
        maze[x][y].setVisited( state );
}

//Fills the array with the user's input
void Maze::fill( vector<string> myMaze, int y )
{
        bool state = true;
        Direction north;
        for(unsigned x = 0; x < myMaze.size(); x++)
        {
            
            if( myMaze[x] == "1" )
                maze[x][y].setIsWall( state );
            else if( myMaze[x] == "S" )
                start = Location(x, y, north); //will remember the starting location
            else if( myMaze[x] == "G" )
                maze[x][y].setIsGoal( state );
        }
}

//Will mark the correct path
void Maze::path( Location loc )
{
        int x = loc.getRow();
        int y = loc.getCol();
        bool state = true;
        maze[x][y].setIsPath(state);
}

//Prints out the finished path
void Maze::print()
{
        int startX, startY;
        startX = start.getRow();
        startY = start.getCol();
        //cycles through the 2d array for each cell
        for( int y = 0; y < col; y++)
        {
                for( int x = 0; x < row; x++)
                {
                        //Will check each cell on what type of symbol it would be represented as. Will print the symbol out
                        if( maze[x][y].getIsWall() )
                                cout << "1 ";
                        else if(x == startX && y == startY)
                                cout << "S ";
                        else if( maze[x][y].getIsGoal() )
                                cout << "G ";
                        else if( maze[x][y].getIsPath() )
                                cout << "* ";
                        else
                                cout << "0 ";
                }
                cout << endl;
        }
}
