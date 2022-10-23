#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <ctime>
enum ErrorNames
		{
			TEST_ERROR
		};
class ErrorEngine
{
private:
	std::map<ErrorNames, std::string> errorDescriptions;
public:
	void init();
	void reportError(ErrorNames error, std::string name,int line);
};


