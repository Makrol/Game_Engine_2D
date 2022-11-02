#include "Engine.h"


//Miejsce na funkcje do zarejestrowania
void doTest2()
{




}
void doTest3()
{

}
void windowModeAction()
{

	Engine* engineTmp = Engine::getInstance();
	if (engineTmp->getFullScreenValue())
		engineTmp->changeVideoMode(Style::Default);
	else
		engineTmp->changeVideoMode(Style::Fullscreen);
}
///////////////////////////////////////



using namespace sf;

Engine* Engine::instance = nullptr;

Engine::Engine(int width, int height, Uint32 mode)
{
	seg = new LineSegment(Point2D(0, 0), Point2D(900, 700));	
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
	setMaxFPS(144);
	setKeyboardEngine(new KeyboardEngine());
	setMouseEngine(new MouseEngine());
}

void Engine::engineLoop()
{
	keyboardEngine->registerNewAction(Keyboard::A, &doTest2, true);
	keyboardEngine->registerNewAction(Keyboard::D, &doTest3, false);
	keyboardEngine->registerNewAction(Keyboard::F11, &windowModeAction, false);
	mouseEngine->registerNewAction(Mouse::Button::Left, &doTest2,true);
	mouseEngine->registerNewActionInArea(Mouse::Button::Right, &doTest2,0,0,100,100,true);
	while (engineWindow->isOpen())
	{
		enginePoolEvent();
		engineUpdate();
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
	
	engineWindow->clear();
	PrimitiveRenderer::drawCircle(Point2D(200, 500), 100, engineWindow,Color::Green);
	
	Point2D tmp[] = {
		Point2D(0,0),
		Point2D(100,100),
		Point2D(150,500)
	};
	PrimitiveRenderer::drawPolygon(tmp, Color::Red, 3, engineWindow,true);
	
	PrimitiveRenderer::drawLine(Point2D(100, 50), Point2D(400, 200), engineWindow, Color::Blue);
		
	PrimitiveRenderer::drawRectangle(Point2D(500, 100), 200, 300, Color(0, 255, 255), engineWindow);
	
	PrimitiveRenderer::drawTriangle(Point2D(900, 300), 200, Color::Magenta, engineWindow);
	seg->drawProgressive(engineWindow,Color(255,255,0));
	
}

void Engine::engineRender()
{
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

RenderWindow* Engine::getWindow()
{
	return engineWindow;
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


