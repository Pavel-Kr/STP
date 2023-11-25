#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6_STP/TEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestClear)
		{
			TEditor editor;
			editor.clear();
			std::string result = editor.toString();
			std::string expected = "0 + 0i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestFlipSign1)
		{
			TEditor editor;
			editor.clear();
			editor.flipSign();
			std::string result = editor.toString();
			std::string expected = "-0 + 0i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestFlipSign2)
		{
			TEditor editor;
			editor.clear();
			editor.setEditingPart(IMAG);
			editor.flipSign();
			std::string result = editor.toString();
			std::string expected = "0 -0i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDigit1)
		{
			TEditor editor;
			editor.clear();
			editor.addDigit(156);
			std::string result = editor.toString();
			std::string expected = "0 + 0i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDigit2)
		{
			TEditor editor;
			editor.clear();
			editor.addDigit(1);
			std::string result = editor.toString();
			std::string expected = "01 + 0i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDigit3)
		{
			TEditor editor;
			editor.clear();
			editor.setEditingPart(IMAG);
			editor.addDigit(1);
			std::string result = editor.toString();
			std::string expected = "0 + 01i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddZero1)
		{
			TEditor editor;
			editor.clear();
			editor.addZero();
			std::string result = editor.toString();
			std::string expected = "00 + 0i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddZero2)
		{
			TEditor editor;
			editor.clear();
			editor.setEditingPart(IMAG);
			editor.addZero();
			std::string result = editor.toString();
			std::string expected = "0 + 00i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestDeleteDigit1)
		{
			TEditor editor;
			editor.clear();
			editor.setComplexNumber("15 + 3i");
			editor.deleteDigit();
			std::string result = editor.toString();
			std::string expected = "1 + 3i";
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestDeleteDigit2)
		{
			TEditor editor;
			editor.clear();
			editor.setComplexNumber("1 + 31i");
			editor.setEditingPart(IMAG);
			editor.deleteDigit();
			std::string result = editor.toString();
			std::string expected = "1 + 3i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDelimiter1)
		{
			TEditor editor;
			editor.clear();
			editor.setComplexNumber("1 + 3i");
			editor.addDelimiter();
			std::string result = editor.toString();
			std::string expected = "1. + 3i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDelimiter2)
		{
			TEditor editor;
			editor.clear();
			editor.setComplexNumber("1.0 + 3i");
			editor.addDelimiter();
			std::string result = editor.toString();
			std::string expected = "1.0 + 3i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDelimiter3)
		{
			TEditor editor;
			editor.clear();
			editor.setComplexNumber("1 + 3i");
			editor.setEditingPart(IMAG);
			editor.addDelimiter();
			std::string result = editor.toString();
			std::string expected = "1 + 3.i";
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestAddDelimiter4)
		{
			TEditor editor;
			editor.clear();
			editor.setComplexNumber("1 + 3.0i");
			editor.setEditingPart(IMAG);
			editor.addDelimiter();
			std::string result = editor.toString();
			std::string expected = "1 + 3.0i";
			Assert::AreEqual(result, expected);
		}
	};
}
