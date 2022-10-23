#include <iostream>
#include "Engine.h"

int main()
{
    std::cout <<  VideoMode::getDesktopMode().width;
    std::cout <<  VideoMode::getDesktopMode().height;
    Engine* engine = Engine::getInstance(1280,720);
    engine->start();

    
}
