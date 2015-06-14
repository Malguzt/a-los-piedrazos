#include "Game.h"

Game::Game()
{
    backgroundTexture.loadFromFile("img/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    pWnd = new RenderWindow(VideoMode(1200, 768), "Shoot the bottles", Style::Fullscreen);
    pWnd->setFramerateLimit(60);
    createBottles();
}

Game::~Game()
{
    delete pWnd;
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

        pWnd->clear();
        if(board.getShoots() > 0)
        {
            processCollisions();
            updateGame();
            drawGame();
        } else {
            board.drawTheEnd(*pWnd);
        }
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
    for (std::vector<Bottle*>::iterator it = bottles.begin(); it != bottles.end(); ++it)
    {
        (*it)->checkCollision(theRock, bottles, board);
    }
}

void Game::processKey(int keyCode)
{
    if(Keyboard::isKeyPressed(Keyboard::Right)) theRock.changeRadius(2);
    if(Keyboard::isKeyPressed(Keyboard::Left)) theRock.changeRadius(-2);
    if(Keyboard::isKeyPressed(Keyboard::Up)) theRock.changeSpeed(2);
    if(Keyboard::isKeyPressed(Keyboard::Down)) theRock.changeSpeed(-2);

    switch(keyCode)
    {
        case Keyboard::Escape:
            pWnd->close();
            break;
        case Keyboard::Space:
            theRock.shoot();
            break;
    }
}

void Game::updateGame()
{
    theRock.update();
    for (std::vector<Bottle*>::iterator it = bottles.begin(); it != bottles.end(); ++it)
    {
        (*it)->updatePosition();
        (*it)->setSize(board.getBottlesSize());
    }
    if(!theRock.inTheScene(*pWnd))
    {
        board.lostAShoot();
        theRock.newShoot();
    }
}

void Game::drawGame()
{
    pWnd->draw(backgroundSprite);
    theRock.draw(*pWnd);
    for (std::vector<Bottle*>::iterator it = bottles.begin(); it != bottles.end(); ++it)
    {
        (*it)->draw(*pWnd);
    }
    board.draw(*pWnd);
}

void Game::createBottles()
{
    for(int i = 0; i < numberOfBottles; ++i)
    {
        switch(i) {
         case 0:
            bottles.push_back(new RedBottle(bottles));
            break;
         case 1:
            bottles.push_back(new GreenBottle(bottles));
            break;
         case 2:
         case 3:
            bottles.push_back(new RockBottle(bottles));
            break;
         default:
            bottles.push_back(new Bottle(bottles));
            break;
        }
    }
}
