#include "Player2.h"

Player2::Player2(sf::String F, float X, float Y, float W, float H) : Creature(F, X, Y, W, H) {


    sprite.setTextureRect(sf::IntRect(0, 96, w,
                                      h));

}

Player2::~Player2() {}

void Player2::update(float time) {
    motion(time);

    switch (state)
    {
        case right:
            dx = speed;
            break;
        case left:
            dx = -speed;
            break;
        case jump:
            break;
        case stay:
            break;
        case right_Top:
            dx = speed;
            break;
        case left_Top:
            dx = -speed;
            break;
    }
    x += dx * time;
    interactionWithMap(dx, 0);
    y += dy * time;
    interactionWithMap(0, dy);
    if (!isMove) speed = 0;
    sprite.setPosition(x + w / 2, y + h / 2);
    dy = dy + 0.0015 * time;
}

void Player2::motion(float time) {


    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
        state = left;
        speed = 0.35;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame >= 3) CurrentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96,
                                          96));
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
        state = right;
        speed = 0.35;//направление вправо, см выше
        CurrentFrame += 0.005 * time;
        if (CurrentFrame >= 3) CurrentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96,
                                          96));
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (onGround)) {
        state = jump;
        dy = -1.1;
        onGround = false;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame >= 3) CurrentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96,
                                          96));

    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
        state = right_Top;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
        state = left_Top;
    }

}


void Player2::interactionWithMap(float Dx, float Dy)
{

    for (int i = y / 32; i < (y + h) / 32; i++)
        for (int j = x / 32; j < (x + w) / 32; j++) {
            if (TileMap[i][j] == '0' | TileMap[i][j] == 's')
            {
                if (Dy > 0) {
                    y = i * 32 - h;
                    dy = 0;
                    onGround = true;
                }
                if (Dy < 0) {
                    y = i * 32 + 32;
                    dy = 0;
                }
                if (Dx > 0) { x = j * 32 - w; }
                if (Dx < 0) { x = j * 32 + 32; }
            } else { onGround = false; }
        }
}
