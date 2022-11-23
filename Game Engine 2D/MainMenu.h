#pragma once

#include "Button.h"
#include <stack>
#include "BitmapHandler.h"
#include "BitmapObject.h"
#include "TransformableObject.h"

//using namespace sf;
/**
 * @brief Struktura stanów silnika gry
 *
 */
enum stateTitle { MAINMENU, GAME,DEMO, EXIT };
/**
 * @brief Klasa menu g³ównego gry
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
	//Texture backgroundTexture;/*!<Tekstura t³a menu g³ównego>*/
	//Sprite background;/*!<T³o menu g³ównego>*/
public:
	/**
	* @brief Konstruktor inicjuj¹cy menu g³ówne
	*
	* @param screanSize
	*/
	MainMenu(BitmapHandler* bitmapHandler, std::stack<int>* gameState,Vector2f screanSize, bool* gameModeChanged);
	/**
	 * @brief Niszczenie menu g³ównego
	 *
	 */
	~MainMenu();
	/**
	 * @brief Aktualizacja menu g³ównego
	 *
	 * @param window wskaŸnik do okna gry
	 * @param gameState referencja do stosu zawieraj¹cego obecy stan silnika gry
	 * @param health ¿ycie gracza
	 * @return true - je¿eli wcisniêto przycisk newGame
	 * @return false - wpozosta³ych przypadkach
	 */
	void update(RenderWindow* window);
	/**
	 * @brief Wyœwietlanie menu g³ownego
	 *
	 * @param target wskaŸnik na okno gry
	 */
	void draw(RenderWindow* window);
};

