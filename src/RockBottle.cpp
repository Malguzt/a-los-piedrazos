#include "RockBottle.h"

RockBottle::RockBottle(std::vector<Bottle*> &bottles):
    Bottle::Bottle(bottles)
{
    rockTexture.loadFromFile("img/small_rock.png");
    rockSprite.setTexture(rockTexture);
    rockSprite.setTextureRect(IntRect(0, 0, 32, 32));
}

RockBottle::~RockBottle()
{
}

void RockBottle::draw(RenderWindow &gm)
{
    Bottle::draw(gm);
    Vector2f scale = getScale();
    rockSprite.setPosition(Vector2f(position.x + (10 * scale.x), position.y + (60 * scale.y)));
    rockSprite.setScale(scale);
    gm.draw(rockSprite);
}

void RockBottle::updateBoard(Board &board)
{
    board.addShoots(3);
}
