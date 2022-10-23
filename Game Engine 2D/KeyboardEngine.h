#pragma once
#include "InputEngine.h"

using namespace sf;

class KeyboardEngine: public InputEngine
{
public:
	void pollEvent(Event* eventHendler, RenderWindow* window);
};

