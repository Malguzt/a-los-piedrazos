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
        void lostALive();
        void addPoints(int points);
        int getLives();
    protected:
    private:
        Texture okTexture;
        Texture koTexture;
        Font font;
        Text text;
        int lives = 3;
        const int maxLives = 3;
        int points = 0;
        Sprite hearts[3];
};

#endif // BOARD_H
