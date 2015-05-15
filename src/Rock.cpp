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
    int x = (frame % 8 * 32);
    int y = (frame / (int)8) * 32;
    sprite.setTextureRect(IntRect(x, y, 32, 32));
    gm.draw(sprite);

    #ifdef DEBUG_PHYSICS
    //Draw radius
    Vertex radiusLine[] = {pivot, position};
    gm.draw(radiusLine, 2, Lines);

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
    sprite.setPosition(position - Vector2f(16, 16));
    calculateRadius();
    updateSpeed();
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
    float angle = getTheAngle() - (M_PI / 2);
    speed.x = speedModule * cos(angle);
    speed.y = speedModule * sin(angle);
}

void Rock::changeRadius(int addRadius){
    if(radius + addRadius > 5 && radius + addRadius < 201) {
        radius += addRadius;
    }
}

void Rock::changeSpeed(int addSpeed)
{
    if(speedModule + addSpeed > -201 && speedModule + addSpeed < 201){
        speedModule += addSpeed;
    }
}
