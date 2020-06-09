//
// Created by Артем Автайкин on 09.06.2020.
//

#ifndef BASICSMETHODS_PLAYER_H
#define BASICSMETHODS_PLAYER_H
#include "Creature.h"
#include "Map.h"
class Player : public Creature  {
public:
    ///variable to determine which picture to draw
    float CurrentFrame;
    ///Constructor/Destructor
    Player(sf::String F, float X, float Y, float W, float H);

    virtual ~Player();
    /*!
 *The method is responsible for the movement of the character
 * @param time needed not to depend on processor frequency
 */
    void update(float time);
    /*!
     * The method is responsible for animation and control
     * @param time needed to determine which picture to draw
     */
    virtual void motion(float time) = 0;
    /*!
     *The method is responsible to handle collisions with map
     * @param Dx, Dy acceleration on x and y
     */
    void interactionWithMap(float Dx, float Dy);



};


#endif //BASICSMETHODS_PLAYER_H
