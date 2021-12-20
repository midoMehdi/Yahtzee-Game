#pragma once
#include<iostream>
#include"dice.h"

class sortFunctor
{
public:
	bool operator()(const dice& d1, const dice& d2) {
		return d1() <= d2();
	}
};

