#include "Game.h"

void Game::initWindow() {
    this->videoMode.height = 1500;
    this->videoMode.width = 2600;
    this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "2dGame",
                                                      sf::Style::Titlebar | sf::Style::Close);
}

Game::Game() {

    this->initWindow();
    shootBuffer.loadFromFile(
            "sounds/shoot.ogg");
    shoot.setBuffer(shootBuffer);
    music.openFromFile("sounds/Queen.ogg");

}

void Game::pollEvents(float x1, float y1, int state1, float x2, float y2, int state2) {
    //Event polling
    while (this->window->pollEvent(event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                if (event.key.code == sf::Keyboard::LShift) {
                    if (state1 == 0) {
                        creatures.emplace_back(
                                std::make_unique<Bullet>("bullet.png", x1 + 110, y1 + 40, 15, 15, state1));
                        shoot.play();
                    } else {
                        creatures.emplace_back(
                                std::make_unique<Bullet>("bullet.png", x1 - 110, y1 + 40, 15, 15, state1));
                        shoot.play();
                    }
                }
                if (event.key.code == sf::Keyboard::RShift) {
                    if (state2 == 0) {
                        creatures.emplace_back(
                                std::make_unique<Bullet>("bullet.png", x2 + 110, y2 + 40, 15, 15, state2));
                        shoot.play();
                    } else {
                        creatures.emplace_back(
                                std::make_unique<Bullet>("bullet.png", x2 - 110, y2 + 40, 15, 15, state2));
                        shoot.play();
                    }
                }
                break;
        }

    }
}

void Game::update(float time) {

    for (it = creatures.begin(); it != creatures.end();)
    {
        Creature *b = it->get();
        b->update(time);
        if (b->life == false) {
            it = creatures.erase(it);

        }
        else ++it;

    }

}

void Game::drawPersons() {
    for (it = creatures.begin(); it != creatures.end();) {
        window->draw((*it)->sprite);
        ++it;

    }
}

//Accessors
const bool Game::running() const {
    return this->window->isOpen();
}

void Game::createMap() {

    sf::Image map_image;
    map_image.loadFromFile(
            "images/map.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);

    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++) {
            if (TileMap[i][j] == ' ')
                s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
            if (TileMap[i][j] == 's')
                s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
            if ((TileMap[i][j] == '0'))
                s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));


            s_map.setPosition(j * 32, i *
                                      32);

            window->draw(s_map);

        }

}

void Game::intersection(Player1 &player1, Player2 &player2) {
    for (it = creatures.begin(); it != creatures.end(); it++)
    {
        if ((*it)->getRect().intersects(player1.getRect()))
        {
            std::cout << player1.health << "\n";
            player1.getDamage();
            std::cout << player1.health << "\n";
            (*it)->life = 0;

        }
        if ((*it)->getRect().intersects(player2.getRect())) {
            std::cout << player2.health << "\n";
            player2.getDamage();
            std::cout << player2.health << "\n";
            (*it)->life = 0;
        }


    }
    if (player1.health == 0 or player2.health == 0) {
        End_Menu(player1, player2);
    }
}


void Game::startGame() {
    menu(this->window);
    Player1 player1("hero.png", 1120, 250, 96.0, 96.0);
    Player2 player2("hero.png", 1500, 250, 96.0, 96.0);
    sf::Clock clock;
    while (running()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        pollEvents(player1.x, player1.y, player1.state, player2.x, player2.y, player2.state);
        update(time);
        intersection(player1, player2);
        player1.update(time);
        player2.update(time);
        window->clear();
        createMap();
        drawPersons();
        window->draw(player1.sprite);
        window->draw(player2.sprite);
        window->display();


    }
}

void Game::End_Menu(Player1 &player1, Player2 &player2) {
    music.play();

    sf::Image Return, W1, W2;
    Return.loadFromFile("images/Return.png");
    W1.loadFromFile("images/W1.png");
    W2.loadFromFile("images/W2.png");

    Return.createMaskFromColor(sf::Color(0, 0, 0));

    sf::Texture textureRtn, textureW1, textureW2;
    textureRtn.loadFromImage(Return);
    textureW1.loadFromImage(W1);
    textureW2.loadFromImage(W2);

    sf::Sprite spriteRtn, spriteW1, spriteW2;

    spriteW1.setTexture(textureW1);
    spriteW1.setTextureRect(sf::IntRect(0, 0, 2600, 1500));

    spriteW2.setTexture(textureW2);
    spriteW2.setTextureRect(sf::IntRect(0, 0, 2600, 1500));

    spriteRtn.setTexture(textureRtn);
    spriteRtn.setTextureRect(sf::IntRect(300, 280, 700, 388));

    bool isMenu = 1;

    int choice = 0;

    spriteRtn.setPosition(215, 1300);

    while (isMenu == 1) {

        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        isMenu = 0;

                    window->close();
            }
        }

        spriteRtn.setColor(sf::Color::White);

        window->clear();
        //change button's color when mouse aimed on it
        if (sf::IntRect(215, 1200, 700, 250).contains(sf::Mouse::getPosition(*window))) {
            spriteRtn.setColor(sf::Color::Blue);
            choice = 1;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            switch (choice) {

                case 1:

                    isMenu = false;
                    music.stop();
                    startGame();
            }

        }

        if (player1.health == 0)
            window->draw(spriteW2);
        if (player2.health == 0)
            window->draw(spriteW1);
        window->draw(spriteRtn);
        window->display();
    }


}
