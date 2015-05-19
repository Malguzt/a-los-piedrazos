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
        void changeRadius(int addRadius);
        void changeSpeed(int addSpeed);
        void shoot();
        bool inTheScene(int x, int y);
        void newShoot();
    protected:
    private:
        bool inTheSling = true;
        Vector2f position = Vector2f(200.5f, 500.5f);
        Vector2f speed = Vector2f(0, 0);
        Vector2f pivot = Vector2f(200, 400);
        int speedModule = 10;
        Sprite sprite;
        Texture texture;
        CircleShape shape;
        int frame = 0;
        int radius = 100;
        void changePosition();
        void updateSpeed();
        void calculateRadius();
        float getTheAngle();
};

#endif // ROCK_H
