#include "GrassModule.h"

GrassModule::GrassModule(Texture texture)
{
	this->texture = texture;
	gameObjectBody.setTexture(this->texture);
}

void GrassModule::draw(RenderWindow* window)
{
	gameObjectBody.setPosition(0, 0);
	window->draw(gameObjectBody);
	gameObjectBody.setPosition(800, 0);
	window->draw(gameObjectBody);
	gameObjectBody.setPosition(1600, 0);
	window->draw(gameObjectBody);
	gameObjectBody.setPosition(0, 800);
	window->draw(gameObjectBody);
	gameObjectBody.setPosition(800, 800);
	window->draw(gameObjectBody);
	gameObjectBody.setPosition(1600, 800);
	window->draw(gameObjectBody);
}
