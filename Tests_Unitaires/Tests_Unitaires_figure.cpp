#include "pch.h"
#include "CppUnitTest.h"
#include "../Yahtzee/figure.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsUnitaires
{
    TEST_CLASS(TestsUnitaires)
    {
    public:

        //Methode calculate pour "brelan"
        TEST_METHOD(Test_calculatebrelan)
        {
            dice d1(1), d2(3), d3(3), d4(4), d5(3);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            brelan<3> b1(dices);
            //Calculate Score.

            Assert::AreEqual(b1.calculate(), unsigned(9), L"Le score est 9");
            Assert::AreNotEqual(b1.calculate(), unsigned(20), L"Le score n'est pas 20");
        }

        //Methode calculate pour "carre"
        TEST_METHOD(Test_calculatecarre)
        {
            dice d1(1), d2(2), d3(1), d4(1), d5(1);;
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            carre<1> c1(dices);
            //Calculate Score.

            Assert::AreEqual(c1.calculate(), unsigned(4), L"Le score est 4");
            Assert::AreNotEqual(c1.calculate(), unsigned(32), L"Le score n'est pas 32");
        }

        //Methode calculate pour "full"
        TEST_METHOD(Test_calculatefull)
        {
            dice d1(2), d2(2), d3(2), d4(1), d5(1);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            full f1(dices);
            //Calculate Score.

            Assert::AreEqual(f1.calculate(), unsigned(25), L"Le score est 25");
            Assert::AreNotEqual(f1.calculate(), unsigned(22), L"Le score n'est pas 22");
        }

        //Methode calculate pour "petite suite"
        TEST_METHOD(Test_calculatepsuite)
        {
            dice d1(4), d2(2), d3(3), d4(4), d5(5);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            psuite ps1(dices);
            //Calculate Score.

            Assert::AreEqual(ps1.calculate(), unsigned(30), L"Le score est 30");
            Assert::AreNotEqual(ps1.calculate(), unsigned(4), L"Le score n'est pas 4");
        }

        //Methode calculate pour "grande suite"
        TEST_METHOD(Test_calculategsuite)
        {
            dice d1(1), d2(2), d3(3), d4(4), d5(5);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            gsuite gs1(dices);
            //Calculate Score.

            Assert::AreEqual(gs1.calculate(), unsigned(40), L"Le score est 40");
            Assert::AreNotEqual(gs1.calculate(), unsigned(30), L"Le score n'est pas 30");
        }

        //Methode calculate pour "yahtzee"
        TEST_METHOD(Test_calculateyahtzee)
        {
            dice d1(4), d2(4), d3(4), d4(4), d5(4);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            yahtzee y1(dices);
            //Calculate Score.

            Assert::AreEqual(y1.calculate(), unsigned(50), L"Le score est 50");
            Assert::AreNotEqual(y1.calculate(), unsigned(11), L"Le score n'est pas 11");
        }

        //Methode calculate pour "chance"
        TEST_METHOD(Test_calculatechance)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            chance ca1(dices);
            //Calculate Score.

            Assert::AreEqual(ca1.calculate(), unsigned(17), L"Le score est 17");
            Assert::AreNotEqual(ca1.calculate(), unsigned(11), L"Le score n'est pas 11");
        }

        //Methode calculate pour "total_one"
        TEST_METHOD(Test_calculatetotal_one)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            total_one to1(dices);
            //Calculate Score.

            Assert::AreEqual(to1.calculate(), unsigned(1), L"Le score est 1");
            Assert::AreNotEqual(to1.calculate(), unsigned(3), L"Le score n'est pas 3");
        }

        //Methode calculate pour "total_two"
        TEST_METHOD(Test_calculatetotal_two)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            total_two to2(dices);
            //Calculate Score.

            Assert::AreEqual(to2.calculate(), unsigned(2), L"Le score est 2");
            Assert::AreNotEqual(to2.calculate(), unsigned(6), L"Le score n'est pas 6");
        }

        //Methode calculate pour "total_three"
        TEST_METHOD(Test_calculatetotal_three)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            total_three tt1(dices);
            //Calculate Score.

            Assert::AreEqual(tt1.calculate(), unsigned(0), L"Le score est 0");
            Assert::AreNotEqual(tt1.calculate(), unsigned(6), L"Le score n'est pas 6");
        }

        //Methode calculate pour "total_four"
        TEST_METHOD(Test_calculatetotal_four)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            total_four tf1(dices);
            //Calculate Score.

            Assert::AreEqual(tf1.calculate(), unsigned(8), L"Le score est 8");
            Assert::AreNotEqual(tf1.calculate(), unsigned(12), L"Le score n'est pas 12");
        }

        //Methode calculate pour "total_five"
        TEST_METHOD(Test_calculatetotal_five)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            total_five tf2(dices);
            //Calculate Score.

            Assert::AreEqual(tf2.calculate(), unsigned(0), L"Le score est 0");
            Assert::AreNotEqual(tf2.calculate(), unsigned(30), L"Le score n'est pas 30");
        }

        //Methode calculate pour "total_six"
        TEST_METHOD(Test_calculatetotal_six)
        {
            dice d1(4), d2(2), d3(1), d4(4), d5(6);
            std::vector<dice> dices;
            dices = { d1,d2,d3,d4,d5 };
            total_six ts1(dices);
            //Calculate Score.

            Assert::AreEqual(ts1.calculate(), unsigned(6), L"Le score est 6");
            Assert::AreNotEqual(ts1.calculate(), unsigned(30), L"Le score n'est pas 30");
        }


    };
}