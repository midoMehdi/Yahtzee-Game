
#include<iostream>
#include"dice.h"
#include<vector>
#include"sortFunctor.h"
#include"grille.h"
#include"figure.h"

class player
{
	
	std::vector<dice> dices;
	grille m_grille;
	bool bonus_sup; // verifie si le bonus est appliqué.

	int checkBrelan() const;
	int checkCarre() const;
	bool checkFullHouse() const;
	bool checkPetiteSuite() const;
	bool checkGrandeSuite() const;
	bool checkYahtzee() const;
	
	
public:
	unsigned int m_score;
	std::string m_name;

	player(std::string name);
	~player();

	void addDice(const dice& _dice);
	std::string printName()const;
	void printDices() const;
	dice get_specific_dice(size_t index) const;
	void change_dice(size_t index, dice _dice);
	std::vector<dice>& allDices()  ;
	

	void calcul_possibilities(bool sup_predicat, bool inf_predicat, int random_choice) const;
	//void calcul_possibilities_level_difficile(int random_choice) const;
	void write_in_grille(const std::string& choice);
	grille& get_Grille();
	void change_availibilities(const std::string& choix);
	bool sup_isFill() const;
	bool inf_isFill() const;
	bool grille_isFill() const;

	//unsigned int get_score() const; 
	//std::string get_name() const;je prèfere pas cette solution, création d'un autre objet, (public)

};

