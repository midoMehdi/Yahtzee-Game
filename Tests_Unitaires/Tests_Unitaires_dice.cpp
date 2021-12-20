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

            //Verifier la valeur du dès.

            Assert::IsTrue(_dice() == 5, L"La valeur du dès égale à 5");
            Assert::IsFalse(_dice() == 2, L"La valeur du dès n'est pas égale à 2");


        }
       

    };
}