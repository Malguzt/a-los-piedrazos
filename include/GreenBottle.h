#ifndef GREENBOTTLE_H
#define GREENBOTTLE_H

#include <Bottle.h>


class GreenBottle : public Bottle
{
    public:
        GreenBottle(std::vector<Bottle*> &bottles);
        virtual ~GreenBottle();
    protected:
    private:
        virtual void updateBoard(Board &board);
};

#endif // GREENBOTTLE_H
