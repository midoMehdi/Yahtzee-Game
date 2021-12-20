#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"dice.h"


class figure
{
	
protected:
	std::vector<dice> dices;
	
public:
	
	virtual unsigned int calculate() = 0;
	
};


template<unsigned int x> 
class brelan : public figure {

public:
	
	brelan(std::vector<dice> ds)  {
		dices = ds;
	}

	unsigned int calculate() {
		return 3 * x;
	}
	

};
 

template<unsigned int x>
class carre : public figure {
	
public:

	carre(std::vector<dice> ds)  {
		dices = ds;
	}

	unsigned int calculate() {
		return 4 * x;
	}
	//bool isFill() const;
};




class full : public figure {

public:


	full(std::vector<dice> ds){
		dices = ds;
	}

	
	unsigned int calculate() {
		return 25;
	}
	//bool isFill() const;
};



class psuite : public figure { //petite suite

public:

	psuite(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		return 30;
	}
	//bool isFill() const;
};



class gsuite : public figure {

public:


	gsuite(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		return 40;
	}
	//bool isFill() const;
};



class yahtzee : public figure {

public:


	yahtzee(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		return 50;
	}
	//bool isFill() const;
};



class chance : public figure {

public:

	chance(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {sum += n; }); // c'est ici ou j'ai utilisé l'operator de conversion ( class dice : operator unsigned int() )
		return sum;
	}
	//bool isFill() const;
};




class total_one : public figure {
public:


	total_one(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {if(n == 1)sum += n; });
		return sum;
	}
	//bool isFill() const;
};



class total_two : public figure {

public:

	total_two(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {if (n == 2)sum += n; });
		return sum;
	}
	//bool isFill() const;
};
 


class total_three : public figure {

public:

	total_three(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {if (n == 3)sum += n; });
		return sum;
	}
	//bool isFill() const;
};



class total_four : public figure {
public:
	total_four(std::vector<dice> ds) {
		dices = ds;
	}


	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {if (n == 4)sum += n; });
		return sum;
	}
	//bool isFill() const;
};



class total_five : public figure {


public:

	total_five(std::vector<dice> ds) {
		dices = ds;
	}

	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {if (n == 5)sum += n; });
		return sum;
	}
	//bool isFill() const;
};



class total_six : public figure {


public:


	total_six(std::vector<dice> ds) {
		dices = ds;
	}

	unsigned int calculate() {
		int sum = 0;
		std::for_each(dices.begin(), dices.end(), [&](int n) {if (n == 6)sum += n; });
		return sum;
	}
	//bool isFill() const;
};

