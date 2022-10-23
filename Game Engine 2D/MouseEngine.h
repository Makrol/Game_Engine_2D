#pragma once
#include "InputEngine.h"
class MouseEngine:public InputEngine
{
public:
	void pollEvent(Event* eventHendler,RenderWindow* window);
};

