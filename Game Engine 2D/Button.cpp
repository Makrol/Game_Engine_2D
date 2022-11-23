#include "Button.h"



Button::Button(BitmapHandler* bitmapHandler,std::string bitmapName, Vector2f position)
{
	//texture = *bitmapHandler->getTexture(bitmapName);
	gameObjectBody.setTexture(*bitmapHandler->getTexture(bitmapName));
	gameObjectBody.setPosition(position);
	gameObjectBody.setOrigin(gameObjectBody.getGlobalBounds().width / 2, gameObjectBody.getGlobalBounds().height / 2);
}

bool Button::PressDetection(const RenderWindow& window)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (gameObjectBody.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			return true;
		}
	}
	return false;
}

void Button::update(RenderWindow *window)
{

}

void Button::draw(RenderWindow* window)
{
	window->draw(gameObjectBody);
}

void Button::translate(int x, int y)
{
	int tmpX = gameObjectBody.getPosition().x;
	int tmpY = gameObjectBody.getPosition().y;

	TransformableObject::translate(tmpX, tmpY, x, y);

	gameObjectBody.setPosition(tmpX, tmpY);
}

void Button::rotate(int px, int py, int angle)
{
	int tmpX = gameObjectBody.getPosition().x;
	int tmpY = gameObjectBody.getPosition().y;

	TransformableObject::rotate(tmpX, tmpY, px, py, angle);

	gameObjectBody.setPosition(tmpX, tmpY);
}

void Button::rotate(int angle)
{
	int tmpX = gameObjectBody.getPosition().x;
	int tmpY = gameObjectBody.getPosition().y;

	TransformableObject::rotate(tmpX, tmpY, 0, 0, angle);

	gameObjectBody.setPosition(tmpX, tmpY);
}

void Button::scale(int px, int py, float kx, float ky)
{
	int tmpX = gameObjectBody.getPosition().x;
	int tmpY = gameObjectBody.getPosition().y;


	TransformableObject::scale(tmpX, tmpY, px, py, kx, ky);

	gameObjectBody.setPosition(tmpX, tmpY);
}

void Button::scale(float kx, float ky)
{



	gameObjectBody.setScale(kx,ky);


}

