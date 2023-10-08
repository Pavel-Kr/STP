#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3/lab3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{
	TEST_CLASS(UnitTestLab3)
	{
	public:
		
		TEST_METHOD(TestMax3_1)
		{
			int max = Lab3::max3(5, 3, 8);
			int expected = 8;
			Assert::AreEqual(max, expected);
		}
		TEST_METHOD(TestMax3_2)
		{
			int max = Lab3::max3(8, 3, 5);
			int expected = 8;
			Assert::AreEqual(max, expected);
		}
		TEST_METHOD(TestMax3_3)
		{
			int max = Lab3::max3(3, 5, 8);
			int expected = 8;
			Assert::AreEqual(max, expected);
		}
		TEST_METHOD(TestMax3_4)
		{
			int max = Lab3::max3(3, 8, 5);
			int expected = 8;
			Assert::AreEqual(max, expected);
		}
		TEST_METHOD(TestMagic_1)
		{
			int res = Lab3::magic(0);
			int expected = 0;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestMagic_2)
		{
			int res = Lab3::magic(12345);
			int expected = 42;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestMinDigit_1)
		{
			int res = Lab3::min_digit(0);
			int expected = 0;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestMinDigit_2)
		{
			int res = Lab3::min_digit(5634);
			int expected = 3;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestOddSum_1)
		{
			Matrix mat(3, 5);
			bool exception_thrown = false;
			try {
				int res = Lab3::odd_sum(mat);
			}
			catch (...) {
				exception_thrown = true;
			}
			Assert::AreEqual(exception_thrown, true);
		}
		TEST_METHOD(TestOddSum_2)
		{
			Matrix mat(0, 0);
			int res = Lab3::odd_sum(mat);
			int expected = 0;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestOddSum_3)
		{
			Matrix mat(1, 1);
			int res = Lab3::odd_sum(mat);
			int expected = 0;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestOddSum_4)
		{
			Matrix mat(2, 2);
			mat.set(1, 0, 5);
			int res = Lab3::odd_sum(mat);
			int expected = 5;
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestOddSum_5)
		{
			Matrix mat(0, 0);
			mat.set(1, 0, 4);
			int res = Lab3::odd_sum(mat);
			int expected = 0;
			Assert::AreEqual(res, expected);
		}
	};
}
