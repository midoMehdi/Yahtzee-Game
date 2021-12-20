#include "player.h"
#include<iostream>
#include<algorithm>
#include<Windows.h>
using namespace std;

//================================================================================================


player::player(std::string name) : m_name(name), m_score(0), m_grille(name), bonus_sup(false),dices(0)
{
	
}

//================================================================================================



//================================================================================================

player::~player()
{
}

//================================================================================================



//================================================================================================


void player::addDice(const dice& _dice)
{
	if (dices.size() == 5)
		dices.clear();
	this->dices.push_back(_dice);
}

//================================================================================================



//================================================================================================

std::string player::printName() const
{
	return m_name;
}

//================================================================================================



//================================================================================================

void player::printDices() const
{
	
	for_each(dices.begin(), dices.end(), [](const dice& d) {
		cout<<d()<< " ";
		
		std::fflush;
		Sleep(200);
		
		});
	
}

//================================================================================================



//================================================================================================

dice player::get_specific_dice(size_t index) const
{
	return dices.at(index);
}

//================================================================================================



//================================================================================================

void player::change_dice(size_t index,dice _dice)
{
	dices.at(index) = _dice;
}

//================================================================================================



//================================================================================================

vector<dice>& player::allDices() 
{
	return dices;
}

//================================================================================================



//================================================================================================


int player::checkBrelan() const
{
	vector<dice> copy_dices(dices);
	std::sort(copy_dices.begin(), copy_dices.end(), [](const dice& d1, const dice& d2) { return d1() < d2(); });
	int tester = -1;
	if (copy_dices.at(0).m_value == copy_dices.at(1).m_value && copy_dices.at(1).m_value == copy_dices.at(2).m_value)
		tester = 0;
	else if (copy_dices.at(1).m_value == copy_dices.at(2).m_value && copy_dices.at(2).m_value == copy_dices.at(3).m_value)
		tester = 1;
	else if (copy_dices.at(2).m_value == copy_dices.at(3).m_value && copy_dices.at(3).m_value == copy_dices.at(4).m_value)
		tester = 2;

	if (tester != -1)//la valeur de tester correspond au premier dè de la figure brelan.
		return copy_dices.at(tester)();

	return tester;
}

//================================================================================================



//================================================================================================

int player::checkCarre() const
{
	vector<dice> copy_dices(dices);
	std::sort(copy_dices.begin(), copy_dices.end(), [](const dice& d1, const dice& d2) { return d1() < d2(); });
	int tester = -1;
	if (copy_dices.at(0).m_value == copy_dices.at(1).m_value 
		&& copy_dices.at(1).m_value == copy_dices.at(2).m_value 
		&& copy_dices.at(2).m_value == copy_dices.at(3).m_value)

		tester = 0;

	else if (copy_dices.at(1).m_value == copy_dices.at(2).m_value 
		&& copy_dices.at(2).m_value == copy_dices.at(3).m_value 
		&& copy_dices.at(3).m_value == copy_dices.at(4).m_value)

		tester = 1;
	

	if (tester != -1)//la valeur de tester correspond au premier dè de la figure brelan.(-1 : n'existe pas).
		return copy_dices.at(tester)();

	return tester;
}

//================================================================================================



//================================================================================================


bool player::checkFullHouse() const
{

	vector<dice> copy_dices(dices);
	std::sort(copy_dices.begin(), copy_dices.end(), [](const dice& d1, const dice& d2) { return d1() < d2(); });

	return ( ((copy_dices.at(0).m_value == copy_dices.at(1).m_value) 
			 && (copy_dices.at(2).m_value == copy_dices.at(3).m_value 
		     && copy_dices.at(3).m_value == copy_dices.at(4).m_value))
			 || 
			 (copy_dices.at(0).m_value == copy_dices.at(1).m_value 
			 && copy_dices.at(1).m_value == copy_dices.at(2).m_value) 
			 && copy_dices.at(3).m_value == copy_dices.at(4).m_value);
}

//================================================================================================


//================================================================================================

