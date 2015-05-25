#ifndef BOTTLE_H
#define BOTTLE_H
#include <SFML/Graphics.hpp>
#include "Rock.h"

using namespace sf;

class Bottle
{
    public:
        Bottle(std::vector<Bottle*> &);
        virtual ~Bottle();
        void draw(RenderWindow &);
        void newPosition(std::vector<Bottle*> &);
        bool zoneIsUsed(Bottle &otherBottle);
        bool checkCollision(Rock &, std::vector<Bottle*> &);
    protected:
    private:
        void checkPosition(std::vector<Bottle*> &);
        void getRandomPosition();
        Vector2f position;
        Vector2i theSize = Vector2i(50, 100);
        Sprite sprite;
        Texture texture;
        IntRect getArea();
        int x;
        int y;
};

#endif // BOTTLE_H
