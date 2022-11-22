#pragma once
#include "ShapeObject.h"

#include "Point2D.h"

#include "PrimitiveRenderer.h"


/**
 * @brief Klasa do stworzenia prostok¹ta
 */
class Rectangle:public ShapeObject
{
public:

	/**
	 * @brief Konstruktor prostok¹ta
	 * 
	 * \param position Pozycja
	 * \param xSize Rozmiar X
	 * \param ySize Rozmiar Y
	 * \param border Kolor obramówki
	 * \param fill Wype³nienie kolorem figury
	 * \param thickness Gruboœæ obramowania
	 */
	Rectangle(Point2D position, int xSize, int ySize, Color border, Color fill, int thickness);
	/**
	 * @brief Rysuje obiekty
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	void draw(RenderWindow* window);
	/**
	 * @brief Przesuwa o wspó³rzêdne
	 * 
	 * \param x Wspo³rzêdna na osi X
	 * \param y	Wspo³rzêdna na osi Y
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotacja wzgledem podanych punktów
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma sie przemieœciæ figura
	 */
	void rotate(int px, int py, int angle);
	/**
	 * @brief Rotacja wzglêdem punktu 0,0
	 * 
	 * \param angle K¹t o jaki ma sie przemieœciæ figura
	 */
	void rotate(int angle);
	/**
	 * @brief Skalowanie wzglêdem zadanego punktu
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(int px, int py, float kx, float ky);
	/**
	 * @brief Skalowanie wzglêdem danej figury
	 * 
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);

};

