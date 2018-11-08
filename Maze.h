//Aaron Nicanor

#ifndef MAZE_
#define MAZE_

#include<iostream>
#include<vector>
#include<string>

#include"Location.h"
#include"Cell.h"

using namespace std;

class Maze
{
        private:
                Cell maze[10][10];
                int row,
                    col;
                Location start;

        public:
                Maze();
                Location getStart();
                bool isValid( Location loc );
                bool isGoal( Location loc );
                bool isVisited( Location loc );
                void setIsVisited( Location loc );
                void fill( vector<string> maze, int y );
                void path( Location loc );
                void print();
};

#endif
