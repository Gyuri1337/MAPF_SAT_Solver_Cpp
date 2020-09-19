#include "Solver.h"
#include <Windows.h>
#include "Map.h"

void Solver::solve(Map* map, bool &value)
{
	int n = map->get_agents().size();
	for (int i = 0; i < n; i++)
	{
		Sleep(1000);
	}
	value = true;
}
