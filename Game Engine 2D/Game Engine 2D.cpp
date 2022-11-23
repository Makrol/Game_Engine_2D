#include <iostream>
#include "Engine.h"

int main()
{
   
    Engine* engine = Engine::getInstance(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
    engine->start();

    
}
