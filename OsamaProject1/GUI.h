#pragma once

#include "Graph.h"
#include "ReiseNetwork.h"
#include "Buchung.h"

class GUI : public Graph
{
public :
	// Hier die Funktionen 
	int showMenu();

	Node* readCity(); // wie haben wir *readCity bekommen? 

	void Reisebuchen();
	

	//GUI(ReiseNetwork& rNetwork) : m_rNetwork(rNetwork) { }
	
	void showBuchungList();
	//bool FlugBuchung();




private :
	std::list<Buchung> m_buchung;



};

class GUIException
{

public:

	GUIException(const std::string& msg) : m_msg(msg) {}

	std::string getError() const { return m_msg; }


private:

	std::string m_msg;

};