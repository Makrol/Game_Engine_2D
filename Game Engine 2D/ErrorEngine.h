#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <ctime>
#include <SFML/Graphics.hpp>
/**
 * @brief Nazwy Errorów
 */
enum ErrorNames
{
	TEST_ERROR,
	TEXTURE_ERROR
};
/**
 * @brief Klasa obs³uguj¹ca b³êdy
 */
class ErrorEngine
{

private:
	 std::map<ErrorNames, std::string> errorDescriptions/*!<Mapa ³¹cz¹ca nazwe errora z jego opisem>*/;
	 /**
	  * @brief.
	  * 
	  */
	 void init();
public:
	/**
	 * @brief Wyœwietla messagebox i zapisuje do pliku szczegó³owe informacje o b³êdu  
	 * 
	 * \param error nazwa b³êdu
	 * \param name nazwa pliku w którym wyst¹pi³ b³¹d
	 * \param desc opis b³êdu
	 * \param line linia w której wyst¹pi³ b³¹d
	 */
	void reportError(ErrorNames error,std::string name, std::string desc,int line);
};


