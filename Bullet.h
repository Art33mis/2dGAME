/*!
 \file
 \brief Heir Bullet Class Description File
 This  class for creating bullet to damage players
 Contains all the basic methods and fields to visualisation, motion and interaction
 */
#include "Creature.h"
#include "Map.h"
#ifndef BASICSMETHODS_BULLET_H
#define BASICSMETHODS_BULLET_H


class Bullet : public Creature {
public:
    /// variable to choose direction of bullet
    int direction;
    /// Constructor/Destructor
    Bullet(sf::String F, float X, float Y, float W, float H, int dir);

    virtual ~Bullet();
    /*!
     *The method is responsible for the movement of the character and interaction with map
     * @param time needed not to depend on processor frequency
     */
    void update(float time) override;


    ///Map's array

};


#endif //BASICSMETHODS_BULLET_H
