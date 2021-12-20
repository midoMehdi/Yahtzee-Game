#include "grille.h"
#include<iostream>
#include<string>
using namespace std;



std::string grille::check_availability(bool _predicat, unsigned int value) const
{
	
	if (!_predicat) {
		//cout << value << endl;
		string s = to_string(value);
		return s;
	}
	else {
		std::string s = "value";
		return s;
	}
}

//================================================================================================


//================================================================================================

std::string grille::check_bonus(bool _predicat, unsigned int value) const
{
	if (value > 62) {
		
		return to_string(35);
	}
	else {
		return to_string(0);
	}
	
}


//================================================================================================


//================================================================================================

grille::grille()
{
}

grille::grille(string name_player) : m_name_player(name_player)

{
	this->m_total_1 = 0;
	this->total_1_isAvailable = true;
	this->total_2_isAvailable = true;
	this->total_3_isAvailable = true;
	this->total_4_isAvailable = true;
	this->total_5_isAvailable = true;
	this->total_6_isAvailable = true;
	this->berlan_isAvailable = true;
	this->carre_isAvailable = true;
	this->fullHouse_isAvailable = true;
	this->psuite_isAvailable = true;
	this->gsuite_isAvailable = true;
	this->yahtzee_isAvailable = true;
	this->chance_isAvailable = true;

	this->grille_isFill = false;
	
}


//================================================================================================


//================================================================================================



grille::~grille()
{
}


//================================================================================================


//================================================================================================



void grille::print_grille() const
{
	cout
		<< "--------------------" << "-----" << " " << "-------------" << " " << setw(60) << "--------------------\n"
		<< setw(26) << "|" << setw(12) << m_name_player << setw(3) << "|" << setw(52) << "|Enter for : \n"
		<< "--------------------" << "-----" << "|" << "-------------" << "|" << setw(60) << "--------------------\n"
		<< "|1 [total 1]. de 1   " << setw(5) << "|" << setw(9) << check_availability(total_1_isAvailable, m_total_1) << setw(6) << "|" << setw(39) << "|" << setw(10) << "1\n"
		<< "|2 [total 2]. de 2   " << setw(5) << "|" << setw(9) << check_availability(total_2_isAvailable, m_total_2) << setw(6) << "|" << setw(39) << "|" << setw(10) << "2\n"
		<< "|3 [total 3]. de 3   " << setw(5) << "|" << setw(9) << check_availability(total_3_isAvailable, m_total_3) << setw(6) << "|" << setw(39) << "|" << setw(10) << "3\n"
		<< "|4 [total 4]. de 4   " << setw(5) << "|" << setw(9) << check_availability(total_4_isAvailable, m_total_4) << setw(6) << "|" << setw(39) << "|" << setw(10) << "4\n"
		<< "|5 [total 5]. de 5   " << setw(5) << "|" << setw(9) << check_availability(total_5_isAvailable, m_total_5) << setw(6) << "|" << setw(39) << "|" << setw(10) << "5\n"
		<< "|6 [total 6]. de 6   " << setw(5) << "|" << setw(9) << check_availability(total_6_isAvailable, m_total_6) << setw(6) << "|" << setw(39) << "|" << setw(10) << "6\n"
		<< "|Bonus si > a 62 [35]" << setw(5) << "|" << setw(9) << check_bonus(bonus_isAvailable, m_bonus) << setw(6) << "|" << setw(40) << "|\n"
		<< "|Total superieur     " << setw(5) << "|" << setw(9) << m_total_superieur << setw(6) << "|" << setw(40) << "|\n"
		<< "--------------------" << "-----" << "|" << "-------------" << "|" << setw(60) << "--------------------\n"
		;
	cout
		<< "--------------------" << "-----" << "|" << "-------------" << "|" << setw(60) << "--------------------\n"
		<< "|Berlan(3id) total" << setw(8) << "|" << setw(9) << check_availability(berlan_isAvailable, m_brelan) << setw(6) << "|" << setw(39) << "|" << setw(13) << "brelan\n"
		<< "|Carre (4id) total" << setw(8) << "|" << setw(9) << check_availability(carre_isAvailable, m_carre) << setw(6) << "|" << setw(39) << "|" << setw(13) << "carre\n"
		<< "|Full House [25]  " << setw(8) << "|" << setw(9) << check_availability(fullHouse_isAvailable, m_full_house) << setw(6) << "|" << setw(39) << "|" << setw(13) << "full\n"
		<< "|Petite suite [30]" << setw(8) << "|" << setw(9) << check_availability(psuite_isAvailable, m_petite_suite) << setw(6) << "|" << setw(39) << "|" << setw(13) << "psuite\n"
		<< "|Grande suite [40]" << setw(8) << "|" << setw(9) << check_availability(gsuite_isAvailable, m_grande_suite) << setw(6) << "|" << setw(39) << "|" << setw(13) << "gsuite\n"
		<< "|Yahtzee [50]     " << setw(8) << "|" << setw(9) << check_availability(yahtzee_isAvailable, m_yahtzee) << setw(6) << "|" << setw(39) << "|" << setw(13) << "yahtzee\n"
		<< "|Chance [Total]   " << setw(8) << "|" << setw(9) << check_availability(chance_isAvailable, m_chance) << setw(6) << "|" << setw(39) << "|" << setw(13) << "chance\n"
		<< "|Total inferieur  " << setw(8) << "|" << setw(9) << m_total_inferieur << setw(6) << "|" << setw(40) << "|\n"
		<< "--------------------" << "-----" << "|" << "-------------" << "|" << setw(60) << "--------------------\n"
		;
	cout << "--------------------" << "-----" << " " << "-------------" << " \n"
		<< "|Total              " << setw(6) << "|" << setw(9) << m_total << setw(6) << "|\n"
		<< "--------------------" << "-----" << " " << "-------------" << " \n"
		<< endl;
}

//================================================================================================


//================================================================================================


bool grille::sup_completed() const
{
	return !total_1_isAvailable && !total_2_isAvailable && !total_3_isAvailable && !total_4_isAvailable && !total_5_isAvailable && !total_6_isAvailable;
}

bool grille::inf_completed() const
{
	return !berlan_isAvailable && !carre_isAvailable && !fullHouse_isAvailable && !psuite_isAvailable && !gsuite_isAvailable && !yahtzee_isAvailable && !chance_isAvailable;
}

bool grille::grille_completed() const
{
	return inf_completed()
		&& sup_completed();
		
	
}
