#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameObject.h"
using namespace sf;
/**
 * @brief Klasa obiektów do narysowania
 */
class DrawableObject: virtual public GameObject
{
public:
	/**
	 * @brief Rysuje obiekt
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	virtual void draw(RenderWindow* window)=0;
};

