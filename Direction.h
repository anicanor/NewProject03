//Aaron Nicanor

#ifndef DIRECTION_
#define DIRECTION_

class Direction
{
        private:
                char dir;
                bool checkAll;

        public:
                Direction();
                char get() const;
                bool change();
};

#endif
