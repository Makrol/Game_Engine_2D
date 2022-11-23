#include "Engine.h"


//Miejsce na funkcje do zarejestrowania
void playerMoveL()
{
	Engine::getInstance()->player->translate((float) - 1300 * Engine::getInstance()->getDeltaTime().asSeconds(), 0);
	Engine::getInstance()->player->lastDirection = 'A';
	Engine::getInstance()->player->animate(Engine::getInstance()->getDeltaTime().asSeconds());
}
void playerMoveR()
{
	Engine::getInstance()->player->translate(1300* Engine::getInstance()->getDeltaTime().asSeconds(), 0);
	Engine::getInstance()->player->lastDirection = 'D';
	Engine::getInstance()->player->animate(Engine::getInstance()->getDeltaTime().asSeconds());
}
void playerMoveT()
{
	Engine::getInstance()->player->translate(0, -1300* Engine::getInstance()->getDeltaTime().asSeconds());
	Engine::getInstance()->player->lastDirection = 'W';
	Engine::getInstance()->player->animate(Engine::getInstance()->getDeltaTime().asSeconds());
}
void playerMoveB()
{
	Engine::getInstance()->player->translate(0, 1300* Engine::getInstance()->getDeltaTime().asSeconds());
	Engine::getInstance()->player->lastDirection = 'S';
	Engine::getInstance()->player->animate(Engine::getInstance()->getDeltaTime().asSeconds());
}
void playerAtack()
{
	Engine::getInstance()->player->atack = true;
	Engine::getInstance()->player->animate(Engine::getInstance()->getDeltaTime().asSeconds());
}
void backMenu()
{
	if(Engine::getInstance()->getGameState()->size()>1)
		Engine::getInstance()->getGameState()->pop();
}
int lineCounter = 0;
Point2D p1;
Point2D p2;
void drawDemoLine()
{
	lineCounter++;
	if (lineCounter == 1)
	{
		p1.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		p1.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);	
	}
	else if (lineCounter == 2)
	{
		p2.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		p2.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);

		Engine::getInstance()->getWindow()->display();
		PrimitiveRenderer::drawLine(p1, p2, Engine::getInstance()->getWindow(), Color::Red, 3);
		Engine::getInstance()->getWindow()->display();
		lineCounter = 0;
	}
	
}

int polygonCounter = 0;
Point2D polygonPoints[100];
void drawDemoPolygon()
{
	polygonPoints[polygonCounter] = Point2D(Mouse::getPosition(*Engine::getInstance()->getWindow()).x, Mouse::getPosition(*Engine::getInstance()->getWindow()).y);
	polygonCounter++;

	//polygonPoints.push_back(Point2D());
	//polygonCounter++;
}
void renderPolygon()
{
	//PrimitiveRenderer::drawPolygon(polygonPoints, Color::Blue, polygonCounter,Engine::getInstance()->getWindow(), 3);
	Engine::getInstance()->getWindow()->display();

	PrimitiveRenderer::drawPolygon(polygonPoints, Color::Blue, polygonCounter, Engine::getInstance()->getWindow(),3);

	Engine::getInstance()->getWindow()->display();
	//PrimitiveRenderer::drawBrokenLine()
	polygonCounter = 0;
	//polygonPoints.clear();
}
Point2D pc1;
Point2D pc2;
int circleCounter = 0;
void drawCircle()
{
	circleCounter++;
	if (circleCounter == 1)
	{
		pc1.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pc1.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);
	}
	else if (circleCounter == 2)
	{
		pc2.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pc2.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);

		Point2D center(abs((pc1.getX()+pc2.getX())/2),abs((pc1.getY() + pc2.getY()) / 2));
		int radius = sqrt(pow(abs((pc1.getX() - pc2.getX())),2)+pow(abs((pc1.getY() - pc2.getY())),2))/2;

		//Engine::getInstance()->getWindow()->display();
		PrimitiveRenderer::drawCircle8Symmetry(center,radius,Engine::getInstance()->getWindow(),Color::Cyan,3);
		Engine::getInstance()->getWindow()->display();
		circleCounter = 0;
	}
}

