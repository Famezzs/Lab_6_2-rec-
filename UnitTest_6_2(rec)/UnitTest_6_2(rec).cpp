#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Home\source\repos\Lab_6_2(rec)\Lab_6_2(rec)\Lab_6_2(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
	TEST_CLASS(UnitTest62rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			const int n = 1;
			int a[n];
			a[0] = 3;
			double y;

			ArithmeticMean(a, n, 0, y, 0, 0);
			Assert::AreEqual(y, 3.);
		}
	};
}
