#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "KeyboardEngine.h"
#include "MouseEngine.h"
#include "ErrorEngine.h"
#include "LineSegment.h"
#include "Player.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "BitmapHandler.h"
using namespace sf;


/**
 * @brief Klasa silnia
 */
class Engine
{
protected:
	/**
	 * @brief Konstruktor
	 * 
	 * \param width Szeroko��
	 * \param height Wysoko��
	 * \param mode Tryb screena
	 */
	Engine(int width,int height,Uint32 mode);
	static Engine* instance;/*!<Instancja silnika>*/
	
public:

	/**
	 * @brief Usuni�cie jednego z domy�lnych konstruktor�w
	 * 
	 * \param other 
	 */
	Engine(Engine& other) = delete;
	/**
	 * @brief Usuni�cie operatora przypisania
	 * 
	 * \param 
	 */
	void operator=(const Engine&) = delete;

	/**
	 * @brief.
	 * 
	 * \param width Szeroko��
	 * \param height Wysoko��
	 * \param mode Tryb screena
	 * \return Instancje silnika
	 */
	static Engine* getInstance(int width, int height, Uint32 mode = Style::Close);
	/**
	 * @brief Getter instancji
	 * 
	 * \return Instancje silnika
	 */
	static Engine* getInstance();

	/**
	 * @brief Zmiana trybu gry(Screena)
	 * 
	 * \param width Szeroko��
	 * \param height Wysoko��
	 * \param height Tryb screena
	 */
	void changeVideoMode(Uint32 mode, int width = 1280, int height = 720);
	/**
	 * @brief Uruchomienie silnika
	 * 
	 */
	void start();

	/**
	 * @brief Ustawienie fps
	 * 
	 * \param n Ilo�� fps
	 */
	void setMaxFPS(int n);
	/**
	 * @brief Czy full screen 
	 * 
	 * \return Czy fullscreen
	 */
	bool getFullScreenValue();
	/**
	 * @brief Zwraca wska�nik do okna gry
	 * 
	 * \return Wska�nik do okna gry
	 */
	RenderWindow* getWindow();
	
	Player* player;/*!<Gracz>*/

	Circle* trng;/*!<Ko�o>*/
	


	/**
	 * @brief Zwraca czas pomi�dzy klatkami
	 * 
	 * \return czas pomi�dzy klatkami
	 */
	Time getDeltaTime();
private:
	
	KeyboardEngine* keyboardEngine;/*!<Silnik obs�ugi klawiatury>*/
	MouseEngine* mouseEngine;/*!<Silnik obs�ugi myszki>*/
	RenderWindow* engineWindow;/*!<Okno gry>*/
	BitmapHandler bitmapHandler;/*!<Repozytorium tekstur>*/
	Event event;/*!<obiekt z informacjami o zdarzeniach>*/
	Clock mainClock;/*!<Zegar>*/
	Time deltaTime;/*!<Czas pomi�dzy klatkami>*/

	bool fullScreen;/*!<Czy fullscreen>*/
	bool videoModeChange;/*!<Czy sie mode zmienia>*/

	/**
	 * @brief �adowanie tekstur 
	 * 
	 */
	void loadTextures();
	/**
	 * @brief Ustawienie domy�lnego silnika klawiatury
	 * 
	 * \param keyboardEngine
	 */
	void setKeyboardEngine(KeyboardEngine* keyboardEngine);
	/**
	 * @brief Ustawienie domy�lnego silnika myszy
	 * 
	 * \param mouseEngine
	 */
	void setMouseEngine(MouseEngine* mouseEngine);
	/**
	 * @brief Inicjalizacja silnika
	 * 
	 * \param width
	 * \param height
	 * \param mode
	 */
	void initEngine(int width, int height, Uint32 mode);
	/**
	 * @brief P�tla g��wna silnika
	 * 
	 */
	void engineLoop();
	/**
	 * @brief Czytanie zdarze�
	 * 
	 */
	void enginePoolEvent();
	/**
	 * @brief Aktualizacja silnika
	 * 
	 */
	void engineUpdate();
	/**
	 * @brief Renderowanie silnika 
	 * 
	 */
	void engineRender();
	/**
	 * @brief Aktualizacja czasu
	 * 
	 */
	void updateTimer();
	/**
	 * @brief Ko�czenie silnika 
	 * 
	 */
	void endGame();
	/**
	 * @brief Ob�uga event�w okna
	 * 
	 */
	void poolBasicEvent();
	/**
	 * @brief Akcja po zmianie rozmiaru okna
	 * 
	 */
	void windowResized();
	/**
	 * @brief Akcja po focus okna
	 * 
	 */
	void windowGainedFocus();
	/**
	 * @brief Akcja po utracie focus okna
	 * 
	 */
	void windowLostFocus();
	/**
	 * @brief Zmiana trybu okna
	 * 
	 */
	void windowModeChange();

};