bool player::checkPetiteSuite() const
{
	vector<dice> copy_dices(dices);
	std::sort(copy_dices.begin(), copy_dices.end(), [](const dice& d1, const dice& d2) { return d1() < d2(); });

	if( (copy_dices.at(0).m_value == 1 && copy_dices.at(1).m_value == 2 && copy_dices.at(2).m_value == 3 && copy_dices.at(3).m_value == 4))
		return true;
	else if (copy_dices.at(1).m_value == 2 && copy_dices.at(2).m_value == 3 && copy_dices.at(3).m_value == 4 && copy_dices.at(3).m_value == 5) {
		return true;
	}

	return false;
	
}

//================================================================================================


//================================================================================================



bool player::checkGrandeSuite() const
{
	vector<dice> copy_dices(dices);
	std::sort(copy_dices.begin(), copy_dices.end(), [](const dice& d1, const dice& d2) { return d1() < d2(); });

	return copy_dices.at(0).m_value == 1 && copy_dices.at(1).m_value == 2 && copy_dices.at(2).m_value == 3 && copy_dices.at(3).m_value == 4 && copy_dices.at(4).m_value == 5;
}


//================================================================================================


//================================================================================================


bool player::checkYahtzee() const
{
	vector<dice> copy_dices(dices);
	std::sort(copy_dices.begin(), copy_dices.end(), [](const dice& d1, const dice& d2) { return d1() < d2(); });
	return copy_dices.at(0).m_value == copy_dices.at(4).m_value;
}

//================================================================================================


//================================================================================================


