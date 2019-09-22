#pragma once
#ifndef BUS_ROUTE
#include "Edge.h"


class BusRoute : public Edge {

public:
	virtual double getWeight() { return (0,18 * m_distance); }
	double getMinutes() { return (m_distance / 75) * 60;  }
	double getPreis() { return getWeight(); }

	BusRoute(Node& rSrc, Node& rDst, double m_distance) : Edge(rSrc, rDst) {
		this->m_distance = m_distance; /* Noch nicht deklariert deswegen mit this*/
	};


private:
	double m_distance;





};


#endif // !1

