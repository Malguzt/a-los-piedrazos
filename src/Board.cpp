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

    rockTexture.loadFromFile("img/small_rock.png");
    rockSprite.setTexture(rockTexture);
    rockSprite.setTextureRect(IntRect(0, 0, 32, 32));
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


    for(int i= 0; i < shoots; ++i)
    {
        rockSprite.setPosition(Vector2f(300 + i * 30, 10));
        app.draw(rockSprite);
    }
}

void Board::lostAShoot()
{
    if(shoots > 0)
    {
        --shoots;
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

int Board::getShoots()
{
    return shoots;
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
