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
	int x;/*!<Wspo³rzêdna na osi X>*/
	int y;/*!<Wspo³rzêdna na osi Y>*/
	Color color;/*!<kolor punktu>*/
	int thickness;/*!<gruboœæ punktu>*/
public:
	/**
	 * @brief Konstruktor punktu
	 * 
	 */
	Point2D();
	/**
	 * @brief Konstruktor punktu
	 * 
	 * \param x Wspo³rzêdna na osi X
	 * \param y Wspo³rzêdna na osi Y
	 */
	Point2D(int x,int y);
	/**
	 * @brief Konstruktor punktu
	 * 
	 * \param x Wspo³rzêdna na osi X
	 * \param y Wspo³rzêdna na osi Y
	 * \param color kolor punktu
	 * \param thickness gruboœæ punktu
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
	 * \return Wspo³rzêdna na osi X
	 */
	int getX();
	/**
	 * @brief getter Y
	 * 
	 * \return Wspo³rzêdna na osi Y
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
	 * \param x Wspo³rzêdna na osi X
	 */		  
	void setX(int x);
	/**
	 * @brief setter Y
	 * 
	 * \param y Wspo³rzêdna na osi Y
	 */		    
	void setY(int y);
	/**
	 * @brief. Rysuje punkt
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ punkt
	 */
	void draw(RenderWindow *window);
	/**
	 * @brief zamienia punkty
	 * 
	 * \param p1 Wspó³rzêdne jednego punktu
	 * \param p2 Wspó³rzêdne drugiego puntku
	 */
	static void swapPoints(Point2D& p1, Point2D& p2);

	/**
	 * @brief Przesuwa o wspó³rzêdne
	 * 
	 * \param x Wspo³rzêdna na osi X
	 * \param y Wspo³rzêdna na osi Y
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
	 * @brief Skalowanie wzglêdem danego punktu
	 * 
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
};