void player::calcul_possibilities(bool sup_predicat, bool inf_predicat, int random_choice) const {

	if (( m_grille.get_berlan_isAvailable() && inf_predicat) || (m_grille.get_berlan_isAvailable() && random_choice == 7)) {// on peut pas passer _player.checkBrelan() as a template parameter; solution : switch (^_^).
		figure* f = NULL;
		switch (checkBrelan())
		{
		case 1:
			f = new brelan<1>(dices);
			cout << "|       brelan =         " << f->calculate() << endl;
			break;
		case 2:
			f = new brelan<2>(dices);
			cout << "|       brelan =         " << f->calculate() << endl;
			break;
		case 3:
			f = new brelan<3>(dices);
			cout << "|       brelan =         " << f->calculate() << endl;
			break;
		case 4:
			f = new brelan<4>(dices);
			cout << "|       brelan =         " << f->calculate() << endl;
			break;
		case 5:
			f = new brelan<5>(dices);
			cout << "|       brelan =         " << f->calculate() <<  endl;
			break;
		case 6:
			f = new brelan<6>(dices);
			cout << "|       brelan =         " << f->calculate() <<  endl;
			break;
		default:
			f = new brelan<0>(dices);
			cout << "|       brelan =         " << f->calculate() <<  endl;
			break;
		}

		Sleep(100);
		delete f;

	}

	if ((m_grille.get_carre_isAvailable() && inf_predicat) || (m_grille.get_carre_isAvailable() && random_choice == 8)) {

		figure* f = NULL;
		switch (checkCarre())
		{
		case 1:
			f = new carre<1>(dices);
			cout << "|       carre  =             " << f->calculate() <<  endl;
			break;
		case 2:
			f = new carre<2>(dices);
			cout << "|       carre  =             " << f->calculate() <<  endl;
			break;
		case 3:
			f = new carre<3>(dices);
			cout << "|       carre  =             " << f->calculate() <<  endl;
			break;
		case 4:
			f = new carre<4>(dices);
			cout << "|       carre  =             " << f->calculate() <<  endl;
			break;
		case 5:
			f = new carre<5>(dices);
			cout << "|       carre  =             " << f->calculate() <<  endl;
			break;
		case 6:
			f = new carre<6>(dices);
			cout << "|       carre  =             " << f->calculate() <<  endl;
			break;
		default:
			f = new carre<0>(dices);
			cout << "|       carre  =             " << f->calculate() << endl;
			break;
		}

		Sleep(100);
		delete f;
	}


	if ((m_grille.get_fullHouse_isAvailable() && inf_predicat) || (m_grille.get_fullHouse_isAvailable() && random_choice == 11)) {
		if (checkFullHouse()) {
			figure* f = new full(dices);
			cout << "|       full house =        " << f->calculate() <<  endl;
			Sleep(300);
			delete f;
		}
		else {
			cout << "|       full house =        " << 0 << setw(11) <<  endl;
			Sleep(100);
		}

	}

	if ((m_grille.get_psuite_isAvailable() && inf_predicat) || (m_grille.get_psuite_isAvailable() && random_choice == 9)) {
		if (checkPetiteSuite()) {
			figure* f = new psuite(dices);
			cout << "|       petite suite =      " << f->calculate() <<  endl;
			Sleep(100);
			delete f;
		}
		else {
			cout << "|       petite suite =      " << 0 <<  endl;
			Sleep(100);
		}

	}

	if ((m_grille.get_gsuite_isAvailable() && inf_predicat) || (m_grille.get_gsuite_isAvailable() && random_choice == 10)) {
		if (checkGrandeSuite()) {
			figure* f = new gsuite(dices);
			cout << "|       grandee suite =     " << f->calculate() << endl;
			Sleep(100);
			delete f;
		}
		else {
			cout << "|       grandee suite =     " << 0 << endl;
			Sleep(100);
		}

	}

	if ((m_grille.get_yahtzee_isAvailable() && inf_predicat) || (m_grille.get_yahtzee_isAvailable() && random_choice == 12)) {
		if (checkYahtzee()) {
			figure* f = new yahtzee(dices);
			cout << "|       yahtzee =           " << f->calculate() <<  endl;
			Sleep(100);
			delete f;
		}
		else {
			cout << "|       yahtzee =           " << 0 <<  endl;
			Sleep(100);
		}

	}

	if ((m_grille.get_chance_isAvailable() && inf_predicat) || (m_grille.get_chance_isAvailable() && random_choice == 13)) {
		figure* f = new chance(dices);
		cout << "|       chance =        " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	if ((m_grille.get_total_1_isAvailable() && sup_predicat) || (m_grille.get_total_1_isAvailable() && random_choice == 1)) {
		figure* f = new total_one(dices);
		cout << "|       total de 1 =    " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	if ((m_grille.get_total_2_isAvailable() && sup_predicat) || (m_grille.get_total_2_isAvailable() && random_choice == 2)) {
		figure* f = new total_two(dices);
		cout << "|       total de 2 =    " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	if ((m_grille.get_total_3_isAvailable() && sup_predicat) || (m_grille.get_total_3_isAvailable() && random_choice == 3)) {
		figure* f = new total_three(dices);
		cout << "|       total de 3 =    " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	if ((m_grille.get_total_4_isAvailable() && sup_predicat) || (m_grille.get_total_4_isAvailable() && random_choice == 4)) {
		figure* f = new total_four(dices);
		cout << "|       total de 4 =    " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	if ((m_grille.get_total_5_isAvailable() && sup_predicat) || (m_grille.get_total_5_isAvailable() && random_choice == 5)) {
		figure* f = new total_five(dices);
		cout << "|       total de 5 =    " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	if ((m_grille.get_total_6_isAvailable() && sup_predicat) || (m_grille.get_total_6_isAvailable() && random_choice == 6)) {
		figure* f = new total_six(dices);
		cout << "|       total de 6 =    " << f->calculate() <<  endl;
		Sleep(100);
		delete f;
	}

	cout
		<< " ----------------------------------" << endl;
}


//================================================================================================


//================================================================================================



void player::write_in_grille(const std::string& choice)
{
	if (choice == "1") {
		figure* f = new total_one(dices);
		//m_grille.total_1() = f->calculate();
		m_grille.total_1() = f->calculate();
		//m_grille.m_total_1 = f->calculate();
		m_grille.total_superieur() += m_grille.total_1();
		m_grille.total() += m_grille.total_1();
		delete f;
	}
	else if (choice == "2") {
		figure* f = new total_two(dices);
		m_grille.m_total_2 = f->calculate();
		m_grille.total_superieur() += m_grille.m_total_2;
		m_grille.total() += m_grille.m_total_2;
		delete f;
	}
	else if (choice == "3") {
		figure* f = new total_three(dices);
		m_grille.total_3() = f->calculate();
		m_grille.total_superieur() += m_grille.m_total_3;
		m_grille.total() += m_grille.m_total_3;
		delete f;
	}
	else if (choice == "4") {
		figure* f = new total_four(dices);
		m_grille.total_4() = f->calculate();
		m_grille.total_superieur() += m_grille.m_total_4;
		m_grille.total() += m_grille.m_total_4;
		delete f;
	}
	else if (choice == "5") {
		figure* f = new total_five(dices);
		m_grille.total_5() = f->calculate();
		m_grille.total_superieur() += m_grille.m_total_5;
		m_grille.total() += m_grille.m_total_5;
		delete f;
	}
	else if (choice == "6") {
		figure* f = new total_six(dices);
		m_grille.total_6() = f->calculate();
		m_grille.total_superieur() += m_grille.m_total_6;
		m_grille.total() += m_grille.m_total_6;
		delete f;
	}
	else if (choice == "brelan") {
		if (m_grille.get_berlan_isAvailable() ) {
			
			figure* f = NULL;
			switch (checkBrelan())
			{
			case 1:
				f = new brelan<1>(dices);
				m_grille.m_brelan = f->calculate();
				m_grille.total_inferieur() += m_grille.m_brelan;
				m_grille.total() += m_grille.m_brelan;
				break;
			case 2:
				f = new brelan<2>(dices);
				m_grille.m_brelan = f->calculate();
				m_grille.total_inferieur() += m_grille.m_brelan;
				m_grille.total() += m_grille.m_brelan;
				break;
			case 3:
				f = new brelan<3>(dices);
				m_grille.m_brelan = f->calculate();
				m_grille.total_inferieur() += m_grille.m_brelan;
				m_grille.total() += m_grille.m_brelan;
				break;
			case 4:
				f = new brelan<4>(dices);
				m_grille.m_brelan = f->calculate();
				m_grille.total_inferieur() += m_grille.m_brelan;
				m_grille.total() += m_grille.m_brelan;
				break;
			case 5:
				f = new brelan<5>(dices);
				m_grille.m_brelan = f->calculate();
				m_grille.total_inferieur() += m_grille.m_brelan;
				m_grille.total() += m_grille.m_brelan;
				break;
			case 6:
				f = new brelan<6>(dices);
				m_grille.m_brelan = f->calculate();
				m_grille.total_inferieur() += m_grille.m_brelan;
				m_grille.total() += m_grille.m_brelan;
				break;
			default:
				f = new brelan<0>(dices);
				cout << "test default" << endl;
				m_grille.m_brelan = f->calculate();
				
				break;
			}

			Sleep(300);
			delete f;

		}
		else {
			cout << "error" << endl;
		}
	}
	else if (choice == "carre") {
		if (m_grille.get_carre_isAvailable() /*&& _player.checkCarre() != -1*/) {

			figure* f = NULL;
			switch (checkCarre())
			{
			case 1:
				f = new carre<1>(dices);
				m_grille.m_carre = f->calculate();
				m_grille.total_inferieur() += m_grille.m_carre;
				m_grille.total() += m_grille.m_carre;
				break;
			case 2:
				f = new carre<2>(dices);
				m_grille.m_carre = f->calculate();
				m_grille.total_inferieur() += m_grille.m_carre;
				m_grille.total() += m_grille.m_carre;
				break;
			case 3:
				f = new carre<3>(dices);
				m_grille.m_carre = f->calculate();
				m_grille.total_inferieur() += m_grille.m_carre;
				m_grille.total() += m_grille.m_carre;
				break;
			case 4:
				f = new carre<4>(dices);
				m_grille.m_carre = f->calculate();
				m_grille.total_inferieur() += m_grille.m_carre;
				m_grille.total() += m_grille.m_carre;
				break;
			case 5:
				f = new carre<5>(dices);
				m_grille.m_carre = f->calculate();
				m_grille.total_inferieur() += m_grille.m_carre;
				m_grille.total() += m_grille.m_carre;
				break;
			case 6:
				f = new carre<6>(dices);
				m_grille.m_carre = f->calculate();
				m_grille.total_inferieur() += m_grille.m_carre;
				m_grille.total() += m_grille.m_carre;
				break;
			default:
				f = new carre<0>(dices);
				m_grille.m_carre = f->calculate();
				
				break;
			}

			Sleep(300);
			delete f;
		}
		else {
			cout << "error" << endl;
		}
	}
	else if (choice == "full") {
		if (m_grille.get_fullHouse_isAvailable()) {
			if (checkFullHouse()) {
				figure* f = new full(dices);
				m_grille.m_full_house = f->calculate();
				m_grille.total_inferieur() += m_grille.m_full_house;
				m_grille.total() += m_grille.m_full_house;
				delete f;
			}
			else {
				m_grille.m_full_house = 0;
			}
		}
		else {
			cout << "error" << endl;
		}
		
	}
	else if (choice == "psuite") {
		if (m_grille.get_psuite_isAvailable()) {
			if (checkPetiteSuite()) {
				figure* f = new psuite(dices);
				m_grille.m_petite_suite = f->calculate();
				m_grille.total_inferieur() += m_grille.m_petite_suite;
				m_grille.total() += m_grille.m_petite_suite;
				delete f;
			}
			else {
				m_grille.m_petite_suite = 0;
			}
		}
		else {
			cout << "error" << endl;
		}
		
	}
	else if (choice == "gsuite") {
		if (m_grille.get_gsuite_isAvailable()) {
			if (checkGrandeSuite()) {
				figure* f = new gsuite(dices);
				m_grille.m_grande_suite = f->calculate();
				m_grille.total_inferieur() += m_grille.m_grande_suite;
				m_grille.total() += m_grille.m_grande_suite;
				delete f;
			}
			else {
				m_grille.m_grande_suite = 0;
			}
		}
		else{
			cout << "error" << endl;
		}
		
	}
	else if (choice == "yahtzee") {
		if (m_grille.get_yahtzee_isAvailable()) {
			if (checkYahtzee()) {
				figure* f = new yahtzee(dices);
				m_grille.m_yahtzee = f->calculate();
				m_grille.total_inferieur() += m_grille.m_yahtzee;
				m_grille.total() += m_grille.m_yahtzee;
				delete f;
			}
			else {
				m_grille.m_yahtzee = 0;
			}
		}
		else {
			cout << "error" << endl;
		}
	}
	else if (choice == "chance") {
		figure* f = new chance(dices);
		m_grille.m_chance = f->calculate();
		m_grille.total_inferieur() += m_grille.m_chance;
		m_grille.total() += m_grille.m_chance;
		delete f;
	}

	if (m_grille.m_total_superieur > 62 && m_grille.bonus_isAvailable) {
		m_grille.m_bonus = 35;
		m_grille.total_superieur() += m_grille.m_bonus;
		m_grille.total() += m_grille.m_bonus;
	}

	m_score = m_grille.total();
	m_grille.print_grille();
}

//================================================================================================



//================================================================================================



grille& player::get_Grille() 
{
	return m_grille;
}


//================================================================================================



//================================================================================================



void player::change_availibilities(const std::string& choice)
{
	if (choice == "1") {
		//cout << "hehi" << endl;
		m_grille.total_1_isAvailable = false;
	}
	else if (choice == "2") {
		m_grille.total_2_isAvailable = false;
	}
	else if (choice == "3") {
		m_grille.total_3_isAvailable = false;
	}
	else if (choice == "4") {
		m_grille.total_4_isAvailable = false;
	}
	else if (choice == "5") {
		m_grille.total_5_isAvailable = false;
	}
	else if (choice == "6") {
		m_grille.total_6_isAvailable = false;
	}
	else if (choice == "brelan") {
		m_grille.berlan_isAvailable = false;
	}
	else if (choice == "carre") {
		m_grille.carre_isAvailable = false;
	}
	else if (choice == "full") {
		m_grille.fullHouse_isAvailable = false;
	}
	else if (choice == "psuite") {
		m_grille.psuite_isAvailable = false;
	}
	else if (choice == "gsuite") {
		m_grille.gsuite_isAvailable = false;
	}
	else if (choice == "yahtzee") {
		m_grille.yahtzee_isAvailable = false;
	}
	else if (choice == "chance") {
		m_grille.chance_isAvailable = false;
	}
	if (m_grille.m_total_superieur > 62) {
		m_grille.bonus_isAvailable = false;
	}
}


//================================================================================================



//================================================================================================


bool player::sup_isFill() const
{
	return m_grille.sup_completed();
}

//================================================================================================



//================================================================================================


bool player::inf_isFill() const
{
	return m_grille.inf_completed();
}


//================================================================================================



//================================================================================================


bool player::grille_isFill() const
{
	return m_grille.grille_completed();
}



//================================================================================================

