cmake_minimum_required(VERSION 3.15)
# The project name
project(basicsmethods)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 17)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(basicsmethods main.cpp Player1.cpp Player1.h Game.cpp Game.h Map.h Bullet.cpp Bullet.h Creature.cpp Creature.h Player2.cpp Player2.h Menu.h Player.cpp Player.h)
target_link_libraries(basicsmethods sfml-graphics sfml-window sfml-system sfml-audio sfml-network)