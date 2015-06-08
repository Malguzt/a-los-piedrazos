#include <string>
#include "Board.h"
#include <sstream>
using namespace sf;

Board::Board()
{
    font.loadFromFile("sixty.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setColor(Color::Green);
    text.setPosition(10, 10);

    okTexture.loadFromFile("img/ok.png");
    koTexture.loadFromFile("img/ko.png");

    for(int i = 0; i < maxLives; ++i)
    {
        hearts[i].setTexture(okTexture);
        hearts[i].setPosition(660 + i * 38, 10);
    }
}

Board::~Board()
{
}

void Board::draw(RenderWindow &app)
{
    std::ostringstream sPoints;
    sPoints << points;

    text.setString("Puntos: " +  sPoints.str());

    app.draw(text);

    for(int i= 0; i < maxLives; ++i)
    {
        app.draw(hearts[i]);
    }
}

void Board::lostALive()
{
    if(lives > 0)
    {
        --lives;
    }

    for(int i = 0; i < maxLives; ++i)
    {
        if(i < lives)
        {
            hearts[i].setTexture(okTexture);
        } else {
            hearts[i].setTexture(koTexture);
        }
    }
}

void Board::addPoints(int newPoints)
{
    points += newPoints;

    if(points < 0)
    {
        points = 0;
    }
}

int Board::getLives()
{
    return lives;
}

void Board::drawTheEnd(RenderWindow &app)
{
    std::ostringstream sPoints;
    sPoints << points;

    text.setCharacterSize(50);
    text.setPosition(10, 100);
    text.setString("Perdiste\n Total de puntos: " +  sPoints.str());

    app.draw(text);
}
