#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <set>
#include "Vector4d.h"
using namespace sf;

class InputEngine
{
protected:
	std::map<int, Vector4d> keyClickArea;
	std::map<int, void(*)()> keyActionContener;
	std::set<int> spamAbleKeys;
	bool spamButton;
	int lastButton;
	void doAction(Event * eventHendler,RenderWindow* window);

public:
	virtual void pollEvent(Event *eventHendler, RenderWindow* window)=0;
	void registerNewAction(int key, void(*func)(), bool spamAble);
	void registerNewActionInArea(int key, void(*func)(), int px1, int py1, int px2, int py2, bool spamAble);
};

