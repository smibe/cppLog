#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CppLog;

namespace CppLog_UnitTest
{		
	TEST_CLASS(LoggerTest)
	{
	public:
		TEST_METHOD(LoggerNameTest)
		{
			CppLog::Logger logger(L"testLogger");
			Assert::AreEqual(ToString("testLogger"), logger.GetName());
		}

		TEST_METHOD(LoggerWriteTest)
		{
			CppLog::Logger logger(L"testLogger");
			Assert::AreEqual(ToString("testLogger"), logger.GetName());
		}
	};
}