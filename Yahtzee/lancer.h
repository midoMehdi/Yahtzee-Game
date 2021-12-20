#pragma once
#include<iostream>
#include"dice.h"
class lancer
{
	dice* m_dice;

public:

	lancer(dice &dice);
	~lancer();
	void lancerDice();
	
};

