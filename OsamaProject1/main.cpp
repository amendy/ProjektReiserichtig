#include <iostream>
#include "Edge.h"
#include "Node.h"
#include "GUI.h"
#include "BusRoute.h"
#include "FlugRoute.h"



using namespace std; 

int main()
{

	GUI gui;
	Node& berlin = gui.addNode(new Node("Berlin"));
	Node& Madrid = gui.addNode(new Node("Madrid"));
	Node& London = gui.addNode(new Node("London"));
	Node& NewYork = gui.addNode(new Node("NewYork"));



	gui.addEdge(new FlugRoute(berlin, Madrid, 1900));
	gui.addEdge(new BusRoute(berlin, Madrid, 2300));
	gui.addEdge(new FlugRoute(berlin, London, 930));
	gui.addEdge(new FlugRoute(London, NewYork, 5600));

	bool bRunning = true;

	// Endlosschleife, bis bRunning auf 'false' gesetzt wird
	while (bRunning)
	{
		int menuEntry = gui.showMenu();

		// Hinweis: Die Fallunterscheidung geht auch mit Switch-Case (siehe C-Programmierung)

		// Flug buchen



		switch (menuEntry)
		{
		case 1:
			gui.Reisebuchen();
			break;

		case 2: gui.showBuchungList();
			break;
		case 3:
			bRunning = false;
			break;

		default:
			break;
		}




	}


	return 0;
}