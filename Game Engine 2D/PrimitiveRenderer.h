#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <stack>
using namespace sf;

/**
 * @brief Rysowanie prymitywów
 */
class PrimitiveRenderer
{
private:
	/**
	 * @brief Wykrywanie i obs³uga kolizji linii
	 * 
	 * \param p1 Wspó³rzêdne koñca jednej linii
	 * \param p2 Wspó³rzêdne koñca jednej linii
	 * \param p3 Wspó³rzêdne koñca drugiej linii
	 * \param p4 Wspó³rzêdne koñca drugiej linii
	 * \return 
	 */
	static bool isColision(Point2D &p1, Point2D& p2, Point2D& p3, Point2D& p4);
public:
	/**
	 * @brief Rysuje linie
	 * 
	 * \param p1 Wspó³rzêdne koñca linii
	 * \param p2 Wspó³rzêdne koñca linii
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ linia
	 * \param color Kolor linii
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawLine(Point2D p1, Point2D p2, RenderWindow* window,Color color,int thickness);
	/**
	 * @brief Rysuje prostok¹t
	 * 
	 * \param p1 Punkt
	 * \param sizeX Rozmiar X
	 * \param sizeY Rozmiar Y
	 * \param border Kolor obramowania
	 * \param fill Wype³nienie kolorem figury
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawRectangle(Point2D p1, int sizeX, int sizeY, Color border, Color fill,RenderWindow* window,int thickness);
	/**
	 * @brief Rysuje trójk¹t
	 * 
	 * \param p1 Punkt
	 * \param size Rozmiar
	 * \param border Kolor obramowania
	 * \param fill Wype³nienie kolorem figury
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawTriangle(Point2D p1, int size, Color border, Color fill,RenderWindow* window,int thickness);
	/**
	 * @brief Rysuje ko³o 
	 * 
	 * \param p1 Punkt
	 * \param size Rozmiar
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param border Kolor obramowania
	 * \param fill Wype³nienie kolorem figury
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawCircle(Point2D p1, int size,RenderWindow* window, Color border, Color fill,int thickness);
	/**
	 * @brief Rysuje wielok¹t z detekcj¹ przecinania siê œcian
	 * 
	 * \param pointTab Tablica punktów
	 * \param color Kolor linii
	 * \param pointsNumber Iloœæ punktów
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawPolygon(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,int thickness);
	/**
	 * @brief Rysuje ko³o z 8 liniami symetrii
	 * 
	 * \param p1 Punkt
	 * \param radius Promieñ
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param color Kolor linii
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawCircle8Symmetry(Point2D p1, int radius,RenderWindow *window,Color color,int thickness);
	/**
	 * @brief Rysuje elipse z 4 liniami symetrii 
	 * 
	 * \param p1 Punkt
	 * \param radiusX Promieñ na osi X
	 * \param radiusY Promieñ na osi Y
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param color Kolor linii
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawEllipse4Symmetry(Point2D p1, int radiusX,int radiusY,RenderWindow *window,Color color,int thickness);
	/**
	 * @brief Rysuje ³aman¹ linie 
	 * 
	 * \param pointTab Tablica punktów
	 * \param color Kolor linii
	 * \param pointsNumber Iloœæ punktów
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 * \param isOpen Sprawdza czy otwarte
	 * \param thickness Gruboœæ obramowania
	 */
	static void drawBrokenLine(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,bool isOpen,int thickness);
	/**
	 * @brief Wype³nia kolorem do momentu znalezienia innego koloru 
	 * 
	 * \param start Wspó³rzêdne piksela
	 * \param filColor Wybrany kolor wype³nienia
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	static void floodFill(Point2D start, Color filColor, RenderWindow* window);
	/**
	 * @brief Wype³nia figure do obramowania
	 * 
	 * \param start Wspó³rzêdne piksela  
	 * \param filColor Wybrany kolor wype³nienia
	 * \param borderColor Kolor obramowania
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	static void boundryFill(Point2D start, Color filColor, Color borderColor, RenderWindow* window);
};

