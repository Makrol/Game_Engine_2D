#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <ctime>
#include <SFML/Graphics.hpp>
/**
 * @brief Nazwy Error�w
 */
enum ErrorNames
{
	TEST_ERROR,
	TEXTURE_ERROR
};
/**
 * @brief Klasa obs�uguj�ca b��dy
 */
class ErrorEngine
{

private:
	 std::map<ErrorNames, std::string> errorDescriptions/*!<Mapa ��cz�ca nazwe errora z jego opisem>*/;
	 /**
	  * @brief.
	  * 
	  */
	 void init();
public:
	/**
	 * @brief Wy�wietla messagebox i zapisuje do pliku szczeg�owe informacje o b��du  
	 * 
	 * \param error nazwa b��du
	 * \param name nazwa pliku w kt�rym wyst�pi� b��d
	 * \param desc opis b��du
	 * \param line linia w kt�rej wyst�pi� b��d
	 */
	void reportError(ErrorNames error,std::string name, std::string desc,int line);
};


