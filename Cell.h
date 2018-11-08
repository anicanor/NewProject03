//Aaron Nicanor

#ifndef CELL_
#define CELL_

class Cell
{
        private:
                bool isWall,
                     isGoal,
                     beenVisited,
                     isPath;

        public:
                Cell();
                void setIsWall( bool state );
                void setVisited( bool state );
                void setIsGoal( bool state );
                void setIsPath( bool state );
                bool getIsGoal();
                bool getIsPath();
                bool getIsWall();
                bool getBeenVisited();
};

#endif
