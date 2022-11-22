#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "Point2D.h"
/**
* @brief Klasa, po której dziedzicz¹ primitywy
*/
class ShapeObject: public DrawableObject,TransformableObject
{
protected:
	Point2D position;/*!<Pozycja>*/
	int xSize;/*!<Rozmiar X>*/
	int ySize;/*!<Rozmiar Y>*/
	Color border;/*!<Kolor obramówki>*/
	Color fill;/*!< Wype³nienie kolorem figury >*/
	int thickness;/*!<Gruboœæ obramowania>*/
public:
	/**
	* @brief Rysowanie obiektu
	*
	* \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	*/
	virtual void draw(RenderWindow* window)=0;
	/**
	 * @brief Przesuniêcie obiektu
	 * 
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 */
	virtual void translate(int x, int y) = 0;
	/**
	 * @brief Obrócenie obiektu wzglêdem punktów 
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */ 
	virtual void rotate(int px, int py, int angle) = 0;
	/**
	 * @brief Obrócenie obiektu
	 * 
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	virtual void rotate(int angle) = 0;
	/**
	 * @brief Skalowanie obiektu wzglêdem podanych punktów 
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	virtual void scale(int px, int py, float kx, float ky) = 0;
	/**
	 * @brief Skalowanie obiektu wzglêdem punktów 0,0
	 * 
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	virtual void scale(float kx, float ky) = 0;
};

