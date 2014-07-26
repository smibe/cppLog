#include "stdafx.h"
#include "CppUnitTest.h"
#include "FormatString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace StringUtils;
using namespace std;

namespace CppLog_UnitTest
{
	TEST_CLASS(FormatStringTest)
	{
	public:
		
		TEST_METHOD(FormatString_WithIntegerParameter)
		{
			wstring test = L"test123";
			std::wstring message = FormatString(L"%s %d", test, 999);
			Assert::AreEqual(ToString("test123 999"), message);
		}

		TEST_METHOD(FormatString_WithFloatParameter)
		{
			wstring test = L"test123";
			std::wstring message = FormatString(L"%s %.2f", test, 999.0);
			Assert::AreEqual(ToString("test123 999.00"), message);
		}

		TEST_METHOD(FormatString_WithMultipleParameter)
		{
			wstring test = L"test123";
			std::wstring message = FormatString(L"Param%s param2%.2f param3%d", test, 999.0, 888);
			Assert::AreEqual(ToString("Paramtest123 param2999.00 param3888"), message);
		}
	};
}