#include "dice.h"
#include<iostream>
#include<random>
using namespace std;
dice::dice():m_value(0)
{
}

dice::dice(unsigned int value) 
{
    if (value > 6 || value < 1) {
        cout << "erreur valeur de dè sup ou inf de 1 ou 6." << endl;
        exit(0);
    }
    m_value = value;
}

dice& dice::operator=(const dice& d)
{
    m_value = d.m_value;
    return *this;
    // TODO: insérer une instruction return ici
}

dice::~dice()
{
}

void dice::printValue() const
{
    cout << m_value << " ";
}

dice::operator unsigned int()
{
    return m_value;
}

unsigned int dice::operator()() const
{
    return m_value;
}

//bool dice::operator==(const dice& d)
//{
//    return m_value == d.m_value;
//}

std::ostream& operator<<(std::ostream& out, const dice& d)
{
    out << d.m_value << endl;
    return out;
}
