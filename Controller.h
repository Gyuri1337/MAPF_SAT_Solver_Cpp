#pragma once

#include "Map.h"
#include "Solver.h"

class Controller
{
public:
	~Controller();
	
	void main();
	int solve(Map * map, unsigned int timeout_sec);
	
	Solver * solver;
};
