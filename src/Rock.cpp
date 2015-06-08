#include "Rock.h"
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;

Rock::Rock()
{
    texture.loadFromFile("img/small_rock.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Rock::~Rock()
{
    //dtor
}

void Rock::draw(RenderWindow &gm)
{
    //Draw radius
    if(inTheSling)
    {
        Vertex radiusLine[] = {Vertex(pivot, Color(200, 200, 0)), Vertex(position, Color(250, 80, 50))};
        gm.draw(radiusLine, 2, Lines);
    }

    int x = (frame % 8 * 32);
    int y = (frame / (int)8) * 32;
    sprite.setTextureRect(IntRect(x, y, 32, 32));
    gm.draw(sprite);

    #ifdef DEBUG_PHYSICS

    //Draw speed
    Vertex speedLine[] = {position, speed + position};
    gm.draw(speedLine, 2, Lines);
    #endif // DEBUG_PHYSICS

}

void Rock::update()
{
    if(frame > 30)
    {
        frame = 0;
    } else {
        ++frame;
    }
    changePosition();
}

void Rock::changePosition()
{
    position += speed;
    updateSpeed();
    sprite.setPosition(position - Vector2f(16, 16));
}

void Rock::calculateRadius()
{
    float angle = getTheAngle();
    position.x = pivot.x + radius * cos(angle);
    position.y = pivot.y + radius * sin(angle);
}

float Rock::getTheAngle()
{
    Vector2f centripetal = position - pivot;

    return atan2(centripetal.y, centripetal.x) ;
}

void Rock::updateSpeed()
{
    if(inTheSling)
    {
        calculateRadius();
        float angle = getTheAngle() - (M_PI / 2);
        speed.x = speedModule * cos(angle);
        speed.y = speedModule * sin(angle);
    }
    speed += Vector2f(0, 0.4);

}

void Rock::changeRadius(int addRadius)
{
    if(radius + addRadius > 5 && radius + addRadius < 201) {
        radius += addRadius;
    }
}

void Rock::changeSpeed(int addSpeed)
{
    if(speedModule + addSpeed > -51 && speedModule + addSpeed < 51){
        speedModule += addSpeed;
    }
}

void Rock::shoot()
{
    inTheSling = false;
}

bool Rock::inTheScene(int x, int y)
{
    return position.x > 0 && position.x < x && position.y > 0 && position.y < y;
}

void Rock::newShoot()
{
    position = Vector2f(200.5f, 500.5f);
    inTheSling = true;
    speed = Vector2f(0, 0);
    speedModule = 10;
    radius = 100;
}

IntRect Rock::getArea()
{

    return IntRect(position.x, position.y, 32, 32);
}
