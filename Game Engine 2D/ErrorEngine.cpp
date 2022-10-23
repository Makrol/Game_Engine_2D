#include "ErrorEngine.h"
#pragma warning(disable : 4996).
void ErrorEngine::reportError(ErrorNames error,std::string name,int line)
{
	std::ofstream file("errorlogs", std::ios_base::app);
	time_t now = time(0);
	file << "error_code:"<<error<< " - "<< "in_file:"<< name << " - "<< "in_line:"<< line << " - " << errorDescriptions.find(error)->second << " - " << ctime(&now);
	file.close();
}

void ErrorEngine::init()
{
	errorDescriptions.insert(std::make_pair(ErrorNames::TEST_ERROR, "To testowy opis erroru"));
}
