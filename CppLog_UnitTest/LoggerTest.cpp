#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logger.h"
#include "TargetMock.h"

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
			TargetMock target;
			logger.AddTarget(&target);
			logger.LogMessage(Log_Debug, L"Test message");
			Assert::AreEqual(ToString(L"Test message"), target.GetLastEntry());
		}

		TEST_METHOD(LoggerMessage_WarningConfigured_LogNotWritten)
		{
			CppLog::Logger logger(L"testLogger");
			TargetMock target;
			logger.AddTarget(&target);
			logger.SetLoggingType(Log_Warning);
			logger.LogMessage(Log_Debug, L"Test message");
			Assert::AreEqual(ToString(L""), target.GetLastEntry());
		}
	};
}