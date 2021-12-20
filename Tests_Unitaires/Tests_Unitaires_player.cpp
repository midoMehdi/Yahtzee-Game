#include "pch.h"
#include "CppUnitTest.h"
#include"../Yahtzee/player.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/*
* Teste de la classe player
*/
namespace TestsUnitaires
{
	TEST_CLASS(TestsUnitaires)
	{
	public:

		/*
		* Test of method check_brelan. (methode privée)
		*/
		TEST_METHOD(Test_checkbrelan) {
			dice d1(1), d2(2), d3(3), d4(4), d5(5), d6(6);
			player p("mehdi");
			

		}
		/*
		* Test of method check_brelan. (methode privée)
		*/
		TEST_METHOD(Test_checkcarre) {

		}
		/*
		* Test of method check_brelan. (methode privée)
		*/
		TEST_METHOD(Test_checkFullHouse) {

		}
		/*
		* Test of method check_brelan.(methode privée)
		*/
		TEST_METHOD(Test_checkPetiteSuite) {

		}

		/*
		* Test of method check_brelan. (methode privée)
		*/
		TEST_METHOD(Test_checkGrandeSuite) {

		}

		/*
		* Test of method check_brelan. (methode privée)
		*/
		TEST_METHOD(Test_checkYahtzee) {

		}
		
		/*
		* Test of method addDice.
		*/
		TEST_METHOD(Test_addDice)
		{
			dice d1(1), d2(2), d3(3), d4(4), d5(5), d6(6);
			player p("mehdi");
			/*
			* test si vector of dice contient 0 dice .
			*/
			Assert::AreEqual(size_t(0), p.allDices().size(),L"Aucun dice ajouté.");

			p.addDice(d1);
			p.addDice(d2);
			p.addDice(d3);
			p.addDice(d4);
			p.addDice(d5);

			/*
			* Test the maximum (= 5) capicity of dices. 
			*/
			Assert::AreEqual(size_t(5), p.allDices().size(),L"5 dices sont ajoutés.");

			/*
			* si on ajoute un autre dice, vector sera supprimé et ajouter le nouveau dice.
			*/
			p.addDice(d6);
			Assert::AreEqual(size_t(1), p.allDices().size(),L"Vector of dice contient 1 dice");
		}

		/*
		* Test of method get specific dice with given index.
		*/
		TEST_METHOD(Test_get_specific_dice) {
			dice d1(1), d2(2), d3(3), d4(4), d5(5), d6(6);
			player p("mehdi");
			p.addDice(d1);
			p.addDice(d2);
			p.addDice(d3);
			p.addDice(d4);
			p.addDice(d5);
			Assert::AreEqual(size_t(1), p.get_specific_dice(0)(), L"La méthode retourne le dè numéro 1");
			Assert::AreEqual(size_t(4), p.get_specific_dice(3)(), L"La méthode retorune le dè numéro 4");

			Assert::AreNotEqual(size_t(2), p.get_specific_dice(4)(), L"La méthode ne retourne pas le dè 2");
			
		}

		/*
		* Test of method change dice with given index and new dice.
		*/
		TEST_METHOD(Test_change_dice) {
			dice d1(1), d2(2), d3(3), d4(4), d5(5), d6(6);
			player p("oussama");
			p.addDice(d1);
			p.addDice(d2);
			p.addDice(d3);
			p.addDice(d4);
			p.addDice(d5);
			Assert::AreEqual(size_t(4), p.get_specific_dice(3)(), L"la valeur du dè numéro 3 est 4");
			p.change_dice(3, d6);
			Assert::AreNotEqual(size_t(4), p.get_specific_dice(3)(), L"le dè numéro 3 est changé par 6");
			Assert::AreEqual(size_t(6), p.get_specific_dice(3)(), L"Le dè est changé");
		}

		/*
		* Test of methid allDices.
		*/
		TEST_METHOD(Test_allDices) {
			dice d1(1), d2(2), d3(3), d4(4), d5(5), d6(6);
			player p("mehdi");
			p.addDice(d1);
			p.addDice(d2);
			p.addDice(d3);
			p.addDice(d4);
			p.addDice(d5);

			

			for (size_t i = 0; i < p.allDices().size(); i++) {
				Assert::AreEqual(i+1, p.allDices().at(i)(), L"La méthode retoruen the excpecting result");
			}

		}
		/*
		* Test of method write in grille.
		*/
		TEST_METHOD(Test_write_in_grille) {
			dice d1(1), d2(2), d3(3), d4(4), d5(5), d6(6);
			player p("mehdi");
			p.addDice(d1);
			p.addDice(d2);
			p.addDice(d3);
			p.addDice(d4);
			p.addDice(d5);
			p.write_in_grille("1");//total_1.
			Assert::AreEqual(size_t(1), p.get_Grille().total_1(), L"la valeur retourné est 1(total_1).");

			p.write_in_grille("gsuite");//grande suite.
			Assert::AreEqual(size_t(40), p.get_Grille().grande_suite(), L"la valeur retourné est 40 (grande suite).");

			p.write_in_grille("full");//full house.
			Assert::AreNotEqual(size_t(25), p.get_Grille().full_house(), L"la valeur retourné est 40 (grande suite).");
		}

		/*
		* Test of method change_availibilities.
		*/
		TEST_METHOD(Test_change_availibilities) {
			
			player p("oussama");
			


			Assert::IsTrue(p.get_Grille().get_berlan_isAvailable(), L"la case brelan dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_carre_isAvailable(), L"la case carre dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_chance_isAvailable(), L"la case chance dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_fullHouse_isAvailable(), L"la case fullHouse dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_gsuite_isAvailable(), L"la case grande suite dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_psuite_isAvailable(), L"la case petite suite dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_total_1_isAvailable(), L"la case total_1 dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_total_2_isAvailable(), L"la case total_2 dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_total_3_isAvailable(), L"la case total_3 dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_total_4_isAvailable(), L"la case total_4 dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_total_5_isAvailable(), L"la case total_5 dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_total_6_isAvailable(), L"la case total_6 dans la grille est disponible.");
			Assert::IsTrue(p.get_Grille().get_yahtzee_isAvailable(), L"la case yahtzee dans la grille est disponible.");
			

			p.change_availibilities("1");//total_1.
			Assert::IsFalse(p.get_Grille().get_total_1_isAvailable(), L"la case total_1 dans la grille n'est pas disponible.");
			p.change_availibilities("brelan");//brelan.
			Assert::IsFalse(p.get_Grille().get_berlan_isAvailable(), L"la case brelan dans la grille n'est pas disponible.");
			p.change_availibilities("yahtzee");//yahtzee
			Assert::IsFalse(p.get_Grille().get_yahtzee_isAvailable(), L"la case yahtzee dans la grille n'est pas disponible.");
		}
		/*
		* Test of method sup is Fill.
		*/
		TEST_METHOD(Test_sup_isFill) {
			
			player p("mehdi");
			

			Assert::IsFalse(p.sup_isFill(),L"la partie supérieur est vide.");

			p.change_availibilities("1");//total_1.
			p.change_availibilities("2");//total_2.
			p.change_availibilities("3");//total_3.

			Assert::IsFalse(p.sup_isFill(), L"la partie supérieur est vide.");


			p.change_availibilities("1");//total_1.
			p.change_availibilities("2");//total_2.
			p.change_availibilities("3");//total_3.
			p.change_availibilities("4");//total_4.
			p.change_availibilities("5");//total_5.
			p.change_availibilities("6");//total_6.
			
			Assert::IsTrue(p.sup_isFill(), L"la partie supérieur n'est pas vide.");
		}

		/*
		* Test of method inf is fill.
		*/
		TEST_METHOD(Test_inf_isFill) {
			
			player p("mehdi");
			Assert::IsFalse(p.inf_isFill(), L"La partie inférieur est vide.");
			p.change_availibilities("brelan");//brelan.
			p.change_availibilities("carre");//carre.
			p.change_availibilities("full");//full House.
			
			Assert::IsFalse(p.inf_isFill(), L"La partie inférieur est vide.");

			p.change_availibilities("psuite");//petite suite.
			p.change_availibilities("gsuite");//grande suite.
			p.change_availibilities("yahtzee");//yahtzee suite.
			p.change_availibilities("chance");//chance suite.

			Assert::IsTrue(p.inf_isFill(), L"La partie inférieur n'est pas vide.");
		}

		/*
		* Test of method grille is fill.
		*/
		TEST_METHOD(Test_grille_isFill) {
			player p("oussama");

			Assert::IsFalse(p.grille_isFill(), L"La grille est vide.");

			p.change_availibilities("1");//total_1.
			p.change_availibilities("2");//total_2.
			p.change_availibilities("3");//total_3.
			p.change_availibilities("4");//total_4.
			Assert::IsFalse(p.grille_isFill(), L"La grille est vide.");

			p.change_availibilities("5");//total_5.
			p.change_availibilities("6");//total_6.
			p.change_availibilities("brelan");//brelan.
			p.change_availibilities("carre");//carre.
			p.change_availibilities("full");//full House.

			Assert::IsFalse(p.grille_isFill(), L"La grille est vide.");

			p.change_availibilities("psuite");//petite suite.
			p.change_availibilities("gsuite");//grande suite.
			p.change_availibilities("yahtzee");//yahtzee suite.
			p.change_availibilities("chance");//chance suite.

			Assert::IsTrue(p.grille_isFill(), L"La grille n'est pas vide.");
		}

	};
}
