#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9_STP/TPoly.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCtor1)
		{
			TPoly poly(5, 3);
			std::pair<int, int> m = poly[0];
			Assert::AreEqual(m.first, 5);
			Assert::AreEqual(m.second, 3);
		}
		TEST_METHOD(TestCtor2)
		{
			TPoly poly(0, 3);
			std::pair<int, int> m = poly[0];
			Assert::AreEqual(m.first, 0);
			Assert::AreEqual(m.second, 0);
		}
		TEST_METHOD(TestGetDegree1)
		{
			TPoly poly(5, 3);
			int deg = poly.get_degree();
			Assert::AreEqual(3, deg);
		}
		TEST_METHOD(TestGetDegree2)
		{
			TPoly poly;
			int deg = poly.get_degree();
			Assert::AreEqual(0, deg);
		}
		TEST_METHOD(TestGetCoef1)
		{
			TPoly poly(5, 3);
			int coef = poly.get_coef(3);
			Assert::AreEqual(5, coef);
		}
		TEST_METHOD(TestGetCoef2)
		{
			TPoly poly(5, 3);
			int coef = poly.get_coef(2);
			Assert::AreEqual(0, coef);
		}
		TEST_METHOD(TestGetCoef3)
		{
			TPoly poly;
			int coef = poly.get_coef(2);
			Assert::AreEqual(0, coef);
		}
		TEST_METHOD(TestAdd1)
		{
			TPoly poly1(5, 3);
			TPoly poly2(2, 3);
			TPoly res = poly1 + poly2;
			int coef = res.get_coef(3);
			Assert::AreEqual(7, coef);
		}
		TEST_METHOD(TestAdd2)
		{
			TPoly poly1(5, 3);
			TPoly poly2(2, 2);
			TPoly res = poly1 + poly2;
			int coef3 = res.get_coef(3);
			Assert::AreEqual(5, coef3);
			int coef2 = res.get_coef(2);
			Assert::AreEqual(2, coef2);
		}
		TEST_METHOD(TestMult1)
		{
			TPoly poly1(1, 2);  // x^2
			TPoly poly2(2, 1);  // 2x
			TPoly res = poly1 * poly2;  // x^2 * 2x = 2x^3
			int coef3 = res.get_coef(3);
			Assert::AreEqual(2, coef3);
		}
		TEST_METHOD(TestMult2)
		{
			TPoly poly_a(1, 2);  // x^2
			TPoly poly_b(2, 1);  // 2x
			TPoly poly_c(5, 3);  // 5x^3
			TPoly poly_d(3, 2);  // 3x^2
			TPoly poly_ab = poly_a + poly_b; // x^2 + 2x
			TPoly poly_cd = poly_c + poly_d; // 5x^3 + 3x^2
			TPoly res = poly_ab * poly_cd;  // (x^2 + 2x) * (5x^3 + 3x^2) = 5x^5 + 13x^4 + 6x^3
			int coef5 = res.get_coef(5);
			Assert::AreEqual(5, coef5);
			int coef4 = res.get_coef(4);
			Assert::AreEqual(13, coef4);
			int coef3 = res.get_coef(3);
			Assert::AreEqual(6, coef3);
		}
		TEST_METHOD(TestSub1)
		{
			TPoly poly1(5, 3);
			TPoly poly2(2, 3);
			TPoly res = poly1 - poly2;
			int coef = res.get_coef(3);
			Assert::AreEqual(3, coef);
		}
		TEST_METHOD(TestSub2)
		{
			TPoly poly1(5, 3);
			TPoly poly2(2, 2);
			TPoly res = poly1 - poly2;
			int coef3 = res.get_coef(3);
			Assert::AreEqual(5, coef3);
			int coef2 = res.get_coef(2);
			Assert::AreEqual(-2, coef2);
		}
		TEST_METHOD(TestMinus)
		{
			TPoly poly1(5, 3);
			TPoly res = -poly1;
			int coef = res.get_coef(3);
			Assert::AreEqual(-5, coef);
		}
		TEST_METHOD(TestEqual1)
		{
			TPoly poly1(5, 3);
			TPoly poly2(2, 3);
			bool res = poly1 == poly2;
			Assert::AreEqual(false, res);
		}
		TEST_METHOD(TestEqual2)
		{
			TPoly poly1(5, 3);
			TPoly poly2(2, 2);
			TPoly poly_sum = poly1 + poly2;
			bool res = poly_sum == poly1;
			Assert::AreEqual(false, res);
		}
		TEST_METHOD(TestEqual3)
		{
			TPoly poly1(5, 3);
			TPoly poly2(5, 3);
			bool res = poly2 == poly1;
			Assert::AreEqual(true, res);
		}
		TEST_METHOD(TestDerivative)
		{
			TPoly poly1(5, 3);
			TPoly der = poly1.derivative();
			int coef3 = der.get_coef(3);
			Assert::AreEqual(0, coef3);
			int coef2 = der.get_coef(2);
			Assert::AreEqual(15, coef2);
		}
		TEST_METHOD(TestEvaluate)
		{
			TPoly poly1(5, 3);
			double res = poly1.evaluate(2); // 5 * 2^3 = 5 * 8 = 40
			Assert::AreEqual(40.0, res, 0.001);
		}
		TEST_METHOD(TestIndex1)
		{
			TPoly poly1(5, 3);
			std::pair<int, int> m = poly1[0];
			Assert::AreEqual(5, m.first);
			Assert::AreEqual(3, m.second);
		}
		TEST_METHOD(TestIndex2)
		{
			TPoly poly1(5, 3);
			std::pair<int, int> m = poly1[50];
			Assert::AreEqual(0, m.first);
			Assert::AreEqual(0, m.second);
		}
	};
}
