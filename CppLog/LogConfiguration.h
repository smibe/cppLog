#pragma once
#include "Logger.h"
#include "ITarget.h"

namespace CppLog
{
	class LogConfiguration {
	public:
		~LogConfiguration();
		void EnableLogger(const std::wstring& loggerName, ELoggingType type);
		void AddOutputter(const std::wstring& loggerName, ITarget outputter);
	};
}
