#include "ErrorEngine.h"
#include <windows.h>
#include <cstring>

#define WIN32_LEAN_AND_MEAN
#pragma warning(disable : 4996)
void ErrorEngine::reportError(ErrorNames error,std::string name,std::string desc,int line)
{
	init();
	std::ofstream file("errorlogs", std::ios_base::app);
	time_t now = time(0);
	file << "error_code:"<<error<< " - "<< "in_file:"<< name << " - "<< "in_line:"<< line << " - " << errorDescriptions.find(error)->second << " - "<< desc<<" - " << ctime(&now);
	file.close();
	std::string tmp = errorDescriptions.find(error)->second;
	
	const char* tmp2 = tmp.c_str();
	MessageBoxA(NULL, tmp2, "Error!!", MB_OK | MB_ICONERROR);
	exit(0);

}

void ErrorEngine::init()
{
	errorDescriptions.insert(std::make_pair(ErrorNames::TEST_ERROR, "To testowy opis erroru"));
	errorDescriptions.insert(std::make_pair(ErrorNames::TEXTURE_ERROR, "Blad ladowania bitmapy z pliku"));
}
