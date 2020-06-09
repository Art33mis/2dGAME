#include "Player2.h"

Player2::Player2(sf::String F, float X, float Y, float W, float H) : Player(F, X, Y, W, H) {


    sprite.setTextureRect(sf::IntRect(0, 96, w,
                                      h));

}

Player2::~Player2() {}




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



