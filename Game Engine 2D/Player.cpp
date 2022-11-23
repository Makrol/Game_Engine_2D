#include "Player.h"



Player::Player(Point2D position, BitmapHandler* bitmapHandler)
{
	atack = false;
	this->bitmapHandler = bitmapHandler;
	gameObjectBody.setTexture(*bitmapHandler->getTexture("playerG1"));
	animationTime = 0;
	frameNum = 1;
	lastDirection = 'S';

}

Player::~Player()
{
}

void Player::update(RenderWindow *window)
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

void Player::animate(float deltaTime)
{
	if (!atack)
	{
		animationTime += deltaTime;
		if (animationTime >= 0.04)
		{
			animationTime = 0;
			frameNum++;
			
		}
		if (frameNum > 5)
			frameNum = 1;
		switch (lastDirection)
		{
		case 'A':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerL" + std::to_string(frameNum)));
			break;
		case 'S':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerD" + std::to_string(frameNum)));
			break;
		case 'D':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerP" + std::to_string(frameNum)));
			break;
		case 'W':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerG" + std::to_string(frameNum)));
			break;

		default:
			break;
		}
	}
	else
	{
		animationTime += deltaTime;
		if (animationTime >= 0.04)
		{
			animationTime = 0;
			frameNum++;
			
		}
		if (frameNum > 3)
			frameNum = 1;
		switch (lastDirection)
		{
		case 'A':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerLA" + std::to_string(frameNum+5)));
			break;
		case 'S':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerDA" + std::to_string(frameNum+5)));
			break;
		case 'D':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerPA" + std::to_string(frameNum+5)));
			break;
		case 'W':
			gameObjectBody.setTexture(*bitmapHandler->getTexture("playerGA" + std::to_string(frameNum+5)));
			break;

		default:
			break;
		}

	}


	
	atack = false;
}


