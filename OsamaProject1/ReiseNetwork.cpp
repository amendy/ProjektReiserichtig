#include "ReiseNetwork.h"
#include "FlugRoute.h"
#include "BusRoute.h"


void ReiseNetwork::addFlugRoute(Node& rCity1, Node& rCity2, double dist)
{
	addEdge(new FlugRoute(rCity1, rCity2, dist));
	addEdge(new FlugRoute(rCity2, rCity1, dist));
}


void ReiseNetwork::addBusRoute(Node& rCity1, Node& rCity2, double dist)
{
	addEdge(new BusRoute(rCity1, rCity2, dist));
	addEdge(new BusRoute(rCity2, rCity1, dist));
}


Node* ReiseNetwork::getNodeById(const std::string& rNodeId)
{
	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++) {
		if ((*it)->getID() == rNodeId)
			return *it;
	}
	return NULL;
}
