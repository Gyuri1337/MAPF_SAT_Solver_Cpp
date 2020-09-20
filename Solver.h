#pragma once

#include "Map.h"

class Solver
{
public:
	Solver(unsigned int timevalue_sec);
	bool solve(Map * map);
	
private:
	unsigned int timeout;
};
