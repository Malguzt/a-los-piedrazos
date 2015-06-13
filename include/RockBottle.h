#ifndef ROCKBOTTLE_H
#define ROCKBOTTLE_H

#include <Bottle.h>


class RockBottle : public Bottle
{
    public:
        RockBottle(std::vector<Bottle*> &bottles);
        virtual ~RockBottle();
        virtual void draw(RenderWindow &);
    protected:
    private:
        Texture rockTexture;
        Sprite rockSprite;
        virtual void updateBoard(Board &board);
};

#endif // ROCKBOTTLE_H
