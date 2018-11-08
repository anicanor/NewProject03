//Aaron Nicanor

#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
#include<string>

#include"Cell.h"
#include"Maze.h"
#include"Direction.h"
#include"Location.h"

using namespace std;

vector<string> split( const string& s , char delimiter )
{
   vector<string> tokens;         // vector of tokens
   string token;                  // a single token
   istringstream tokenStream(s);  // an input string stream
   
   while( getline( tokenStream , token , delimiter ) )
        tokens.push_back(token);    // add found token

   return tokens;
}

int main()
{
    stack<Location> pathHolder; //saves a stack of locations. Will be used to map out the correct path
    Location cur, step; //Makes two locations cur and step. cur is the current location, and step is the spot location would end up next
    bool atGoal = false;
    int count = 1;
    string blank; //will take in an input from the user to make sure they're still inputing
    
    //each loop will solve for one maze at a time. After each maze, count will increase
    while(cin >> blank)
    {
        //Will fill up the maze by creating a vector of each line ten times. It will then convert each vector into the maze each time
        Maze myMaze;
        for( int y = 0; y < 10; y++ )
        {
            string input;
            char delimiter = ' ';

            getline( cin, input );
            vector<string> listOfTokens = split( input , delimiter );

            myMaze.fill( listOfTokens, y ); //fills in row y with the given vector of tokens
        }
    
        //Handles the navigation of the maze and will determine the path to the goal.
        pathHolder.push( myMaze.getStart() );
        while( !pathHolder.empty() && !atGoal)
        {
                cur = pathHolder.pop();
                do
                {
                        step = cur.Go();
                        if( myMaze.isGoal( step ) )
                        {
                                pathHolder.push(step);
                                atGoal = true;
                        }
                        else if( myMaze.isValid( step ) )
                        {
                                myMaze.setIsVisited( step );
                                cur.Turn();
                                pathHolder.push( cur );
                                cur = step;
                        }
                }
                while( cur.Turn() );
        }
    
        //Prints out the maze. Will note if it was correct or not
        if( atGoal == true )
        {
                cout << "Maze " << count << ": Solution found" << endl;

                //Will mark the certain cells in the maze as the path taken to the goal
                while( !pathHolder.empty() )
                    myMaze.path( pathHolder.pop() );

                myMaze.print();
        }
        else
        {
                cout << "Maze " << count << ": No solution" << endl;
                myMaze.print();
        }
        count++;
    }

    return 0;
}

