#pragma once
#include "BitmapObject.h"
class GrassModule : public BitmapObject
{
public:
	GrassModule(Texture texture);
	void draw(RenderWindow * window);
};