void fillColor()
{
	RenderWindow* window = Engine::getInstance()->getWindow();
	//window->display();
	PrimitiveRenderer::floodFill(Point2D(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y), Color::White, window);
	window->display();
}
Point2D pe1;
Point2D pe2;
int elipseCounter = 0;
void drawElips()
{
	elipseCounter++;
	if (elipseCounter == 1)
	{
		pe1.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pe1.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);
	}
	else if (elipseCounter == 2)
	{
		pe2.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pe2.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);

		Point2D center(abs((pe1.getX() + pe2.getX()) / 2), abs((pe1.getY() + pe2.getY()) / 2));
		int radius1 = abs((pe1.getX() - pe2.getX()) / 2);
		int radius2 = abs((pe1.getY() - pe2.getY()) / 2);

		PrimitiveRenderer::drawEllipse4Symmetry(center, radius1, radius2, Engine::getInstance()->getWindow(), Color::Green, 3);
		Engine::getInstance()->getWindow()->display();
		elipseCounter = 0;
	}
}
int brokenCounter = 0;
Point2D brokenPoints[100];
void drawBrokenLine()
{
	brokenPoints[brokenCounter] = Point2D(Mouse::getPosition(*Engine::getInstance()->getWindow()).x, Mouse::getPosition(*Engine::getInstance()->getWindow()).y);
	brokenCounter++;
}
void renderBrokenLine()
{
	Engine::getInstance()->getWindow()->display();

	PrimitiveRenderer::drawBrokenLine(brokenPoints, Color(172, 168, 1), brokenCounter, Engine::getInstance()->getWindow(),true, 3);

	Engine::getInstance()->getWindow()->display();
	brokenCounter = 0;

}
void drawByMouse()
{
	Point2D(Mouse::getPosition(*Engine::getInstance()->getWindow()).x, Mouse::getPosition(*Engine::getInstance()->getWindow()).y,Color(172,1,172),3).draw(Engine::getInstance()->getWindow());
	Engine::getInstance()->getWindow()->display();
}
Point2D pr1;
Point2D pr2;
int rectCounter = 0;
void drawRect()
{
	rectCounter++;
	if (rectCounter == 1)
	{
		pr1.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pr1.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);
	}
	else if (rectCounter == 2)
	{
		pr2.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pr2.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);

		int tmp;
		if (pr1.getX() > pr2.getX())
		{
			tmp = pr1.getX();
			pr1.getXRef() = pr2.getX();
			pr2.getXRef() = tmp;
		}

		if (pr1.getY() > pr2.getY())
		{
			tmp = pr1.getY();
			pr1.getYRef() = pr2.getY();
			pr2.getYRef() = tmp;
		}


		int xSize = abs(pr1.getX()-pr2.getX());
		int ySize = abs(pr1.getY() - pr2.getY());

		Engine::getInstance()->getWindow()->display();
		PrimitiveRenderer::drawRectangle(pr1, xSize, ySize, Color::Magenta, Color::Transparent, Engine::getInstance()->getWindow(), 3);
		Engine::getInstance()->getWindow()->display();
		rectCounter = 0;
	}
}

Point2D pt1;
Point2D pt2;
int triaCounter = 0;
void drawTria()
{
	triaCounter++;
	if (triaCounter == 1)
	{
		pt1.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pt1.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);
	}
	else if (triaCounter == 2)
	{
		pt2.setX(Mouse::getPosition(*Engine::getInstance()->getWindow()).x);
		pt2.setY(Mouse::getPosition(*Engine::getInstance()->getWindow()).y);


		int tmp;
		if (pt1.getX() > pt2.getX())
		{
			tmp = pt1.getX();
			pt1.getXRef() = pt2.getX();
			pt2.getXRef() = tmp;
		}

		if (pt1.getY() > pt2.getY())
		{
			tmp = pt1.getY();
			pt1.getYRef() = pt2.getY();
			pt2.getYRef() = tmp;
		}


		Point2D center(abs((pt1.getX() + pt2.getX()) / 2), abs((pt1.getY() + pt2.getY()) / 2));
		int radius = sqrt(pow(abs((pt1.getX() - pt2.getX())), 2) + pow(abs((pt1.getY() - pt2.getY())), 2)) / 2;





		PrimitiveRenderer::drawTriangle(pt1, radius, Color(112, 74, 187), Color::Transparent, Engine::getInstance()->getWindow(),3);
		Engine::getInstance()->getWindow()->display();
		triaCounter = 0;
	}
}

