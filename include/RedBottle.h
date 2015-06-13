#ifndef REDBOTTLE_H
#define REDBOTTLE_H

#include <Bottle.h>


class RedBottle : public Bottle
{
    public:
        RedBottle(std::vector<Bottle*> &bottles);
        virtual ~RedBottle();
    protected:
    private:
        virtual void updateBoard(Board &board);
};

#endif // REDBOTTLE_H
