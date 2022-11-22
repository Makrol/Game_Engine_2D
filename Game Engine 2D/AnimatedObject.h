#pragma once
#include "GameObject.h"

/**
 * @brief Klasa obiektów animowanych
 */
class AnimatedObject: virtual public GameObject
{
public:
	/**
	 * @brief Animacja
	 * 
	 * \param deltaTime Czas pomiêdzy klatkami
	 */
	virtual void animate(float deltaTime) = 0;
protected:
	float animationTime;/*!<Czas po zmianie klatki animacji>*/
	int frameNum;/*!<Numer klatki animacji>*/
};

