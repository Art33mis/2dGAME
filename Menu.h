/*!
 \file
 \brief Menu Description File
 Contains method to create and draw menu interface
 */
#ifndef BASICSMETHODS_MENU_CPP
#define BASICSMETHODS_MENU_CPP
#include <SFML/Window.hpp>


inline void menu(std::unique_ptr<sf::RenderWindow> &window) {
 /// Creating music
    sf::Music music;//создаем объект музыки
    music.openFromFile("/Users/artyom_avtaykin/Documents/GitHub/2dGAME/sounds/West.ogg");//загружаем файл
    music.play();
/// creating a visual component menu
    //Create images
    sf::Image Background, Start, Exit;
    Background.loadFromFile("/Users/artyom_avtaykin/Documents/GitHub/2dGAME/images/Background.png");
    Start.loadFromFile("/Users/artyom_avtaykin/Documents/GitHub/2dGAME/images/Start1.png");
    Exit.loadFromFile("/Users/artyom_avtaykin/Documents/GitHub/2dGAME/images/Exit1.png");

    ///create masks to delete background
    Start.createMaskFromColor(sf::Color(0, 0, 0));
    Exit.createMaskFromColor(sf::Color(0, 0, 0));

    ///create textures
    sf::Texture textureBGD, textureStart, textureExit;
    textureBGD.loadFromImage(Background);
    textureStart.loadFromImage(Start);
    textureExit.loadFromImage(Exit);

    ///Create sprites
    sf::Sprite spriteBGD, spriteStart, spriteExit;
    //Background sprite
    spriteBGD.setTexture(textureBGD);
    spriteBGD.setTextureRect(sf::IntRect(0, 0, 2600, 1500));
    ///Start sprite
    spriteStart.setTexture(textureStart);
    spriteStart.setTextureRect(sf::IntRect(460, 280, 700, 388));
    spriteStart.setScale(2.0, 2.0);
    ///Exit sprite
    spriteExit.setTexture(textureExit);
    spriteExit.setTextureRect(sf::IntRect(460, 280, 700, 388));
    spriteExit.setScale(2.0, 2.0);


///menu indicator
    bool isMenu = 1;
///choice variable
    int choice = 0;
///sprite's position
    spriteStart.setPosition(215, 500);
    spriteExit.setPosition(215, 800);

///Menu initialization

    while (isMenu == 1) {
    ///handle events
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        isMenu = 0;
                        window->close();
                    }

            }
        }
        /// default color
        spriteStart.setColor(sf::Color::White);
        spriteExit.setColor(sf::Color::White);
        //erase previous imagines
        window->clear();
        ///change button's color when mouse aimed on it
        if (sf::IntRect(215, 500, 700, 250).contains(sf::Mouse::getPosition(*window))) {
            spriteStart.setColor(sf::Color::Blue);
            choice = 1;
        }
        if (sf::IntRect(215, 800, 700, 250).contains(sf::Mouse::getPosition(*window))) {
            spriteExit.setColor(sf::Color::Blue);
            choice = 2;
        }



        /// choice
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            switch (choice) {


                case 1:

                    isMenu = false;
                    break;

                case 2 :
                    window->close();
                    isMenu = 0;
                    break;

            }

        }

        /// draw and display
        window->draw(spriteBGD);
        window->draw(spriteStart);
        window->draw(spriteExit);
        window->display();
    }


}

#endif //BASICSMETHODS_MENU_CPP
