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

using namespace sf;



class Engine
{
protected:
	Engine(int width,int height,Uint32 mode);
	static Engine* instance;
	
public:
	LineSegment* seg;
	Point2D* point;


	std::string testcos;

	Engine(Engine& other) = delete;
	void operator=(const Engine&) = delete;

	static Engine* getInstance(int width, int height, Uint32 mode = Style::Close);
	static Engine* getInstance();

	void changeVideoMode(Uint32 mode, int width = 1280, int height = 720);
	void start();

	void setMaxFPS(int n);
	bool getFullScreenValue();
	RenderWindow* getWindow();
	Player* player;
	Rectangle* rectn;
	Triangle* tring;
	Circle* circle;


	Time getDeltaTime();
private:
	KeyboardEngine* keyboardEngine;
	MouseEngine* mouseEngine;
	RenderWindow* engineWindow;
	Event event;
	Clock mainClock;
	Time deltaTime;
	ErrorEngine errorEngine;
	bool fullScreen;
	bool videoModeChange;

	void setKeyboardEngine(KeyboardEngine* keyboardEngine);
	void setMouseEngine(MouseEngine* mouseEngine);
	void initEngine(int width, int height, Uint32 mode);
	void engineLoop();
	void enginePoolEvent();
	void engineUpdate();
	void engineRender();
	void updateTimer();
	void endGame();
	void doTest();
	void poolBasicEvent();
	void windowResized();
	void windowGainedFocus();
	void windowLostFocus();
	void windowModeChange();

	void draw();
	
	

};


