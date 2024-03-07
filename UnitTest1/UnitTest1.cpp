#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_8.1(rec)/PR_8.1(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "abcsqdefg";
			Assert::AreEqual(1, Count(str, 0));
		}
		TEST_METHOD(TestMethod2)
		{
			char* dest = new char[151];
			dest[0] = '\0';
			char str[] = "sqabcsqdefgqsq";

			char* result = Change(dest, str, dest, 0);
			Assert::AreEqual("***abc***defg***q", result);
			delete[] result;
		}
	};
}
