#include "GreenBottle.h"

GreenBottle::GreenBottle(std::vector<Bottle*> &bottles):
    Bottle::Bottle(bottles)
{
    sprite.setColor(Color(0, 250, 0));
}

GreenBottle::~GreenBottle()
{
}

void GreenBottle::updateBoard(Board &board)
{
    board.increaseBottles();
}
