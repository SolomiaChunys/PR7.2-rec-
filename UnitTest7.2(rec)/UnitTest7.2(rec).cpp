#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2(rec)/PR7.2(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int k = 4;
			const int n = 4;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			int a[k][n] = { {4,3,6,1},
				{5,11,4,1},
				{9,15,2,8},
				{6,1,7,8} };
			int min;
			MinMaxRows(a, k, n, 0, min);
			Assert::AreEqual(min, 8);
		}
	};
}
