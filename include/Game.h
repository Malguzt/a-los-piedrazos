#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Rock.h"

using namespace sf;
using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();
        void Go();
    private:
        RenderWindow *pWnd;
        Rock theRock;
        void processEvent(Event &evt);
        void drawGame();
        void updateGame();
        void processCollisions();
        void processKey(int keyCode);
};

#endif // GAME_H
