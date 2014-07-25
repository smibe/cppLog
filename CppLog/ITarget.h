#pragma once
#include "Logger.h"

using namespace CppLog;

class ITarget
{
public:
	virtual ~ITarget() { }
	virtual void LogMessage(ELoggingType type, const std::wstring& message);
};

