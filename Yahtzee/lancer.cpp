#include "lancer.h"
#include<iostream>
#include<random>
using namespace std;
lancer::lancer(dice& dice)
{
	m_dice = &dice;
}

lancer::~lancer()
{
}

void lancer::lancerDice()
{
	m_dice->m_value = (rand() % 6) + 1;	
	
}
