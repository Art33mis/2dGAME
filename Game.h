/*!
 \file
 \brief Game Class Description File
 The class is responsible creating, drawing players,bullets, map.
 Handle events, collision and end of the game
 Contains method to create and draw menu interface
 */
#include <iostream>
#include <memory>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Map.h"
#include <list>
#include "Player1.h"
#include "Player2.h"
#include "Menu.h"
#ifndef BASICSMETHODS_GAME_H
#define BASICSMETHODS_GAME_H


class Game {
private:
    /// Variables for creating window
    sf::VideoMode videoMode;
    sf::Event event;
    /*!
     * initialize window
     */
    void initWindow();

public:
    ///sfml-objects to add sound and music
    sf::SoundBuffer shootBuffer;

    sf::Sound shoot;

    sf::Music music;
    /// smart pointer of window
    std::unique_ptr<sf::RenderWindow> window;

    ///Constructor
    Game();

    /*!
     * The method is responsible for handle events. Particularly close window, create and add bullet in list
     * @param x1, y1, x2, y2 needed to set positions for new bullet
     * @param state1, state2 needed to choose direction of bullet
     */
    void pollEvents(float x1, float y1, int state1, float x2, float y2, int state2);
    /*!
     * calls the method update for all list items
     * @param time needed for creatures' method update
     */
    void update(float time);
    /*!
     * open window
     * @return opening window
     */
    const bool running() const;
    /*!
     * calls all methods to start game
     */
    void startGame();
    /*!
     * create, draw and display Map
     */
    void createMap();
    /*!
     * draw all list items
     */
    void drawPersons();
    /*!
     * Check player and bullet collision, after delete bullet and get damage to player
     * @param references player1, player2 needed to call their personal method getRect
     */
    void intersection(Player1 &player1, Player2 &player2);
    /*!
     * create, draw and display end of the game.
     * @param references player1, player2 needed to call their personal field health
     */
    void End_Menu(Player1 &player1, Player2 &player2);

    std::list<std::unique_ptr<Creature>> creatures;///> list for bullets
    std::list<std::unique_ptr<Creature>>::iterator it; ///>iterator for list
    ///Map's array



};


#endif //BASICSMETHODS_GAME_H
