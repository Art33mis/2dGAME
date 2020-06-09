/*!
 \file
 \brief Ancestor Class Description File
 Contains all the basic methods and fields for posterity
 */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#ifndef BASICSMETHODS_CREATURE_H
#define BASICSMETHODS_CREATURE_H

class Creature {
public:
    ///The set of possible states of an object
    enum {
        right, left, jump, stay, right_Top, left_Top
    } state;
    ///variables for moving an object
    float dx, dy, x, y, speed;
    /// Weight and Height for Rectangle of our object
    int w, h,
    health;///> object health
    bool life,
    isMove, ///>indicates whether the object is moving
    onGround;///>indicates whether the object is on the ground
    /// sfml-objects to create visual character
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::String name;
    ///Constructors/Destructor of Creature
    Creature(sf::String Name, float X, float Y, int W, int H);

    virtual ~Creature();
/*!
   Method to get hitbox
  \return Rectangle with parameters Position x, y, Height, Weight
 */
    sf::FloatRect getRect();
/*!
 Method to get damage
 * \return Health after damage
 */
    int getDamage();
/*!
 *The method is responsible for the movement of the character
 * @param time needed not to depend on processor frequency
 */
    virtual void update(float time) = 0;

};


#endif //BASICSMETHODS_СREATURE_H
