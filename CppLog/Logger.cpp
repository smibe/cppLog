#include "stdafx.h"
#include "Logger.h"

using namespace CppLog;
using namespace std;

Logger::Logger(const std::wstring& name)
{
	m_name = name;
	m_type = Log_Debug;
}

Logger::~Logger()
{
}

wstring Logger::GetName()
{
	return m_name;
}

void Logger::AddTarget(ITarget *target)
{
	m_targets.push_back(target);
}

void Logger::SetLoggingType(ELoggingType type)
{
	m_type = type;
}

void Logger::LogMessage(ELoggingType type, const wstring& message)
{
	if (type < m_type)
	{
		return;
	}

	for (auto target : m_targets)
	{
		target->LogMessage(type, message);
	}
}