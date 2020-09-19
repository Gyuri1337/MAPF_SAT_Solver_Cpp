#pragma once

#include "Agent.h"
#include <vector>
struct Map
{
	Map(unsigned int vertices_count, std::vector<std::vector<unsigned int>> adj_list, std::vector<unsigned int> agents);

private:
	unsigned int vertices_count;
	std::vector<std::vector<unsigned int>> adj_list;
	std::vector<unsigned int> agents;
	
};
