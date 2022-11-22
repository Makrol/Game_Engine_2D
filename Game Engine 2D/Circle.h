#pragma once
#include "ShapeObject.h"

#include "Point2D.h"

#include "PrimitiveRenderer.h"
/**
 * @brief Klasa do stworzenia kó³ka
 */
class Circle:public ShapeObject
{
public:
    /**
     * @brief Konstruktor kó³ka
     * 
     * \param position Pozycja 
     * \param Size Rozmiar
     * \param border Kolor obramówki
     * \param fill Wype³nienie kolorem figury
     * \param thickness Gruboœæ obramowania
     */
	Circle(Point2D position, int Size, Color border, Color fill, int thickness);
    /**
     * @brief Rysuje obiekty
     * 
     * \param window window WskaŸnik do okna w którym ma siê pojawiæ figura
     */
    void draw(RenderWindow* window);
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
     * \param angle angle K¹t o jaki ma sie przemieœciæ figura
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

