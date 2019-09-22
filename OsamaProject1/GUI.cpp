#include "GUI.h"
#include <iostream>
#include <deque>
#include "FlugRoute.h"
#include "BusRoute.h"
#include "Buchung.h"

using namespace std; 

int GUI::showMenu()
{
	std::cout << "Bitte wählen Sie eine Zahl für die jeweilige Aktion:" << std::endl
		<< "1 - Neue Buchung" << std::endl
		<< "2 - Ausgabe aller Buchungen" << std::endl
		<< "3 - Beenden" << std::endl;

	std::cout << "Eingabe: ";
	int eingabe;
	std::cin >> eingabe;
	return eingabe;
}

Node* GUI::readCity() // Node einlesen
{
	std::string City;
	Node* pNode = NULL;

	do
	{
		std::cout << "Bitte Zielstadt angeben?" << std::endl;
		std::cin >> City;
		pNode = this->findNode(City);
		if (pNode == NULL)
		{
			std::cout << "Stadt nicht verfuegbar. Eingabe wiederholen. Abbrechen mit 'q'" << std::endl;

		}
	} while (pNode == NULL);
	return pNode;
	/*
	Node* pNode = NULL; // wenn Node eine Null ist
std::string City;   // gibt eine Stadt aus.

while (pNode == NULL) { // wenn ein Node Null muss eine Eingabe kommen
	std::cin >> City;

	// werfe Exception, wenn der Nutzer keine Stadt, sondern 'q' eingibt:
	//if (city == "q")
		//throw TravelGuiException("Es wurde keine Start- oder Zielstadt eingegeben.");

	pNode = findNode(City);

	if (pNode == NULL) // Wenn Node null ist
		std::cout << "Stadt nicht verfügbar. Eingabe wiederholen. Abbrechen mit 'q'." << std::endl;
}

return pNode;*/
}

void GUI::Reisebuchen() {
	double preis = 0.0;
	double Minutes = 0.0;
	// Funktionen der GUI 
	// Zuerst Eingabe fördern laut Aufgabe
	std::cout << " Bitte geben Sie Ihre Startcity ein" << std::endl;
	Node* rSrc = readCity();
	std::cout << " Bitte geben Sie Ihre Zielcity ein" << std::endl;
	Node* rDst = readCity(); 
	
	/* Dann kommst deque von Edge, die den ganzen Weg mit Dijkstra optimiert*/

	std::deque<Edge*>path;
	findShortestPathDijkstra(path, *rSrc, *rDst);
	// For Schleife in einer Liste Edge 
	for (std::deque<Edge*>::iterator it = path.begin(); it!= path.end(); it++)
	{
		if (FlugRoute* pFlight = dynamic_cast<FlugRoute*>(*it))
		{
			preis += pFlight->getPreis();
			std::cout << "Flug: " << pFlight->toString() << "; Dauer: " << pFlight->getMinutes() << "min" << std::endl;
		}
		// ist es eine Busverbindung?
		else if (BusRoute* pBus = dynamic_cast<BusRoute*>(*it))
		{
			preis += pBus->getPreis();
			std::cout << "Bus: " << pBus->toString() << "; Dauer: " << pBus->getMinutes() << "min" << std::endl;
		}
	}
	cout << "preis is " << preis << endl;


	std::string bBuchung;
	std::cout << "Moechten Sie diese Route buchen? [j/n]: ";
	std::cin >> bBuchung;
	// Überspringe das alles, falls die Route nicht gebucht werden soll!
	if (bBuchung == "j")
	{
		std::string firstname, lastname;
		std::cout << "Bitte Vornamen eingeben: ";
		std::cin >> firstname;
		std::cout << "Bitte Nachnamen eingeben: ";
		std::cin >> lastname;

		std::string address1, address2;
		std::cout << "Bitte Strasse und Hausnummer eingeben: ";
		std::cin >> address1;
		std::cout << "Bitte PLZ und Ort eingeben: ";
		std::cin >> address2;

		while (firstname.empty() || lastname.empty() || address1.empty() || address2.empty()) {
			std::cout << "Bitte Vornamen eingeben: ";
			std::cin >> firstname;
			std::cout << "Bitte Nachnamen eingeben: ";
			std::cin >> lastname;
			std::cout << "Bitte Strasse und Hausnummer eingeben: ";
			std::cin >> address1;
			std::cout << "Bitte PLZ und Ort eingeben: ";
			std::cin >> address2;

			//	throw GUIException("Die Personenangaben sind unvollständig.");
		}

		Buchung b;

		b.m_rSrc = rSrc;
		b.m_rDst = rDst;
		b.m_firstname = firstname;
		b.m_lastname = lastname;
		b.m_address1 = address1;
		b.m_address2 = address2;
		b.m_preis = preis;

		/* In die Liste der Buchungen speichern*/
		m_buchung.push_back(b);


	}
}


	void GUI::showBuchungList()
	{
		std::cout << "\n--------------------------------------------------------------" << std::endl;
		 // for Schleife in einer Liste von Beginn bis zum Ende. 
		for (std::list<Buchung>::iterator it = m_buchung.begin(); it != m_buchung.end(); it++)
		{
			/*
			 * Hinweis zur Nutzung des Iterators:
			 * ----------------------------------
			 * std::list<Booking> enthält direkt Booking-Objekte, KEINE Pointer! ---> UNTERSCHIED ZUR NODE-LISTE!
			 * Der dereferenzierte Iterator (*it) ist also kein Pointer, sondern ein Booking-Objekt.
			 * (*it).m_pStart ist das Selbe wie it->m_pStart. (Pfeiloperator geht bei Iteratoren genauso wie bei Pointern)
			 * ---> Darum kann hier der Pfeiloperator genutzt werden, um direkt auf die Elemente des Booking-Objektes zuzugreifen.
			 *
			 * Unterschied zur Node-Liste:
			 * Bei einer std::list<Node*> musste der Iterator zuerst dereferenziert werden. (*itNode)
			 * Der Pfeiloperator hat sich dann auf den gespeicherten Pointer bezogen, z.B: (*itNode) -> getId();
			*/

			if (it->m_rSrc != NULL && it->m_rDst != NULL)
			{
				// Wenn die Liste nicht Null ist, dann zeige die Eingabe aus. 
				std::cout << "Verbindung: " << it->m_rSrc->getID() << " -> " << it->m_rDst->getID() << std::endl;
				std::cout << "Name:       " << it->m_firstname << " " << it->m_lastname << std::endl;
				std::cout << "Addresse 1: " << it->m_address1 << std::endl;
				std::cout << "Addresse 2: " << it->m_address1 << std::endl;
				std::cout << "preis: " << it->m_preis;

				std::cout << "\n--------------------------------------------------------------" << std::endl;
			}
		}
	}


	//---------------------------------------------------------------------------------------------------------------------
