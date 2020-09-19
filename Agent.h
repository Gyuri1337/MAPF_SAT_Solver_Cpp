#pragma once

struct Agent
{
public:
	//--------------------------------
	//Constructors
	////--------------------------------
	Agent(unsigned short int fx, unsigned short int fy, unsigned short int tx, unsigned short int ty);

	//--------------------------------
	//Declaration
	//--------------------------------
	unsigned short int to_x;
	unsigned short int to_y;
	unsigned short int from_x;
	unsigned short int from_y;
};

struct AgentComparer
{
	bool operator()(const Agent& struct1, const Agent& struct2)
	{
		return struct1.from_y == struct2.from_y ? struct1.from_x < struct2.from_x : struct1.from_y < struct2.from_y;
	}

};