void playerRotate()
{
	Engine::getInstance()->player->rotate(0, 0, 10);
}
void windowModeAction()
{

	Engine* engineTmp = Engine::getInstance();
	if (engineTmp->getFullScreenValue())
	{
		engineTmp->changeVideoMode(Style::Default);
	}
	else
	{
		engineTmp->changeVideoMode(Style::Fullscreen);
	}
	engineTmp->getWindow()->display();
		
}

void playerScaleUp()
{
	Engine::getInstance()->player->scale(950, 450, 1.3,1.3);
}
void playerScaleDown()
{
	Engine::getInstance()->player->scale(950, 450, 0.9, 0.9);
}
void clearWindow()
{
	Engine::getInstance()->getWindow()->clear();
	Engine::getInstance()->getWindow()->display();
}


///////////////////////////////////////



using namespace sf;

Engine* Engine::instance = nullptr;

Engine::Engine(int width, int height, Uint32 mode)
{
	gameModeChanged = false;
	gameState.push(MAINMENU);
	loadTextures();
	grass = new GrassModule(*bitmapHandler.getTexture("grass"));
	menu = new MainMenu(&bitmapHandler, &gameState, Vector2f(width, height),&gameModeChanged);


	player = new Player(Point2D(200,200),&bitmapHandler);
	player->scale(2, 2);

	initEngine(width,height,mode);
}


Engine* Engine::getInstance(int width, int height, Uint32 mode)
{
	if (instance == nullptr)
	{
		instance = new Engine(width,height,mode);
	}
	return instance;
}

Engine* Engine::getInstance()
{
	return instance;
}

