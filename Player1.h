/*!
 \file
 \brief Heir Player1 Class Description File
 This first of two classes for creating character to play
 Contains all the basic methods and fields to visualisation, motion and interaction
 */
#ifndef BASICSMETHODS_PLAYER_H
#define BASICSMETHODS_PLAYER_H
#include "Creature.h"
#include "Map.h"
class Player1 : public Creature {
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
    void update(float time);
    /*!
     * The method is responsible for animation and control
     * @param time needed to determine which picture to draw
     */
    void motion(float time);
    /*!
     *The method is responsible to handle collisions with map
     * @param Dx, Dy acceleration on x and y
     */
    void interactionWithMap(float Dx, float Dy);


    /// Map's array

};


#endif //BASICSMETHODS_PLAYER_H
