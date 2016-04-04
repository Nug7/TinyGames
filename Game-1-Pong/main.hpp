#ifndef GAME_1_PONG_H_
#define GAME_1_PONG_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

class Panel
{

};

class Ball
{

};







class Game
{
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();
private:
    sf::RenderWindow window;

};



#endif // GAME_1_PONG_H_
