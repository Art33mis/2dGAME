#include "Player1.h"

Player1::Player1(sf::String F, float X, float Y, float W, float H) : Player(F, X, Y, W,
                                                                              H)
{

}

Player1::~Player1() {

}



void Player1::motion(float time) {


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



