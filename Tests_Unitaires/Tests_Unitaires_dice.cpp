#include "pch.h"
#include "CppUnitTest.h"
#include "../Yahtzee/dice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsUnitaires
{
    TEST_CLASS(TestsUnitaires)
    {
    public:

        TEST_METHOD(Test_operator_conversion)
        {
            dice _dice(5);

            //Verifier la valeur du d�s.

            Assert::IsTrue(_dice() == 5, L"La valeur du d�s �gale � 5");
            Assert::IsFalse(_dice() == 2, L"La valeur du d�s n'est pas �gale � 2");


        }
       

    };
}