#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <stack>
using namespace sf;

/**
 * @brief Rysowanie prymityw�w
 */
class PrimitiveRenderer
{
private:
	/**
	 * @brief Wykrywanie i obs�uga kolizji linii
	 * 
	 * \param p1 Wsp�rz�dne ko�ca jednej linii
	 * \param p2 Wsp�rz�dne ko�ca jednej linii
	 * \param p3 Wsp�rz�dne ko�ca drugiej linii
	 * \param p4 Wsp�rz�dne ko�ca drugiej linii
	 * \return 
	 */
	static bool isColision(Point2D &p1, Point2D& p2, Point2D& p3, Point2D& p4);
public:
	/**
	 * @brief Rysuje linie
	 * 
	 * \param p1 Wsp�rz�dne ko�ca linii
	 * \param p2 Wsp�rz�dne ko�ca linii
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� linia
	 * \param color Kolor linii
	 * \param thickness Grubo�� obramowania
	 */
	static void drawLine(Point2D p1, Point2D p2, RenderWindow* window,Color color,int thickness);
	/**
	 * @brief Rysuje prostok�t
	 * 
	 * \param p1 Punkt
	 * \param sizeX Rozmiar X
	 * \param sizeY Rozmiar Y
	 * \param border Kolor obramowania
	 * \param fill Wype�nienie kolorem figury
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param thickness Grubo�� obramowania
	 */
	static void drawRectangle(Point2D p1, int sizeX, int sizeY, Color border, Color fill,RenderWindow* window,int thickness);
	/**
	 * @brief Rysuje tr�jk�t
	 * 
	 * \param p1 Punkt
	 * \param size Rozmiar
	 * \param border Kolor obramowania
	 * \param fill Wype�nienie kolorem figury
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param thickness Grubo�� obramowania
	 */
	static void drawTriangle(Point2D p1, int size, Color border, Color fill,RenderWindow* window,int thickness);
	/**
	 * @brief Rysuje ko�o 
	 * 
	 * \param p1 Punkt
	 * \param size Rozmiar
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param border Kolor obramowania
	 * \param fill Wype�nienie kolorem figury
	 * \param thickness Grubo�� obramowania
	 */
	static void drawCircle(Point2D p1, int size,RenderWindow* window, Color border, Color fill,int thickness);
	/**
	 * @brief Rysuje wielok�t z detekcj� przecinania si� �cian
	 * 
	 * \param pointTab Tablica punkt�w
	 * \param color Kolor linii
	 * \param pointsNumber Ilo�� punkt�w
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param thickness Grubo�� obramowania
	 */
	static void drawPolygon(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,int thickness);
	/**
	 * @brief Rysuje ko�o z 8 liniami symetrii
	 * 
	 * \param p1 Punkt
	 * \param radius Promie�
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param color Kolor linii
	 * \param thickness Grubo�� obramowania
	 */
	static void drawCircle8Symmetry(Point2D p1, int radius,RenderWindow *window,Color color,int thickness);
	/**
	 * @brief Rysuje elipse z 4 liniami symetrii 
	 * 
	 * \param p1 Punkt
	 * \param radiusX Promie� na osi X
	 * \param radiusY Promie� na osi Y
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param color Kolor linii
	 * \param thickness Grubo�� obramowania
	 */
	static void drawEllipse4Symmetry(Point2D p1, int radiusX,int radiusY,RenderWindow *window,Color color,int thickness);
	/**
	 * @brief Rysuje �aman� linie 
	 * 
	 * \param pointTab Tablica punkt�w
	 * \param color Kolor linii
	 * \param pointsNumber Ilo�� punkt�w
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 * \param isOpen Sprawdza czy otwarte
	 * \param thickness Grubo�� obramowania
	 */
	static void drawBrokenLine(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,bool isOpen,int thickness);
	/**
	 * @brief Wype�nia kolorem do momentu znalezienia innego koloru 
	 * 
	 * \param start Wsp�rz�dne piksela
	 * \param filColor Wybrany kolor wype�nienia
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 */
	static void floodFill(Point2D start, Color filColor, RenderWindow* window);
	/**
	 * @brief Wype�nia figure do obramowania
	 * 
	 * \param start Wsp�rz�dne piksela  
	 * \param filColor Wybrany kolor wype�nienia
	 * \param borderColor Kolor obramowania
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 */
	static void boundryFill(Point2D start, Color filColor, Color borderColor, RenderWindow* window);
};

