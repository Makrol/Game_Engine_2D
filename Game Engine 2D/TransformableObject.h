#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include "GameObject.h"
/**
 * @brief Abstrakcyjna klasa do transformacji obiektów
 */
class TransformableObject: virtual public GameObject
{
public:
	/**
	 * @brief Przesuniêcie obiektu
	 * 
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X  
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 * \param xm Wartoœci o jakie maj¹ byæ wykonane zmiany na osi X
	 * \param ym Wartoœci o jakie maj¹ byæ wykonane zmiany na osi Y
	 */
	static void translate(int& x, int& y, int xm, int ym);
	/**
	 * @brief Obrócenie obiektu
	 * 
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	static void rotate(int &x,int &y,int px, int py, int angle);
	/**
	 * @brief Skalowanie obiektu wzglêdem podanych punktów  
	 * 
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	static void scale(int& x, int& y, int px, int py, float kx, float ky);
	/**
	 * @brief Przesuwa o wspó³rzêdne
	 * 
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 */
	virtual void translate(int x,int y)=0;
	/**
	 * @brief Rotuje obiekt wzglêdem punktów 
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	virtual void rotate(int px,int py,int angle)=0;
	/**
	 * @brief Rotuj obiekt
	 * 
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	virtual void rotate(int angle)=0;
	/**
	 * @brief Skalowanie obiektu wzglêdem podanych punktów
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	virtual void scale(int px, int py,float kx,float ky)=0;
	/**
	 * @brief Skalowanie obiektu wzglêdem punktów 0,0
	 * 
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	virtual void scale(float kx,float ky)=0;
};

