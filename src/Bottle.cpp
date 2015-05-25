#include "Bottle.h"

Bottle::Bottle(std::vector<Bottle*> &bottles)
{
    texture.loadFromFile("img/blue_bottle.png");
    sprite.setTexture(texture);
    newPosition(bottles);
}

Bottle::~Bottle()
{
    //dtor
}

void Bottle::draw(RenderWindow &gm)
{
    #ifdef DEBUG_PHYSICS
        RectangleShape rectangle((Vector2f) theSize);
        rectangle.setPosition(position);
        gm.draw(rectangle);
    #endif // DEBUG_PHYSICS
    gm.draw(sprite);
}

void Bottle::checkPosition(std::vector<Bottle*> &bottles)
{
    bool isUsed;
    do
    {
        isUsed = false;
        getRandomPosition();
        for (std::vector<Bottle*>::iterator it = bottles.begin(); it != bottles.end(); ++it)
        {
            isUsed |= zoneIsUsed(*(*it));
        }
    } while(isUsed);
}

void Bottle::getRandomPosition()
{
    int x = rand() % 350 + 400;
    int y = rand() % 400 + 10;
    position = Vector2f(x, y);
}

void Bottle::newPosition(std::vector<Bottle*> &bottles)
{
    checkPosition(bottles);
    sprite.setPosition(position);
}

IntRect Bottle::getArea()
{

    return IntRect((Vector2i) position, theSize);
}

bool Bottle::zoneIsUsed(Bottle &otherBottle)
{
    if(&otherBottle != this)
    {
        return getArea().intersects(otherBottle.getArea());
    }

    return false;
}

bool Bottle::checkCollision(Rock &theRock, std::vector<Bottle*> &bottles)
{
    if (getArea().intersects(theRock.getArea()))
    {
        theRock.newShoot();
        newPosition(bottles);

        return true;
    }

    return false;
}
