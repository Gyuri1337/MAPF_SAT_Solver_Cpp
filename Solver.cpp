#include "Solver.h"
#include <Windows.h>
#include "Map.h"
#include <iostream>

Solver::Solver(unsigned timevalue_sec)
{
	this->timeout = timeout;
}


bool Solver::solve(Map * map)
{
	int n = map->get_agents().size();
	if(n > 20)
	{
		return false;
	}
	return true;
}
