#pragma once
#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"
using namespace sf;
/**
 * @brief Linia mi�dzy dwoma punktami
 */
class LineSegment: public TransformableObject
{
public:
	/**
	 * @brief Konstruktor linii
	 * 
	 * \param first Jeden koniec linii 
	 * \param second Drugi koniec linii 
	 */
	LineSegment(Point2D first,Point2D second);

	/**
	 * @brief Getter 1 ko�ca linii
	 * 
	 * \return 
	 */
	Point2D getFirst();
	/**
	 * @brief Getter 2 ko�ca linii
	 * 
	 * \return 
	 */
	Point2D getSecond();

	/**
	 * @brief Setter 1 ko�ca linii
	 * 
	 * \param point
	 */
	void setFirst(Point2D point);
	/**
	 * @brief Setter 2 ko�ca linii
	 * 
	 * \param point
	 */
	void setSecond(Point2D point);
	/**
	 * @brief Rysuje linie podstawowym algorytmem SFML
	 * 
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param color Kolor
	 */
	void drawDefault(RenderWindow* window,Color color);
	/**
	 * @brief Rysuje linie algorytmem przyrostowym
	 * 
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param color Kolor
	 * \param thickness Grubo�� linii
	 */
	void draw(RenderWindow* window,Color color, int thickness);


	/**
	 * @brief Przemieszcza linie
	 * 
	 * \param x Wsp�rz�dna X
	 * \param y Wsp�rz�dna Y
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotacja wzgl�dem podanych punkt�w
	 * 
	 * \param px Wspo�rz�dna punktu na osi X
	 * \param py Wspo�rz�dna punktu na osi Y
	 * \param angle K�t o jaki ma sie przemie�ci� figura 
	 */
	void rotate(int px, int py, int angle);
	/**
	 * @brief Rotacja wzgl�dem punktu 0,0
	 * 
	 * \param angle K�t o jaki ma sie przemie�ci� figura 
	 */
	void rotate(int angle);
	/**
	 * @brief Skalowanie wzgl�dem zadanego punktu
	 * 
	 * \param px Wspo�rz�dna punktu na osi X
	 * \param py Wspo�rz�dna punktu na osi Y
	 * \param kx Wsp�czynnik skalowania na osi X
	 * \param ky Wsp�czynnik skalowania na osi Y
	 */
	void scale(int px, int py, float kx, float ky);
	/**
	 * @brief Skalowanie wzgl�dem punktu 0,0
	 * 
	 * \param kx Wsp�czynnik skalowania na osi X
	 * \param ky Wsp�czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
private:
	Point2D first;/*!<>*/
	Point2D second;/*!<>*/
	
};

