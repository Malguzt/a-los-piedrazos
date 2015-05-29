#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Rock.h"
#include "Bottle.h"

using namespace sf;
using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();
        void Go();
        void createBottles();
    private:
        RenderWindow *pWnd;
        Rock theRock;
        std::vector<Bottle*> bottles;
        void processEvent(Event &evt);
        void drawGame();
        void updateGame();
        void processCollisions();
        void processKey(int keyCode);
        int numberOfBottles = 5;
        Texture backgroundTexture;
        Sprite backgroundSprite;
};

#endif // GAME_H
