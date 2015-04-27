#include "Game.h"

Game::Game()
{
    pWnd = new RenderWindow(VideoMode(800, 600), "Shoot the bottles");
    pWnd->setFramerateLimit(6);
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
    }
}

void Game::processCollisions()
{
}

void Game::updateGame()
{
    theRock.update();
}

void Game::drawGame()
{
    theRock.draw(*pWnd);
}
