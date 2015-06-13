#ifndef BOTTLE_H
#define BOTTLE_H
#include <SFML/Graphics.hpp>
#include "Rock.h"
#include "Board.h"

using namespace sf;

class Bottle
{
    public:
        Bottle(std::vector<Bottle*> &);
        virtual ~Bottle();
        virtual void draw(RenderWindow &);
        void newPosition(std::vector<Bottle*> &);
        bool zoneIsUsed(Bottle &otherBottle);
        bool checkCollision(Rock &, std::vector<Bottle*> &, Board &board);
        void updatePosition();
    protected:
        Vector2f position;
        IntRect getArea();
        IntRect getTheoricArea();
    private:
        void checkPosition(std::vector<Bottle*> &);
        void getRandomPosition();
        Vector2f theoricPosition;
        Vector2f speed;
        Vector2i theSize = Vector2i(50, 100);
        Sprite sprite;
        Texture texture;
        virtual void updateBoard(Board &board);
        int x;
        int y;
        int ropeLeng;
};

#endif // BOTTLE_H
