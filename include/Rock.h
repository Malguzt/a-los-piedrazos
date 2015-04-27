#ifndef ROCK_H
#define ROCK_H
#include <SFML/Graphics.hpp>

using namespace sf;


class Rock
{
    public:
        Rock();
        virtual ~Rock();
        void update();
        void draw(RenderWindow &gm);
    protected:
    private:
        Vector2f position = Vector2f(100.5f, 500.5f);
        Vector2f speed = Vector2f(0, 0);
        Vector2f pivot = Vector2f(100, 450);
        int speedModule = 10;
        Sprite sprite;
        Texture texture;
        CircleShape shape;
        int frame = 0;
        void changePosition();
        void updateSpeed();
};

#endif // ROCK_H
