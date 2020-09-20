#include "Controller.h"
#include "Solver.h"
#include "Windows.h"
#include "Writer.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Reader.h"
#include <thread>

Controller::~Controller()
{
	delete solver;
}


void Controller::main()
{
	std::cout << "Welcome, this is a MAPF Application with Sat solver.\n";
	std::cout << "Please copy your agent .scen file into code directory and enter the file name.\n";
	std::string line;
	std::getline(std::cin, line);
	Reader reader;
	if(!reader.open(line))
	{
		std::cout << "Invalid file";
		return;
	}
	auto agents = reader.readAgents();
	reader.sort_agents(agents);
	if(!reader.readMap(agents))
	{
		std::cout << "Failed to load map\n";
		return;
	}
	std::cout << "Map succesfully loaded.\n";
	std::cout << "Please enter a timeout in seconds :\n";
	std::getline(std::cin, line);
	auto * map = reader.getMap();
	auto  const agent_count = solve(map, std::stoi(line));
	Writer writer;
	writer.write(solver, map, agent_count);
	
}

int Controller::solve(Map * map, unsigned int timeout_sec)
{
	solver = new Solver(timeout_sec);
	Map* new_map = new Map(map->get_vertices_count(), map->get_adj_list(), std::vector<unsigned int>());
	std::vector<unsigned int> agents = map->get_agents();
	int i = 0;
	for (; i < agents.size(); i++)
	{
		new_map->add_agent(agents[i]);
		if(!solver->solve(new_map))
		{
			break;
		}
	}
	delete new_map;
	return i;
}

