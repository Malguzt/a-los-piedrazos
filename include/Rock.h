#ifndef ROCK_H
#define ROCK_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio.hpp>


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
        bool inTheScene(RenderWindow &);
        void newShoot();
        IntRect getArea();
        void playCrash();
    protected:
    private:
        SoundBuffer crashBuffer;
        Sound crashSound;
        SoundBuffer slingBuffer;
        Sound slingSound;
        SoundBuffer shootBuffer;
        Sound shootSound;
        bool inTheSling = true;
        Vector2f position;
        Vector2f speed = Vector2f(0, 0);
        Vector2f pivot = Vector2f(200, 550);
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
