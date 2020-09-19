#include "Controller.h"
#include "Solver.h"
#include "Windows.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Reader.h"
#include "Agent.h"
#include <thread>

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
		std::cout << "Failed to load map";
		return;
	}
	auto * map = reader.getMap();
	
	
}

int Controller::solve(Map * map)
{
	Solver solver;
	bool returnvalue = false;
	//std::thread solve_thread(&Solver::solve, &solver, map, returnvalue);
	std::thread solve_thread1([&](Solver* solver1) {solver1->solve(map, returnvalue); });
	Sleep(1000);
	if (returnvalue == false)
	{
		std::terminate();
	}
}

