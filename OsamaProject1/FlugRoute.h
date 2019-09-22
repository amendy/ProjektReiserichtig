#pragma once
#ifndef FLUG_ROUTE
#define FLUG_ROUTE
#include "Edge.h" /* Denn Flugroute ist ein Edge und kommt in der Klassendeklaration nochmal vor*/

/* Klasse Flugroute von public Edge*/
class FlugRoute : public Edge {
	/* zwei Teile von der Klasse public( wo die Funktionen sind insbesondere getWeight und setter ) und private wo die Variablen sind*/
public : 
	virtual double getWeight() { return (80.0 + (0, 10 * m_distance));  }
	double getMinutes() { return (m_distance / 700) * 60; }
	double getPreis() { return getWeight(); }
    
	// Check mal in der Edge.h nach Node
	FlugRoute(Node& rSrc, Node& rDst, double m_distance) : Edge(rSrc, rDst) {
		this->m_distance = m_distance;
	};



private:
	double m_distance; 





};
	

#endif // !1

