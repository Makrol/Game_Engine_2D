#pragma once
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;
/**
 * @brief Klasa dla obiektów z bitmap¹
 */
class BitmapObject: virtual public DrawableObject
{
	Texture texture/*!<Tekstura>*/;
public:
	/**
	 * @brief Rysuje obiekt
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	virtual void draw(RenderWindow* window) = 0;
};

