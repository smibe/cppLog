#pragma once
#include <vector>
#include "ITarget.h"

class TargetMock : public CppLog::ITarget 
{
public:
	void LogMessage(CppLog::ELoggingType type, const std::wstring& message)
	{
		LogEntries.push_back(message);
	}

	std::wstring GetLastEntry()
	{
		if (LogEntries.empty())
			return std::wstring();

		return LogEntries[LogEntries.size() - 1];
	}

	void Clear()
	{
		LogEntries.clear();
	}

	std::vector<std::wstring> LogEntries;
};

