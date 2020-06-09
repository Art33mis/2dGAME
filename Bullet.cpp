#include "Bullet.h"

Bullet::Bullet(sf::String F, float X, float Y, float W, float H, int dir) : Creature(F, X, Y, W, H) {
    direction = dir;
    speed = 0.8;
    sprite.setTextureRect(sf::IntRect(0, 15, w, h));

}

Bullet::~Bullet() {}

void Bullet::update(float time) {
    switch (direction) {
        case right:
            dx = speed;
            dy = 0;
            break;
        case left:
            dx = -speed;
            dy = 0;
            break;
        case jump:
            dx = 0;
            dy = -speed;
            break;
        case stay:
            dx = -speed;
            dy = 0;
            break;//stay
        case right_Top:
            dx = speed;
            dy = -speed;
            break;
        case left_Top:
            dx = -speed;
            dy = -speed;
            break;
    }

    x += dx * time;
    y += dy * time;



    for (int i = y / 32; i < (y + h) / 32; i++)
        for (int j = x / 32; j < (x + w) / 32; j++) {
            if (TileMap[i][j] == '0' | TileMap[i][j] == 's') {
                life = false;
            }
        }


    sprite.setPosition(x + w / 2, y + h / 2);
}
