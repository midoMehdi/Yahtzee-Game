#pragma once
#include<iostream>
class dice
{
	unsigned int m_value;
public:
	dice();
	dice(unsigned int value);
	dice& operator=(const dice& d);
	~dice();
	void printValue() const;
	operator unsigned int();
	unsigned int operator() () const ;
	friend std::ostream& operator<<(std::ostream& out, const dice& d);
	friend class lancer;
	friend class player;

};

