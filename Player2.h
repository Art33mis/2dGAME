/*!
 \file
 \brief Heir PLayer2 Class Description File
 This second of two classes for creating character to play
 Contains all the basic methods and fields to visualisation, motion and interaction with map and other objects
 */
#ifndef BASICSMETHODS_PLAYER2_H
#define BASICSMETHODS_PLAYER2_H
#include "Creature.h"
#include "Map.h"
#include "Player.h"
class Player2 : public Player {
public:
    ///variable to determine which picture to draw
    float CurrentFrame;
    ///Constructor
    Player2(sf::String F, float X, float Y, float W, float H);

    virtual ~Player2();
    /*!
     *The method is responsible for the movement of the character
     * @param time needed not to depend on processor frequency
     */

    /*!
     * The method is responsible for animation and control
     * @param time needed to determine which picture to draw
     */
    void motion(float time);
    /*!
     *The method is responsible to handle collisions with map
     * @param Dx, Dy acceleration on x and y
     */



    /// Map's array

};


#endif //BASICSMETHODS_PLAYER2_H
