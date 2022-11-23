#pragma once

#include "Button.h"
#include <stack>
#include "BitmapHandler.h"
#include "BitmapObject.h"
#include "TransformableObject.h"

//using namespace sf;
/**
 * @brief Struktura stan�w silnika gry
 *
 */
enum stateTitle { MAINMENU, GAME,DEMO, EXIT };
/**
 * @brief Klasa menu g��wnego gry
 *
 */
class MainMenu: public BitmapObject
{
private:
	bool* gameModeChanged;
	std::stack<int>* gameState;
	Button* newGameButton;/*!<Przycisk New Game>*/
	Button* continueButton;/*!<Przycisk Continue>*/
	Button* exitButton;/*!<Przycisk Exit>*/
	Button* demoButton;
	//Texture backgroundTexture;/*!<Tekstura t�a menu g��wnego>*/
	//Sprite background;/*!<T�o menu g��wnego>*/
public:
	/**
	* @brief Konstruktor inicjuj�cy menu g��wne
	*
	* @param screanSize
	*/
	MainMenu(BitmapHandler* bitmapHandler, std::stack<int>* gameState,Vector2f screanSize, bool* gameModeChanged);
	/**
	 * @brief Niszczenie menu g��wnego
	 *
	 */
	~MainMenu();
	/**
	 * @brief Aktualizacja menu g��wnego
	 *
	 * @param window wska�nik do okna gry
	 * @param gameState referencja do stosu zawieraj�cego obecy stan silnika gry
	 * @param health �ycie gracza
	 * @return true - je�eli wcisni�to przycisk newGame
	 * @return false - wpozosta�ych przypadkach
	 */
	void update(RenderWindow* window);
	/**
	 * @brief Wy�wietlanie menu g�ownego
	 *
	 * @param target wska�nik na okno gry
	 */
	void draw(RenderWindow* window);
};

