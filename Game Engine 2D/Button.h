#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "BitmapObject.h"
#include "UpdatableObject.h"
#include "BitmapHandler.h"
#include "TransformableObject.h"
using namespace sf;
/**
 * @brief Klasa przycisków
 *
 */
class Button: public BitmapObject,UpdatableObject
{
private:
	//Texture texture;/*!<Tekstura przycisku>*/
	//Sprite body;/*!<>Cia³o przycisku*/

public:

	/**
	 * @brief konstruktor inicjuj¹cy przycisk
	 *
	 * @param path œcie¿ka do textury przycisku
	 * @param position pozycja na ekranie przycisku
	 */
	Button(BitmapHandler* bitmapHandler,std::string bitmapName, Vector2f position);
	/**
	 * @brief Wykrywanie wcisniêcia przycisku
	 *
	 * @param window referencja do okna aplikacji
	 * @return true je¿eli przycisk zosta³ wciœniêty
	 * @return false je¿eli przycisk nie zosta³ wciœniêty
	 */
	bool PressDetection(const RenderWindow& window);
	/**
	 * @brief Skalowanie rozmiaru przycisku o zadan¹ Wartoœæ
	 *
	 * @param x skalowanie na osi x
	 * @param y skalowanie na osi y
	 */
	//void setScale(double x, double y);
	/**
	 * @brief aktualizowanie stanu przycisku
	 *
	 */
	void update(RenderWindow *window);
	/**
	 * @brief wyœwietlanie przycisku na ekranie
	 *
	 * @param target wskaŸnik na okno gry
	 */
	void draw(RenderWindow* target);
	/**
	 * @brief Przesuwa o wspó³rzêdne
	 *
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotuje obiekt wzglêdem punktów
	 *
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	void rotate(int px, int py, int angle);
	/**
	 * @brief Rotuj obiekt
	 *
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	void rotate(int angle);
	/**
	 * @brief Skalowanie obiektu wzglêdem podanych punktów
	 *
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(int px, int py, float kx, float ky);
	/**
	 * @brief Skalowanie obiektu wzglêdem punktów 0,0
	 *
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
};

