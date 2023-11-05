#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5_STP/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab5
{
	TEST_CLASS(UnitTestLab5)
	{
	public:
		
		TEST_METHOD(TestCtorSuccess)
		{
			double a = 1011.1011;
			int b = 2;
			int c = 4;

			double extend = 1011.1011;
			TPNumber pnum(a, b, c);
			double result = pnum.getNumber();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestCtorFailPrecision)
		{
			double a = 1011.1010;
			int b = 2;
			int c = -1;

			double extend = 0.0;
			TPNumber pnum(a, b, c);
			double result = pnum.getNumber();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestCtorFailBase)
		{
			double a = 1011.1010;
			int b = 1;
			int c = 4;

			double extend = 0.0;
			TPNumber pnum(a, b, c);
			double result = pnum.getNumber();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestCtorString)
		{
			string a = "ABC123.435DC";
			string b = "16";
			string c = "5";

			string extend = "ABC123.435D2";
			TPNumber pnum(a, b, c);
			string result = pnum.getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestCtorStrFailPrecision)
		{
			string a = "ABC123.435DC";
			string b = "16";
			string c = "3";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			string result = pnum.getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestCtorStrFailBase)
		{
			string a = "ABC123.435DC";
			string b = "12";
			string c = "5";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			string result = pnum.getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestCtorStrFailNum)
		{
			string a = "ABJ123.435DC";
			string b = "16";
			string c = "5";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			string result = pnum.getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestAdd2)
		{
			string a = "1110101.110101";
			string b = "2";
			string c = "6";
			string a1 = "111101.100001";
			string b1 = "2";
			string c1 = "6";

			string extend = "10110011.010110";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum + pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestAdd15)
		{
			string a = "1837A.342B";
			string b = "15";
			string c = "4";
			string a1 = "34C01.DDA1";
			string b1 = "15";
			string c1 = "4";

			string extend = "4D07C.22C6";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum + pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestAddDiffBase)
		{
			string a = "1837A.342B";
			string b = "16";
			string c = "4";
			string a1 = "34C01.DDA1";
			string b1 = "15";
			string c1 = "4";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum + pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestAddDiffPrec)
		{
			string a = "1837A.342B";
			string b = "16";
			string c = "4";
			string a1 = "34C01.DDA1A";
			string b1 = "16";
			string c1 = "5";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum + pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestMult)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";
			string a1 = "34.34";
			string b1 = "15";
			string c1 = "2";

			string extend = "3C877.E8";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum * pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestSub)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";
			string a1 = "34.34";
			string b1 = "15";
			string c1 = "2";

			string extend = "124D.DE";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum - pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestDiv)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";
			string a1 = "34.34";
			string b1 = "15";
			string c1 = "2";

			string extend = "55.36";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum / pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestDivZero)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";
			string a1 = "0.0";
			string b1 = "15";
			string c1 = "2";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			TPNumber pnum1(a1, b1, c1);
			string result = (pnum / pnum1).getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestInverse)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";

			string extend = "0.0";
			TPNumber pnum(a, b, c);
			string result = pnum.inverse().getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestSqr)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";

			string extend = "157D924.6D";
			TPNumber pnum(a, b, c);
			string result = pnum.square().getNumberString();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestSetBaseFail)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";

			int extend = 15;
			TPNumber pnum(a, b, c);
			pnum.setBase(2);
			int result = pnum.getBase();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestSetBase)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";

			int extend = 16;
			TPNumber pnum(a, b, c);
			pnum.setBase(16);
			int result = pnum.getBase();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestSetPrec)
		{
			string a = "1283.22";
			string b = "15";
			string c = "2";

			int extend = 4;
			TPNumber pnum(a, b, c);
			pnum.setPrecision(4);
			int result = pnum.getPrecision();
			Assert::AreEqual(extend, result);
		}
		TEST_METHOD(TestSetFail)
		{
			string a = "1283.1337";
			string b = "15";
			string c = "4";

			int extend = 4;
			TPNumber pnum(a, b, c);
			pnum.setPrecision(2);
			int result = pnum.getPrecision();
			Assert::AreEqual(extend, result);
		}
	};
}
