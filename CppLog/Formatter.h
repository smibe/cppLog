#pragma once
#include <string>
#include "Logger.h"
#include <regex>

namespace CppLog
{
	const std::wstring Debug = L"Debug";
	std::wstring ToString(ELoggingType level)
	{
		switch (level)
		{
		case Log_Debug:
			return Debug;
		case Log_Info:
			return L"Info";
		case Log_Warning:
			return L"Warning";
		case Log_Error:
			return L"Error";
		}
		throw new std::exception("Invalid enum value.");
	}

	const std::wstring LEVEL = L"${level}";
	const std::wstring MESSAGE = L"${message}";
	std::wstring ExpandVariable(ELoggingType level, const std::wstring& message, const std::wstring& name)
	{
		if (name == LEVEL)
			return ToString(level);

		if (name == MESSAGE)
			return message;

		return name;
	}

	class Formatter
	{
	public:
		std::wstring Format(ELoggingType level, const std::wstring& message)
		{
			std::wstring formattedMessage;
			static std::wregex variableRegex(L"((.*?)(\\$\\{.+?\\}))*(.*?)");
			std::wsmatch match;
			std::regex_match(m_formatString, match, variableRegex);

			size_t i = 1;
			for (; i-1 < match.size() / 3; i += 3)
			{
				formattedMessage += match[i + 1].str();
				formattedMessage += ExpandVariable(level, message, match[i + 2].str());
			}
			for (; i < match.size(); i++)
			{
				formattedMessage += match[i].str();
			}
			return formattedMessage;
		}

		void SetFormatString(const std::wstring& formatString)
		{
			m_formatString = formatString;
		}

	protected:
		std::wstring m_formatString;
	};
}

