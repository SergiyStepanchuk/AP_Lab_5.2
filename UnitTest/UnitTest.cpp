#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(met_S)
		{
			const double cos = 0.9;
			int n;
			Assert::IsTrue(abs(S(cos, 0.0000001, n) - acos(cos)) < 0.00001, L"Incorrect method M!");
		}
	};
}
