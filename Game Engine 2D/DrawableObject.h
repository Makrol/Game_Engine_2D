#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class DrawableObject
{
public:
	virtual void draw(RenderWindow* window)=0;
};

