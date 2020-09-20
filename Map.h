#pragma once

#include "Agent.h"
#include <vector>
struct Map
{
	Map(unsigned int vertices_count, std::vector<std::vector<unsigned int>> adj_list, std::vector<unsigned int> agents);

	void add_agent(unsigned int agent);
	std::vector<unsigned int> get_agents();
	unsigned int get_vertices_count();
	std::vector<std::vector<unsigned int>> get_adj_list();
	
private:
	unsigned int vertices_count;
	std::vector<std::vector<unsigned int>> adj_list;
	std::vector<unsigned int> agents;
	
};
