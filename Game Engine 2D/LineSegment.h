#pragma once
#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"
using namespace sf;
/**
 * @brief Linia miêdzy dwoma punktami
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
	 * @brief Getter 1 koñca linii
	 * 
	 * \return 
	 */
	Point2D getFirst();
	/**
	 * @brief Getter 2 koñca linii
	 * 
	 * \return 
	 */
	Point2D getSecond();

	/**
	 * @brief Setter 1 koñca linii
	 * 
	 * \param point
	 */
	void setFirst(Point2D point);
	/**
	 * @brief Setter 2 koñca linii
	 * 
	 * \param point
	 */
	void setSecond(Point2D point);
	/**
	 * @brief Rysuje linie podstawowym algorytmem SFML
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param color Kolor
	 */
	void drawDefault(RenderWindow* window,Color color);
	/**
	 * @brief Rysuje linie algorytmem przyrostowym
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param color Kolor
	 * \param thickness Gruboœæ linii
	 */
	void draw(RenderWindow* window,Color color, int thickness);


	/**
	 * @brief Przemieszcza linie
	 * 
	 * \param x Wspó³rzêdna X
	 * \param y Wspó³rzêdna Y
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotacja wzglêdem podanych punktów
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
	 * @brief Skalowanie wzglêdem punktu 0,0
	 * 
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
private:
	Point2D first;/*!<>*/
	Point2D second;/*!<>*/
	
};

