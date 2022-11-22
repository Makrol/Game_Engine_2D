#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "TransformableObject.h"
#include "DrawableObject.h"
#include <cmath>


using namespace sf;
/**
 * @brief Klasa do tworzenia punktu
 */
class Point2D: public DrawableObject,TransformableObject
{
private:
	int x;/*!<Wspo�rz�dna na osi X>*/
	int y;/*!<Wspo�rz�dna na osi Y>*/
	Color color;/*!<kolor punktu>*/
	int thickness;/*!<grubo�� punktu>*/
public:
	/**
	 * @brief Konstruktor punktu
	 * 
	 */
	Point2D();
	/**
	 * @brief Konstruktor punktu
	 * 
	 * \param x Wspo�rz�dna na osi X
	 * \param y Wspo�rz�dna na osi Y
	 */
	Point2D(int x,int y);
	/**
	 * @brief Konstruktor punktu
	 * 
	 * \param x Wspo�rz�dna na osi X
	 * \param y Wspo�rz�dna na osi Y
	 * \param color kolor punktu
	 * \param thickness grubo�� punktu
	 */
	Point2D(int x,int y,Color color,int thickness);
	/**
	 * @brief.
	 * 
	 */
	~Point2D();
	/**
	 * @brief getter X
	 * 
	 * \return Wspo�rz�dna na osi X
	 */
	int getX();
	/**
	 * @brief getter Y
	 * 
	 * \return Wspo�rz�dna na osi Y
	 */
	int getY();

	/**
	 * @brief getter XRef
	 * 
	 * \return Refererencja do X
	 */
	int& getXRef();
	/**
	 * @brief getter YRef
	 * 
	 * \return Refererencja do Y
	 */
	int& getYRef();
	/**
	 * @brief setter X
	 * 
	 * \param x Wspo�rz�dna na osi X
	 */		  
	void setX(int x);
	/**
	 * @brief setter Y
	 * 
	 * \param y Wspo�rz�dna na osi Y
	 */		    
	void setY(int y);
	/**
	 * @brief. Rysuje punkt
	 * 
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� punkt
	 */
	void draw(RenderWindow *window);
	/**
	 * @brief zamienia punkty
	 * 
	 * \param p1 Wsp�rz�dne jednego punktu
	 * \param p2 Wsp�rz�dne drugiego puntku
	 */
	static void swapPoints(Point2D& p1, Point2D& p2);

	/**
	 * @brief Przesuwa o wsp�rz�dne
	 * 
	 * \param x Wspo�rz�dna na osi X
	 * \param y Wspo�rz�dna na osi Y
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotacja wzgledem podanych punkt�w
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
	 * @brief Skalowanie wzgl�dem danego punktu
	 * 
	 * \param kx Wsp�czynnik skalowania na osi X
	 * \param ky Wsp�czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
};

