#include "Map.h"

Map::Map(unsigned vertices_count, std::vector<std::vector<unsigned>> adj_list, std::vector<unsigned> agents)
{
	this->vertices_count = vertices_count;
	this->adj_list = adj_list;
	this->agents = agents;
}

void Map::add_agent(unsigned agent)
{
	this->agents.push_back(agent);
}


std::vector<unsigned> Map::get_agents()
{
	return agents;
}

std::vector<std::vector<unsigned>> Map::get_adj_list()
{
	return adj_list;
}

unsigned Map::get_vertices_count()
{
	return vertices_count;
}

