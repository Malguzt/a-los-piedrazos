#include "Bottle.h"

Bottle::Bottle(std::vector<Bottle*> &bottles)
{
    texture.loadFromFile("img/bottle.png");
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
    rectangle.setPosition(theoricPosition);
    gm.draw(rectangle);
#endif // DEBUG_PHYSICS

    //Draw rope

    Vector2f origin(position.x + theSize.x / 2, 0);
    Vector2f knot = origin;
    knot.y = position.y;

    Vertex radiusLine[] = {Vertex(origin, Color(100, 250, 50)), Vertex(knot, Color(0, 0, 0))};
    gm.draw(radiusLine, 8, Lines);
    sprite.setScale(getScale());
    gm.draw(sprite);
}

Vector2f Bottle::getScale()
{
    return Vector2f((float) theSize.x / baseSize.x, (float) theSize.y / baseSize.y);
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
    }
    while(isUsed);
}

void Bottle::getRandomPosition()
{
    int x = rand() % 350 + 400;
    int y = rand() % 400 + 10;
    position = Vector2f(x, 0);
    theoricPosition = Vector2f(x, y);
}

void Bottle::newPosition(std::vector<Bottle*> &bottles)
{
    checkPosition(bottles);
    speed = Vector2f(0, 0.4);
    sprite.setPosition(position);
}

IntRect Bottle::getArea()
{

    return IntRect((Vector2i) position, theSize);
}

IntRect Bottle::getTheoricArea()
{

    return IntRect((Vector2i) theoricPosition, theSize);
}

void Bottle::updatePosition()
{
    int diff = (theoricPosition.y - position.y);

    if(diff < 0)
    {
        position.y += (diff * diff * diff * 0.00001);
        speed.y += diff * 0.04;
    }

    position.y += speed.y;
    sprite.setPosition(position);
    speed.y += 0.4;
}

bool Bottle::zoneIsUsed(Bottle &otherBottle)
{
    if(&otherBottle != this)
    {
        return getTheoricArea().intersects(otherBottle.getTheoricArea());
    }

    return false;
}

bool Bottle::checkCollision(Rock &theRock, std::vector<Bottle*> &bottles, Board &board)
{
    if (getArea().intersects(theRock.getArea()))
    {
        theRock.newShoot();
        newPosition(bottles);
        updateBoard(board);

        return true;
    }

    return false;
}

void Bottle::updateBoard(Board &board)
{
    board.addPoints(20 / getScale().y);
    board.lostAShoot();
}

void Bottle::setSize(int newSize)
{
    theSize = Vector2i(newSize * 10, newSize * 20);
}
