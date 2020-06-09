#include "Creature.h"


Creature::Creature(sf::String F, float X, float Y, int W, int H) {
    x = X;
    y = Y;
    w = W;
    h = H;
    name = F;
    speed = 0;
    health = 100;
    dx = 0;
    dy = 0;
    life = true;
    onGround = false;
    isMove = false;
    image.loadFromFile("images/" + name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setOrigin(w / 2, h / 2);
}

Creature::~Creature() {

}

sf::FloatRect Creature::getRect() {

    return sf::FloatRect(x, y, w, h);

}

int Creature::getDamage() {
    health -= 25;
    return health;
}