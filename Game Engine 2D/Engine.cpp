#include "Engine.h"


//Miejsce na funkcje do zarejestrowania
void playerMoveL()
{
	Engine::getInstance()->player->translate((float) - 1000 * Engine::getInstance()->getDeltaTime().asSeconds(), 0);
}
void playerMoveR()
{
	Engine::getInstance()->player->translate(1000* Engine::getInstance()->getDeltaTime().asSeconds(), 0);
}
void playerMoveT()
{
	Engine::getInstance()->player->translate(0, -1000* Engine::getInstance()->getDeltaTime().asSeconds());
}
void playerMoveB()
{
	Engine::getInstance()->player->translate(0, 1000* Engine::getInstance()->getDeltaTime().asSeconds());
}



void leftFill()
{
	//RenderWindow* windowTmp = Engine::getInstance()->getWindow();
	//PrimitiveRenderer::floodFill(Point2D(Mouse::getPosition(*windowTmp).x, Mouse::getPosition(*windowTmp).y), Color::Red,windowTmp);

}
void rightFill()
{
	//RenderWindow* windowTmp = Engine::getInstance()->getWindow();
	//PrimitiveRenderer::boundryFill(Point2D(Mouse::getPosition(*windowTmp).x, Mouse::getPosition(*windowTmp).y), Color::Blue, Color::White, windowTmp);
}
void windowModeAction()
{

	Engine* engineTmp = Engine::getInstance();
	if (engineTmp->getFullScreenValue())
		engineTmp->changeVideoMode(Style::Default);
	else
		engineTmp->changeVideoMode(Style::Fullscreen);
}
void clearWindow() 
{
	Engine::getInstance()->getWindow()->clear();
	std::cout << "czyszcze";
}
void transformTest()
{
	//std::cout << "d";
	//Engine::getInstance()->point->translate(100, 10);
	//Engine::getInstance()->point->scale(200,250,0.2, 0.2);
	//Engine::getInstance()->point->rotate(300,300,10);

	//Engine::getInstance()->seg->translate(10,30);
	//Engine::getInstance()->seg->rotate(10);
	//Engine::getInstance()->seg->scale(1000, 500, 0.9, -0.9);
}
///////////////////////////////////////



using namespace sf;

Engine* Engine::instance = nullptr;

Engine::Engine(int width, int height, Uint32 mode)
{
	tring = new Triangle(Point2D(700, 300), 100, Color::Green, Color::Red, 5);
	rectn = new Rectangle(Point2D(300, 300), 200, 100, Color::Red, Color::Blue, 5);
	rectn->translate(100, 0);
	rectn->rotate(45);
	rectn->scale(300,400,0.5, 0.5);
	circle = new Circle(Point2D(700, 500), 100, Color::Magenta, Color::Red, 5);

	player = new Player(Point2D(200,200));
	point = new Point2D(200, 200);
	seg = new LineSegment(Point2D(50, 500), Point2D(100, 600));	
	errorEngine.init();
	errorEngine.reportError(ErrorNames::TEST_ERROR,__FILE__,__LINE__);
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

void Engine::setKeyboardEngine(KeyboardEngine* keyboardEngine)
{
	this->keyboardEngine = keyboardEngine;
}

void test()
{
	std::cout << "dziala";
}
void test2()
{
	std::cout << "cos";
}
void Engine::initEngine(int width, int height, Uint32 mode)
{
	fullScreen = false;
	engineWindow = new RenderWindow(VideoMode(width, height), "Engine2d",mode);
	setMaxFPS(60);
	setKeyboardEngine(new KeyboardEngine());
	setMouseEngine(new MouseEngine());
}

void Engine::engineLoop()
{
	keyboardEngine->registerNewAction(Keyboard::A, &playerMoveL, true);
	keyboardEngine->registerNewAction(Keyboard::S, &playerMoveB, true);
	keyboardEngine->registerNewAction(Keyboard::D, &playerMoveR, true);
	keyboardEngine->registerNewAction(Keyboard::W, &playerMoveT, true);


	//keyboardEngine->registerNewAction(Keyboard::A, &doTest2, true);
	
	keyboardEngine->registerNewAction(Keyboard::F11, &windowModeAction, false);
	keyboardEngine->registerNewAction(Keyboard::C, &clearWindow, true);


	mouseEngine->registerNewAction(Mouse::Button::Left, &leftFill,true);
	mouseEngine->registerNewAction(Mouse::Button::Right, &rightFill,true);

	

	while (engineWindow->isOpen())
	{
		engineUpdate();
		enginePoolEvent();
		//draw();
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
	
	
	//point->draw(engineWindow, Color::Blue, 10);
	//seg->draw(engineWindow, Color::Red, 10);
	
}

void Engine::engineRender()
{
	engineWindow->clear();
	player->draw(engineWindow);

	rectn->draw(engineWindow);
	tring->draw(engineWindow);
	circle->draw(engineWindow);

	engineWindow->display();
}

void Engine::setMouseEngine(MouseEngine* mouseEngine)
{
	this->mouseEngine = mouseEngine;
}

void Engine::doTest()
{
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

void Engine::draw()
{
	PrimitiveRenderer::drawCircle(Point2D(200, 500), 100, engineWindow, Color::White, Color::Magenta, 5);


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
	seg->draw(engineWindow, Color(255, 255, 255), 4);

	PrimitiveRenderer::drawCircle8Symmetry(Point2D(400, 500), 30, engineWindow, Color::White, 4);
	PrimitiveRenderer::drawEllipse4Symmetry(Point2D(400, 1000), 100, 600, engineWindow, Color::White, 4);


}

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


