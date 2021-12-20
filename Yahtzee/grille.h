#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
class grille
{
	std::string m_name_player;
	/*Attibut pour la partie superieur de la grille*/
	unsigned int m_total_1;
	unsigned int m_total_2;
	unsigned int m_total_3;
	unsigned int m_total_4;
	unsigned int m_total_5;
	unsigned int m_total_6;
	unsigned int m_bonus;
	unsigned int m_total_superieur;

	/*Attibut pour la partie inferieur de la grille*/
	unsigned int m_brelan;
	unsigned int m_carre;
	unsigned int m_full_house;
	unsigned int m_petite_suite;
	unsigned int m_grande_suite;
	unsigned int m_yahtzee;
	unsigned int m_chance;
	unsigned int m_total_inferieur;
	
	unsigned int m_total;


	/* verifie si la case est vide ou non .*/
	bool total_1_isAvailable;
	bool total_2_isAvailable;
	bool total_3_isAvailable;
	bool total_4_isAvailable;
	bool total_5_isAvailable;
	bool total_6_isAvailable;
	bool bonus_isAvailable;
	bool berlan_isAvailable;
	bool carre_isAvailable;
	bool fullHouse_isAvailable;
	bool psuite_isAvailable;
	bool gsuite_isAvailable;
	bool yahtzee_isAvailable;
	bool chance_isAvailable;

	bool grille_isFill;


	std::string check_availability(bool _predicat, unsigned int value) const ;
	std::string check_bonus(bool _predicat, unsigned int value) const ;
public:
	friend class player;
	grille();
	grille(std::string name_player);
	~grille();
	
	void print_grille() const;
	
	unsigned int& total_1() {
		return m_total_1;
	}

	const unsigned int& total_1() const {
		return m_total_1;
	}

	unsigned int& total_2() {
		return m_total_2;
	}

	const unsigned int& total_2() const {
		return m_total_2;
	}

	
	unsigned int& total_3() {
		return m_total_3;
	}

	const unsigned int& total_3() const {
		return m_total_3;
	}
	
	unsigned int& total_4() {
		return m_total_4;
	}

	const unsigned int& total_4() const {
		return m_total_4;
	}

	unsigned int& total_5() {
		return m_total_5;
	}

	const unsigned int& total_5() const {
		return m_total_5;
	}

	unsigned int& total_6() {
		return m_total_6;
	}

	const unsigned int& total_6() const {
		return m_total_6;
	}

	unsigned int& total_superieur() {
		return m_total_superieur;
	}

	const unsigned int& total_superieur() const {
		return m_total_superieur;
	}

	unsigned int& brelan() {
		return m_brelan;
	}

	const unsigned int& brelan() const {
		return m_brelan;
	}

	unsigned int& carre() {
		return m_carre;
	}

	const unsigned int& carre() const {
		return m_carre;
	}

	unsigned int& full_house() {
		return m_full_house;
	}

	const unsigned int& full_house() const {
		return m_full_house;
	}

	unsigned int& petite_suite() {
		return m_petite_suite;
	}

	const unsigned int& petite_suite() const {
		return m_petite_suite;
	}

	unsigned int& grande_suite() {
		return m_grande_suite;
	}

	const unsigned int& grande_suite() const {
		return m_grande_suite;
	}

	unsigned int& yahtzee() {
		return m_yahtzee;
	}

	const unsigned int& yahtzee() const {
		return m_yahtzee;
	}

	unsigned int& total_inferieur() {
		return m_total_inferieur;
	}

	const unsigned int& total_inferieur() const {
		return m_total_inferieur;
	}
	unsigned int& total() {
		return m_total;
	}

	const unsigned int& total() const {
		return m_total;
	}

	
	bool get_total_1_isAvailable() const {
		return this->total_1_isAvailable;
	}

	bool get_total_2_isAvailable() const {
		return this->total_2_isAvailable;
	}
	bool get_total_3_isAvailable() const {
		return this->total_3_isAvailable;
	}
	bool get_total_4_isAvailable() const {
		return this->total_4_isAvailable;
	}

	bool get_total_5_isAvailable() const {
		return this->total_5_isAvailable;
	}
	bool get_total_6_isAvailable() const {
		return this->total_6_isAvailable;
	}
	bool get_berlan_isAvailable() const {
		return this->berlan_isAvailable;
	}
	bool get_carre_isAvailable() const {
		return this->carre_isAvailable;
	}
	bool get_fullHouse_isAvailable() const {
		return this->fullHouse_isAvailable;
	}
	bool get_psuite_isAvailable() const {
		return this->psuite_isAvailable;
	}
	bool get_gsuite_isAvailable() const {
		return this->gsuite_isAvailable;
	}
	bool get_yahtzee_isAvailable() const {
		return this->yahtzee_isAvailable;
	}
	bool get_chance_isAvailable() const {
		return this->chance_isAvailable;
	}

	bool sup_completed() const;
	bool inf_completed() const;
	bool grille_completed()const;
};

