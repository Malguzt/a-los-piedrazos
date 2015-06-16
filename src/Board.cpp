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

    rockTexture.loadFromFile("img/small_rock.png");
    rockSprite.setTexture(rockTexture);
    rockSprite.setTextureRect(IntRect(0, 0, 32, 32));

    helpTexture.loadFromFile("img/help.png");
    helpSprite.setTexture(helpTexture);
    helpSprite.setPosition(Vector2f(0, -750));

}

Board::~Board()
{
}

void Board::checkClick(Vector2i clickPosition, RenderWindow &app)
{
    IntRect controlsArea = IntRect(app.getSize().x - 100, 10, 100, 30);
    if(controlsArea.contains(clickPosition))
    {
        showHelp = !showHelp;
    }
}

void Board::drawText(RenderWindow &app)
{
    std::ostringstream sPoints;
    sPoints << points;

    text.setString("Puntos: " +  sPoints.str());
    text.setPosition(10, 10);

    app.draw(text);

    text.setString("Controles");
    text.setPosition(app.getSize().x - 100, 10);

    app.draw(text);
}

void Board::drawRocks(RenderWindow &app)
{
    for(int i= 0; i < shoots; ++i)
    {
        rockSprite.setPosition(Vector2f(app.getSize().x - i * 30, app.getSize().y - 30));
        app.draw(rockSprite);
    }
}

void Board::drawHelp(RenderWindow &app)
{
    if(showHelp)
    {
        if(helpSprite.getPosition().y < 0)
        {
            Vector2f newPosition = helpSprite.getPosition() + Vector2f(0, 10);
            helpSprite.setPosition(newPosition);
        }
    } else {
        if(helpSprite.getPosition().y > -750)
        {
            Vector2f newPosition = helpSprite.getPosition() + Vector2f(0, -10);
            helpSprite.setPosition(newPosition);
        }
    }
    app.draw(helpSprite);
}

void Board::draw(RenderWindow &app)
{
    drawText(app);
    drawRocks(app);
    drawHelp(app);
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

void Board::addShoots(int newShoots)
{
    if(shoots + newShoots < maxShoots)
    {
        shoots += newShoots;
    } else {
        shoots = maxShoots;
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

void Board::increaseBottles()
{
    if(bottlesSize < 8)
    {
        ++bottlesSize;
    }
}

void Board::decreaseBottles()
{
    if(bottlesSize > 1)
    {
        --bottlesSize;
    }
}

int Board::getBottlesSize()
{
    return bottlesSize;
}
