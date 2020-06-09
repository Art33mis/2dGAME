/*!
 \file
 \brief Heir Player1 Class Description File
 This first of two classes for creating character to play
 Contains all the basic methods and fields to visualisation, motion and interaction
 */
#include "Player.h"
#ifndef BASICSMETHODS_PLAYER1_H
#define BASICSMETHODS_PLAYER1_H
#include "Creature.h"
#include "Map.h"
#include "Player.h"
class Player1 : public  Player {
public:
    ///variable to determine which picture to draw
    float CurrentFrame;
    ///Constructor/Destructor
    Player1(sf::String F, float X, float Y, float W, float H);

    virtual ~Player1();
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


#endif //BASICSMETHODS_PLAYER1_H
