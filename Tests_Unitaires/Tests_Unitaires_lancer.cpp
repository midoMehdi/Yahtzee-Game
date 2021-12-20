#include "pch.h"
#include "CppUnitTest.h"
#include "../Yahtzee/lancer.h"
#include "../Yahtzee/dice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsUnitaires
{
    TEST_CLASS(TestsUnitaires)
    {
    public:

        TEST_METHOD(Test_lancerDice)
        {
            dice _dice;
            lancer _lancer(_dice);
            //lancer les d�s.
            _lancer.lancerDice();

            Assert::IsTrue(_dice() < 7 && _dice() > 0, L"Valeur du d�s comprise entre 1 et 6");
            Assert::IsFalse(_dice() > 6 && _dice() < 1, L"Valeur du d�s n'est inferieur � 1 et superieur � 6");


        }

    };
}