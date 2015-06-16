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
        int getBottlesSize();
        void increaseBottles();
        void decreaseBottles();
        void checkClick(Vector2i, RenderWindow &app);
    protected:
    private:
        bool showHelp = false;
        Texture rockTexture;
        Sprite rockSprite;
        Texture helpTexture;
        Sprite helpSprite;
        Font font;
        Text text;
        int shoots = 30;
        int maxShoots = 30;
        int points = 0;
        int bottlesSize = 5;
        void drawText(RenderWindow &app);
        void drawRocks(RenderWindow &app);
        void drawHelp(RenderWindow &app);
};

#endif // BOARD_H
