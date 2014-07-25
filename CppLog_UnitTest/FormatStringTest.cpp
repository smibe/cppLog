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
		
		TEST_METHOD(TestMethod1)
		{
			wstring test = L"test123";
			std::wstring message = FormatString(L"%s %d", test, 999.0);
			Assert::AreEqual(ToString("test123 999"), message);
		}

	};
}