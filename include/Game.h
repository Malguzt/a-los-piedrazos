#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Rock.h"
#include "Bottle.h"
#include "RockBottle.h"
#include "GreenBottle.h"
#include "RedBottle.h"
#include "Board.h"

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
        int numberOfBottles = 10;
        Texture backgroundTexture;
        Sprite backgroundSprite;
        Board board;
};

#endif // GAME_H
