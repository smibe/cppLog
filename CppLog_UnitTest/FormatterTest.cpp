#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logger.h"
#include "Formatter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CppLog;

namespace CppLog_UnitTest
{
	TEST_CLASS(FormatterTest)
	{
	public:
		
		TEST_METHOD(FormatMessage_MessageTag_ReplacedWithMessage)
		{
			Formatter formatter;
			formatter.SetFormatString(L"${message}");
			Assert::AreEqual(ToString("TestMessage"), formatter.Format(Log_Debug, L"TestMessage"));
		}

		TEST_METHOD(FormatMessage_LevelTag_IsReplaced)
		{
			Formatter formatter;
			formatter.SetFormatString(L"[${level}]");
			Assert::AreEqual(ToString("[Debug]"), formatter.Format(Log_Debug, L"TestMessage"));
		}
	};
}