void Engine::changeVideoMode(Uint32 mode, int width,int height)
{
	delete engineWindow;
	if (mode == Style::Fullscreen)
	{
		engineWindow = new RenderWindow(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Engine2d", mode);
		fullScreen = true;
	}
	else
	{
		engineWindow = new RenderWindow(VideoMode(width, height), "Engine2d", mode);
		fullScreen = false;
	}
	videoModeChange = true;
}

void Engine::start()
{
	engineLoop();
}

void Engine::loadTextures()
{
	bitmapHandler.loadBitmap("playerD1", "player/d1.png");
	bitmapHandler.loadBitmap("playerD2", "player/d2.png");
	bitmapHandler.loadBitmap("playerD3", "player/d3.png");
	bitmapHandler.loadBitmap("playerD4", "player/d4.png");
	bitmapHandler.loadBitmap("playerD5", "player/d5.png");

	bitmapHandler.loadBitmap("playerDA6", "player/da6.png");
	bitmapHandler.loadBitmap("playerDA7", "player/da7.png");
	bitmapHandler.loadBitmap("playerDA8", "player/da8.png");
	
	bitmapHandler.loadBitmap("playerL1", "player/l1.png");
	bitmapHandler.loadBitmap("playerL2", "player/l2.png");
	bitmapHandler.loadBitmap("playerL3", "player/l3.png");
	bitmapHandler.loadBitmap("playerL4", "player/l4.png");
	bitmapHandler.loadBitmap("playerL5", "player/l5.png");

	bitmapHandler.loadBitmap("playerLA6", "player/la6.png");
	bitmapHandler.loadBitmap("playerLA7", "player/la7.png");
	bitmapHandler.loadBitmap("playerLA8", "player/la8.png");
	
	bitmapHandler.loadBitmap("playerP1", "player/p1.png");
	bitmapHandler.loadBitmap("playerP2", "player/p2.png");
	bitmapHandler.loadBitmap("playerP3", "player/p3.png");
	bitmapHandler.loadBitmap("playerP4", "player/p4.png");
	bitmapHandler.loadBitmap("playerP5", "player/p5.png");

	bitmapHandler.loadBitmap("playerPA6", "player/pa6.png");
	bitmapHandler.loadBitmap("playerPA7", "player/pa7.png");
	bitmapHandler.loadBitmap("playerPA8", "player/pa8.png");
	
	bitmapHandler.loadBitmap("playerG1", "player/g1.png");
	bitmapHandler.loadBitmap("playerG2", "player/g2.png");
	bitmapHandler.loadBitmap("playerG3", "player/g3.png");
	bitmapHandler.loadBitmap("playerG4", "player/g4.png");
	bitmapHandler.loadBitmap("playerG5", "player/g5.png");

	bitmapHandler.loadBitmap("playerGA6", "player/ga6.png");
	bitmapHandler.loadBitmap("playerGA7", "player/ga7.png");
	bitmapHandler.loadBitmap("playerGA8", "player/ga8.png");


	bitmapHandler.loadBitmap("mainMenuBackground", "MainMenu/BACKGROUND.png");
	bitmapHandler.loadBitmap("buttonNewGame", "MainMenu/NEWGAME.png");
	bitmapHandler.loadBitmap("buttonContinue", "MainMenu/CONTINUE.png");
	bitmapHandler.loadBitmap("buttonExit", "MainMenu/EXIT.png");
	bitmapHandler.loadBitmap("buttonDemo", "MainMenu/ENGINEDEMO.png");

	bitmapHandler.loadBitmap("grass", "Grass/grass.png");



}

void Engine::setKeyboardEngine(KeyboardEngine* keyboardEngine)
{
	this->keyboardEngine = keyboardEngine;
}

void Engine::initEngine(int width, int height, Uint32 mode)
{
	fullScreen = false;
	engineWindow = new RenderWindow(VideoMode(width, height), "Engine2d",mode);
	//setMaxFPS(60);
	setKeyboardEngine(new KeyboardEngine());
	setMouseEngine(new MouseEngine());
}

void Engine::engineLoop()
{
	initGameInput();

	

	while (engineWindow->isOpen())
	{
		engineUpdate();
		enginePoolEvent();
		engineRender();
		updateTimer();
	}
	endGame();
}

void Engine::enginePoolEvent()
{
	while (engineWindow->pollEvent(event))
	{
		mouseEngine->pollEvent(&event,engineWindow);
		keyboardEngine->pollEvent(&event, engineWindow);
		poolBasicEvent();
	}
}

void Engine::engineUpdate()
{
	if (gameModeChanged)
	{
		mouseEngine->reset();
		keyboardEngine->reset();

		switch (gameState.top())
		{
		case GAME:
			initGameInput();
		break;
		case MAINMENU:
			
		break;
		case DEMO:
			initDemoInput();
			clearWindow();
		break;

		default:
			break;
		}



		gameModeChanged = false;
	}


	if (gameState.top() == GAME)
	{
		
	}
	else if(gameState.top() == MAINMENU)
	{
		menu->update(engineWindow);
	}
}
void Engine::engineRender()
{

	if (gameState.top() == GAME)
	{
		engineWindow->clear();
		grass->draw(engineWindow);
		player->draw(engineWindow);
		engineWindow->display();
		

	}
	else if (gameState.top()==MAINMENU)
	{
		menu->draw(engineWindow);
		engineWindow->display();
	}
	else if(gameState.top() == DEMO)
	{
		
		
		
	}
	else
	{
		exit(0);
	}


	

	
}

void Engine::setMouseEngine(MouseEngine* mouseEngine)
{
	this->mouseEngine = mouseEngine;
}

void Engine::updateTimer()
{
	deltaTime = mainClock.restart();
}

void Engine::endGame()
{
}

void Engine::poolBasicEvent()
{
	switch (event.type)
	{
	case Event::Closed:
		engineWindow->close();
		break;
	case Event::Resized:
		windowResized();
		break;
	case Event::GainedFocus:
		windowGainedFocus();
		break;
	case Event::LostFocus:
		windowLostFocus();
		break;
	default:
		if (videoModeChange)
		{
			windowModeChange();
			videoModeChange = false;
		}
	}
}

void Engine::windowResized()
{
	
}

void Engine::windowModeChange()
{
	
}
void Engine::initGameInput()
{
	keyboardEngine->registerNewAction(Keyboard::A, &playerMoveL, true);
	keyboardEngine->registerNewAction(Keyboard::S, &playerMoveB, true);
	keyboardEngine->registerNewAction(Keyboard::D, &playerMoveR, true);
	keyboardEngine->registerNewAction(Keyboard::W, &playerMoveT, true);
	keyboardEngine->registerNewAction(Keyboard::R, &playerRotate, false);
	keyboardEngine->registerNewAction(Keyboard::O, &playerScaleUp, false);
	keyboardEngine->registerNewAction(Keyboard::L, &playerScaleDown, false);
	keyboardEngine->registerNewAction(Keyboard::Space, &playerAtack, true);
	keyboardEngine->registerNewAction(Keyboard::F11, &windowModeAction, false);
	keyboardEngine->registerNewAction(Keyboard::Escape, &backMenu, false);

}
void Engine::initDemoInput()
{
	keyboardEngine->registerNewAction(Keyboard::C, &clearWindow, false);
	keyboardEngine->registerNewAction(Keyboard::L, &drawDemoLine, false);
	keyboardEngine->registerNewAction(Keyboard::P, &drawDemoPolygon, false);
	keyboardEngine->registerNewAction(Keyboard::D, &renderPolygon, false);
	keyboardEngine->registerNewAction(Keyboard::K, &drawCircle, false);
	keyboardEngine->registerNewAction(Keyboard::F, &fillColor, false);
	keyboardEngine->registerNewAction(Keyboard::E, &drawElips, false);
	keyboardEngine->registerNewAction(Keyboard::B, &drawBrokenLine, false);
	keyboardEngine->registerNewAction(Keyboard::R, &renderBrokenLine, false);
	keyboardEngine->registerNewAction(Keyboard::V, &drawByMouse, true);
	keyboardEngine->registerNewAction(Keyboard::S, &drawRect, true);
	keyboardEngine->registerNewAction(Keyboard::T, &drawTria, true);

	keyboardEngine->registerNewAction(Keyboard::Escape, &backMenu, false);
	keyboardEngine->registerNewAction(Keyboard::F11, &windowModeAction, false);


}
void Engine::clearInput()
{
	
}
std::stack<int>* Engine::getGameState()
{
	return &gameState;
}
/*
void Engine::draw()
{
	//PrimitiveRenderer::drawCircle(Point2D(200, 500), 100, engineWindow, Color::White, Color::Magenta, 5);


	Point2D tmp[] = {
		Point2D(0,0),
		Point2D(100,100),
		Point2D(150,500),
		Point2D(250,500),
		Point2D(250,40)
	};


	Point2D tmp2[] = {
		Point2D(0,300),
		Point2D(400,100),
		Point2D(500,50),
		Point2D(250,100),
		Point2D(600,600)
	};
	PrimitiveRenderer::drawPolygon(tmp, Color::White, 5, engineWindow, 5);

	PrimitiveRenderer::drawBrokenLine(tmp2, Color::White, 5, engineWindow, false, 5);

	PrimitiveRenderer::drawLine(Point2D(100, 50), Point2D(400, 200), engineWindow, Color::White, 4);

	PrimitiveRenderer::drawRectangle(Point2D(600, 100), 200, 300, Color::White,Color::Magenta, engineWindow, 5);

	PrimitiveRenderer::drawTriangle(Point2D(900, 300), 200, Color::White, Color::Magenta, engineWindow, 5);
	//seg->draw(engineWindow, Color(255, 255, 255), 4);

	PrimitiveRenderer::drawCircle8Symmetry(Point2D(400, 500), 30, engineWindow, Color::White, 4);
	PrimitiveRenderer::drawEllipse4Symmetry(Point2D(400, 1000), 100, 600, engineWindow, Color::White, 4);


}
*/
RenderWindow* Engine::getWindow()
{
	return engineWindow;
}

Time Engine::getDeltaTime()
{
	return deltaTime;
}

void Engine::windowGainedFocus()
{

}
void Engine::windowLostFocus()
{

}


void Engine::setMaxFPS(int n)
{
	engineWindow->setFramerateLimit(n);
}

bool Engine::getFullScreenValue()
{
	return fullScreen;
}


