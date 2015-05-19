#include "Game.h"

Game::Game()
{
    pWnd = new RenderWindow(VideoMode(800, 600), "Shoot the bottles");
    pWnd->setFramerateLimit(60);
}

Game::~Game()
{
    //dtor
}

void Game::Go()
{
    Event evt;

    while(pWnd->isOpen())
    {
        while (pWnd->pollEvent(evt))
        {
            processEvent(evt);
        }

        processCollisions();
        updateGame();
        pWnd->clear();
        drawGame();
        pWnd->display();
    }
}

void Game::processEvent(Event &evt)
{
    switch (evt.type)
    {
        case Event::Closed:
            pWnd->close();
            break;
        case Event::KeyPressed:
            processKey(evt.key.code);
            break;
    }
}

void Game::processCollisions()
{
}

void Game::processKey(int keyCode)
{
    switch(keyCode)
    {
        case Keyboard::Right:
            theRock.changeRadius(2);
            break;
        case Keyboard::Left:
            theRock.changeRadius(-2);
            break;
        case Keyboard::Up:
            theRock.changeSpeed(2);
            break;
        case Keyboard::Down:
            theRock.changeSpeed(-2);
            break;
        case Keyboard::Space:
            theRock.shoot();
            break;
    }
}

void Game::updateGame()
{
    theRock.update();
    if(!theRock.inTheScene(800, 600))
    {
        theRock.newShoot();
    }
}

void Game::drawGame()
{
    theRock.draw(*pWnd);
}
