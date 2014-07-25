#include "stdafx.h"
#include "Logger.h"

using namespace CppLog;
using namespace std;

Logger::Logger(const std::wstring& name)
{
	m_name = name;
}


Logger::~Logger()
{
}

wstring Logger::GetName()
{
	return m_name;
}
