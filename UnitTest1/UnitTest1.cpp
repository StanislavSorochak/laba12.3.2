#include "pch.h"
#include "CppUnitTest.h"
#include "../laba12.3.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;

			int index = 1, N = 2, i = 0;
			Creata(first, last, index, N, i);

			Spusok* T = first;

			int v1 = 0, v2 = 1;

			T = first;
			Process(T, v1, v2, last);
			T = first;

			int l = T->link1->inf;
			Assert::AreEqual(l, 5);
		}
	};
}
