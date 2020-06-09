//
// Created by Артем Автайкин on 09.06.2020.
//

#include "Player.h"
Player::Player(sf::String F, float X, float Y, float W, float H) : Creature(F, X, Y, W,
                                                                              H)
{

}

Player::~Player() {

}

void Player::update( float time) {
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

void Player::motion(float time) {


    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
        state = left;
        speed = 0.35;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame >= 3) CurrentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96,
                                          96));
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        state = right;
        speed = 0.35;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame >= 3) CurrentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96,
                                          96));
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (onGround)) {
        state = jump;
        dy = -1.1;
        onGround = false;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame >= 3) CurrentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96,
                                          96));

    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
        state = right_Top;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
        state = left_Top;
    }

}


void Player::interactionWithMap(float Dx, float Dy)
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