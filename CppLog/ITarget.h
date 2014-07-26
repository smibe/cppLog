#pragma once

namespace CppLog
{
	enum ELoggingType;
	class ITarget
	{
	public:
		virtual ~ITarget() { }
		virtual void LogMessage(CppLog::ELoggingType type, const std::wstring& message) = 0;
			
	};
}

