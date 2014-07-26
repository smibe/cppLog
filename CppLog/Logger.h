#pragma once
#include <string>
#include <vector>
#include "ITarget.h"

namespace CppLog
{
	enum ELoggingType
	{
		Log_Debug = 0,
		Log_Info,
		Log_Warning,
		Log_Error,
	};

	class Logger
	{
	public:
		Logger(const std::wstring& name);
		~Logger();

		void LogMessage(ELoggingType type, const std::wstring& message);

		std::wstring GetName();
		void AddTarget(ITarget *target);
		void SetLoggingType(ELoggingType type);

	protected:
		ELoggingType m_type;
		std::wstring m_name;
		std::vector<ITarget*> m_targets;
	};

	void LogMessage(ELoggingType loggingType, const std::wstring& message);
}