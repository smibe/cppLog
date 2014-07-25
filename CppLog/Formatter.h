#pragma once
namespace CppLog
{
	class IFormatter
	{
	public:
		virtual ~IFormatter() {}
		std::wstring Format(const std::wstring& message);
	};
}

