#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8_STP/TProc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TProc<int> proc;
		TEST_METHOD(TestReset)
		{
			proc.reset();
			int lop = proc.read_lop();
			Assert::AreEqual(0, lop);
			int rop = proc.read_rop();
			Assert::AreEqual(0, rop);
			TOptrn operation = proc.read_operation();
			TOptrn exp = TOptrn::None;
			Assert::IsTrue(operation == exp);
		}
		TEST_METHOD(TestResetOp)
		{
			proc.reset_operation();
			TOptrn operation = proc.read_operation();
			TOptrn exp = TOptrn::None;
			Assert::IsTrue(operation == exp);
		}
		TEST_METHOD(TestOperPlus)
		{
			proc.set_operation(TOptrn::Add);
			proc.write_lop(5);
			proc.write_rop(10);
			proc.do_operation();
			int res = proc.read_lop();
			int expected = 15;
			Assert::AreEqual(expected, res);
		}
		TEST_METHOD(TestOperMinus)
		{
			proc.set_operation(TOptrn::Sub);
			proc.write_lop(5);
			proc.write_rop(10);
			proc.do_operation();
			int res = proc.read_lop();
			int expected = -5;
			Assert::AreEqual(expected, res);
		}
		TEST_METHOD(TestOperMul)
		{
			proc.set_operation(TOptrn::Mul);
			proc.write_lop(5);
			proc.write_rop(10);
			proc.do_operation();
			int res = proc.read_lop();
			int expected = 50;
			Assert::AreEqual(expected, res);
		}
		TEST_METHOD(TestOperDiv)
		{
			proc.set_operation(TOptrn::Div);
			proc.write_lop(10);
			proc.write_rop(5);
			proc.do_operation();
			int res = proc.read_lop();
			int expected = 2;
			Assert::AreEqual(expected, res);
		}
		TEST_METHOD(TestApplyFunc)
		{
			proc.write_rop(5);
			proc.apply_func(TFunc::Sqr);
			int res = proc.read_rop();
			int expected = 25;
			Assert::AreEqual(expected, res);
		}
	};
}
