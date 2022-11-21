#pragma once
#include "DrawableObject.h"
#include "UpdatableObject.h"
#include "TransformableObject.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Player:public DrawableObject,UpdatableObject,Transform,GameObject
{
public:
	Texture tmpText;
	Player(Point2D position);
	Player(Point2D position, Texture texture);
	~Player();

	void update();
	void draw(RenderWindow* window);

	void translate(int x, int y);
	void rotate(int px, int py, int angle);
	void rotate(int angle);
	void scale(int px, int py, float kx, float ky);
	void scale(float kx, float ky);

private:


};

