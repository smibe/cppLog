#pragma once
#include <string>

namespace CppLog
{
	enum ELoggingType
	{
		Log_Error = 1,
		Log_Warning,
		Log_Debug,
		Log_Info,
	};

	class Logger
	{
	public:
		Logger(const std::wstring& name);
		~Logger();

		std::wstring GetName();

		void LogMessage(ELoggingType type, const std::wstring& message);
	protected:
		std::wstring m_name;
	};

	void LogMessage(ELoggingType loggingType, const std::wstring& message);
}