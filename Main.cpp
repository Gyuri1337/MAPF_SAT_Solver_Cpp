// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reader.h"
#include "Agent.h"
#include <algorithm>
int main()
{
    std::cout << "Hello World!\n";
	Reader myReader;
	myReader.open("brc202d-even-11.scen");
	if(myReader.isOpened())
	{
		std::cout << "good";
		std::vector<Agent> agents;
		agents = myReader.readAgents();
		myReader.sort_agents(agents);
		myReader.readMap(agents);
		Map* myMap = myReader.getMap();
		
	}
}
