#include "Map.h"

Map::Map(unsigned vertices_count, std::vector<std::vector<unsigned>> adj_list, std::vector<unsigned> agents)
{
	this->vertices_count = vertices_count;
	this->adj_list = adj_list;
	this->agents = agents;
}
