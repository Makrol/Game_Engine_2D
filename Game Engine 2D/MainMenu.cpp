#include "MainMenu.h"

MainMenu::MainMenu(BitmapHandler* bitmapHandler, std::stack<int>* gameState,Vector2f screenSize,bool* gameModeChanged)
{
	this->gameModeChanged = gameModeChanged;
	this->gameState = gameState;
	texture = *( bitmapHandler->getTexture("mainMenuBackground"));
	

	gameObjectBody.setTexture(texture);


	
	newGameButton = new Button(bitmapHandler,"buttonNewGame", Vector2f(screenSize.x / 2, screenSize.y * 0.3));
	continueButton = new Button(bitmapHandler, "buttonContinue", Vector2f(screenSize.x / 2, screenSize.y * 0.4));
	exitButton = new Button(bitmapHandler, "buttonExit", Vector2f(screenSize.x / 2, screenSize.y * 0.6));
	demoButton = new Button(bitmapHandler, "buttonDemo", Vector2f(screenSize.x / 2, screenSize.y * 0.5));


	newGameButton->scale(0.4, 0.4);
	continueButton->scale(0.4, 0.4);
	exitButton->scale(0.4, 0.4);
	demoButton->scale(0.4, 0.4);
}

MainMenu::~MainMenu()
{
	delete newGameButton;
	delete continueButton;
	delete exitButton;
}

void MainMenu::update(RenderWindow *window)
{

	if (newGameButton->PressDetection(*window))
	{
		(* gameState).push(GAME);
		*gameModeChanged = true;

	}
	else if (continueButton->PressDetection(*window))
	{
		//if (health > 0)
		(*gameState).push(GAME);
		*gameModeChanged = true;
	}
	else if (demoButton->PressDetection(*window))
	{
		(*gameState).push(DEMO);
		*gameModeChanged = true;
	}
	else if (exitButton->PressDetection(*window))
	{
		(*gameState).push(EXIT);
		*gameModeChanged = true;
	}


}

void MainMenu::draw(RenderWindow* window)
{
	window->draw(gameObjectBody);
	newGameButton->draw(window);
	continueButton->draw(window);
	exitButton->draw(window);
	demoButton->draw(window);
}




