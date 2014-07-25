#include "stdafx.h"
#include "LogManager.h"

using namespace std;
using namespace CppLog;


Logger& LogManager::Default()
{
	static Logger logger(L"");
	return logger;
}

LogConfiguration& Configuration()
{
	static LogConfiguration logConfiguration;
	return logConfiguration;
}
