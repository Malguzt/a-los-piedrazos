#include "RedBottle.h"

RedBottle::RedBottle(std::vector<Bottle*> &bottles):
    Bottle::Bottle(bottles)
{
    sprite.setColor(Color::Red);
}

RedBottle::~RedBottle()
{
    //dtor
}

void RedBottle::updateBoard(Board &board)
{
    board.decreaseBottles();
}

