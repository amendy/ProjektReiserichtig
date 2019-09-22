#pragma once
#ifndef BUCHUNG_H
#define BUCHUNG_H
#include <string>
#include "Node.h"

struct Buchung 
{
	Node* m_rSrc;
	Node* m_rDst;
	std::string m_firstname, m_lastname;
	std::string m_address1, m_address2;

	double m_preis;

}; 
/*Buchung{
	Node* m_rSrc;
	Node* rDst; 
	std::string m_firstname, m_lastname;
	std::string m_address1, m_address2;
	
		double m_Preis; 

};*/
#endif // !BUCHUNG_H
