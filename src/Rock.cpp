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
    sprite.setPosition(position);
    updateSpeed();
}

void Rock::updateSpeed()
{
    Vector2f centripetal = position - pivot;
    float angle = atan2(centripetal.y, centripetal.x) - (M_PI / 2);
    speed.x = speedModule * cos(angle);
    speed.y = speedModule * sin(angle);
}
