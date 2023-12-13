#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10_STP/TSet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCombine)
		{
			TSet<int> set1, set2;
			set1.add(3);
			set1.add(5);
			set2.add(5);
			set2.add(7);
			TSet<int> combined = set1.combine(set2);
			int size = combined.count();
			int expected = 3;
			Assert::AreEqual(expected, size);
		}
		TEST_METHOD(TestIntersect)
		{
			TSet<int> set1, set2;
			set1.add(3);
			set1.add(5);
			set2.add(5);
			set2.add(7);
			TSet<int> combined = set1.intersect(set2);
			int size = combined.count();
			int expected = 1;
			Assert::AreEqual(expected, size);
			Assert::IsTrue(combined.contains(5));
		}
		TEST_METHOD(TestSubtract)
		{
			TSet<int> set1, set2;
			set1.add(3);
			set1.add(5);
			set2.add(5);
			set2.add(7);
			TSet<int> combined = set1.subtract(set2);
			int size = combined.count();
			int expected = 1;
			Assert::AreEqual(expected, size);
			Assert::IsTrue(combined.contains(3));
		}
		TEST_METHOD(TestIndex1)
		{
			TSet<int> set1;
			set1.add(3);
			set1.add(5);
			int first = set1[0];
			int second = set1[1];
			Assert::AreEqual(3, first);
			Assert::AreEqual(5, second);
		}
		TEST_METHOD(TestIndex2)
		{
			auto func = [] { 
				TSet<int> set1;
				set1.add(3);
				set1.add(5);
				int a = set1[6]; 
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}
