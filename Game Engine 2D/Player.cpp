#include "Player.h"

Player::Player(Point2D position)
{
	gameObjectBody.setPosition(position.getX(),position.getY());



	if (!tmpText.loadFromFile("player/d1.png"))
		std::cout << "Error";
	gameObjectBody.setTexture(tmpText);
}

Player::Player(Point2D position, Texture texture)
{
	gameObjectBody.setPosition(position.getX(), position.getY());
	gameObjectBody.setTexture(texture);

}

Player::~Player()
{
}

void Player::update()
{

}

void Player::draw(RenderWindow* window)
{
	window->draw(gameObjectBody);
}

void Player::translate(int x, int y)
{
	gameObjectBody.move(x,y);
}

void Player::rotate(int px, int py, int angle)
{
	int tmpX = gameObjectBody.getPosition().x;
	int tmpY = gameObjectBody.getPosition().y;
	TransformableObject::rotate(tmpX, tmpY, px, py, angle);
	gameObjectBody.setPosition(tmpX,tmpY);
}

void Player::rotate(int angle)
{
	gameObjectBody.rotate(angle);
}

void Player::scale(int px, int py, float kx, float ky)
{
	int tmpX = gameObjectBody.getPosition().x;
	int tmpY = gameObjectBody.getPosition().y;

	TransformableObject::scale(tmpX, tmpY, px, py, kx, ky);
	gameObjectBody.scale(kx, ky);
}

void Player::scale(float kx, float ky)
{
	gameObjectBody.scale(kx, ky);
}


