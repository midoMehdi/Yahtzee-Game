#include "pch.h"
#include "CppUnitTest.h"
#include "../Yahtzee/player.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*Teste de la classe grille.*/
namespace TestsUnitaires
{
	TEST_CLASS(TestsUnitaires_grille)
	{
	public:

		/*
		* Test of method sup_completed.
		*/
		TEST_METHOD(Test_sup_completed) {
			player p("mehdi");
			grille _g = p.get_Grille();
			Assert::IsFalse(_g.sup_completed(), L"la partie supérieur est vide.");

			p.change_availibilities("1");//total_1.
			p.change_availibilities("2");//total_2.
			p.change_availibilities("3");//total_3.
			 _g = p.get_Grille();
			Assert::IsFalse(_g.sup_completed(), L"la partie supérieur est vide.");


			p.change_availibilities("1");//total_1.
			p.change_availibilities("2");//total_2.
			p.change_availibilities("3");//total_3.
			p.change_availibilities("4");//total_4.
			p.change_availibilities("5");//total_5.
			p.change_availibilities("6");//total_6.
			 _g = p.get_Grille();
			Assert::IsTrue(_g.sup_completed(), L"la partie supérieur n'est pas vide.");

		}

		/*
		* Test of method inf_completed.
		*/
		TEST_METHOD(Test_inf_completed) {
			player p("oussama");
			grille _g = p.get_Grille();
			Assert::IsFalse(_g.inf_completed(), L"la partie inférieur est vide.");

			p.change_availibilities("brelan");//brelan.
			p.change_availibilities("carre");//carre.
			p.change_availibilities("full");//full House.
			_g = p.get_Grille();
			Assert::IsFalse(_g.inf_completed(), L"la partie inférieur est vide.");


			p.change_availibilities("psuite");//petite suite.
			p.change_availibilities("gsuite");//grande suite.
			p.change_availibilities("yahtzee");//yahtzee suite.
			p.change_availibilities("chance");//chance suite.
			_g = p.get_Grille();
			Assert::IsTrue(_g.inf_completed(), L"la partie inférieur n'est pas vide.");

		}

		/*
		* Test of method grille_completed.
		*/
		TEST_METHOD(Test_grille_completed) {
			player p("mehdi");
			grille _g = p.get_Grille();
			Assert::IsFalse(_g.grille_completed(), L"La grille est vide.");

			p.change_availibilities("1");//total_1.
			p.change_availibilities("2");//total_2.
			p.change_availibilities("3");//total_3.
			p.change_availibilities("4");//total_4.
			_g = p.get_Grille();
			Assert::IsFalse(_g.grille_completed(), L"La grille est vide.");

			p.change_availibilities("5");//total_5.
			p.change_availibilities("6");//total_6.
			p.change_availibilities("brelan");//brelan.
			p.change_availibilities("carre");//carre.
			p.change_availibilities("full");//full House.
			_g = p.get_Grille();
			Assert::IsFalse(_g.grille_completed(), L"La grille est vide.");

			p.change_availibilities("psuite");//petite suite.
			p.change_availibilities("gsuite");//grande suite.
			p.change_availibilities("yahtzee");//yahtzee suite.
			p.change_availibilities("chance");//chance suite.
			_g = p.get_Grille();
			Assert::IsTrue(_g.grille_completed(), L"La grille n'est pas vide.");

		}
	};
}