//Aaron Nicanor

#ifndef LOCATION_
#define LOCATION_

#include"Direction.h"

class Location
{
        private:
                int row,
                    col;
                Direction dir;

        public:
                Location();
                Location( int r, int c, Direction d );
                void set( int r, int c );
                void setRow( int r );
                void setCol( int c );
                void setDir( Direction d );
                int getRow() const;
                int getCol() const;
                Direction getDir() const;
                bool inBounds( int lx, int ux, int ly, int uy ) const;
                Location Go() const;
                bool Turn();

                friend bool operator==( const Location& a , const Location& b );
                friend bool operator!=( const Location& a , const Location& b );
};

#endif
