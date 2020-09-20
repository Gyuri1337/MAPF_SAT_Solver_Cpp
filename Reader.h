#pragma once

#include "Agent.h"
#include "Map.h"

#include <xstring>
#include <fstream>
#include <vector>
class Reader
{
public:
	~Reader();
	//--------------------------------
	//Declaration - Functions
	//--------------------------------
	bool isOpened();
	bool open(std::string);
	std::vector<Agent> readAgents();
	bool readMap(std::vector<Agent> agents, std::string dir = "" );
	Map* getMap();
	void sort_agents(std::vector<Agent>&agents);
	
private:
	//--------------------------------
	//Declaration - Variables
	//--------------------------------
	std::string map_name;
	Map* my_map;
	std::ifstream my_stream;
	
};
