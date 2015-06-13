#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Board
{
    public:
        Board();
        virtual ~Board();
        void draw(RenderWindow &app);
        void drawTheEnd(RenderWindow &app);
        void lostAShoot();
        void addShoots(int shoots);
        void addPoints(int points);
        int getShoots();
    protected:
    private:
        Texture rockTexture;
        Sprite rockSprite;
        Font font;
        Text text;
        int shoots = 3;
        int points = 0;
};

#endif // BOARD_H
