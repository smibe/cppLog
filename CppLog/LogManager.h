#pragma once
#include "Logger.h"
#include "LogConfiguration.h"

namespace CppLog
{
	class LogManager
	{
	public:
		static Logger& Default();
		static LogConfiguration& Configuration();
	};
}
