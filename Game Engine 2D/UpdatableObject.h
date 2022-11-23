#pragma once
#include "GameObject.h"
/**
 * @brief Abstrakcyjna klasa, z metod¹ do aktualizowania stanu gry
 */
class UpdatableObject: virtual public GameObject
{
	
public:
	/**
	 * @brief Metoda do aktualizowania stanu gry
	 * 
	 */
	virtual void update(RenderWindow* window) = 0;
};

