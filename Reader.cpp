#include "Reader.h"
#include "Agent.h"

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

#define ASCII_point 46
#define ASCII_at_sign 64

//--------------------------------
//Definition
//--------------------------------
Reader::~Reader()
{
	delete my_map;
	if(my_stream.is_open())
	{
		my_stream.close();
	}
}

bool Reader::isOpened()
{
	if(!my_stream)
	{
		return false;
	}
	return my_stream.is_open();
}

bool Reader::open(std::string dir)
{
	my_stream.open(dir, std::ifstream::in);
	if(my_stream.is_open())
	{
		return true;
	}
	return false;
}

std::vector<Agent> Reader::readAgents()
{
	std::string actualLine;
	std::getline(my_stream, actualLine);
	std::vector<Agent> agent_list;
	unsigned short int fx;
	unsigned short int fy;
	unsigned short int tx;
	unsigned short int ty;
	unsigned int count = 0;
	while(!my_stream.eof())
	{
		std::getline(my_stream, actualLine);
		std::replace(actualLine.begin(), actualLine.end(), '\t', ' ');
		if(actualLine.empty())
		{
			continue;
		}
		std::istringstream iss(actualLine);
		std::string s;
		if (map_name.empty())
		{
			iss >> s;
			iss >> s;
			map_name = s;
			iss >> s;
			iss >> s;
			iss >> s;
		}
		else
		{
			for (int i = 0; iss >> s && i < 4; i++)
			{
			}
		}
		fx = std::stoi(s);
		iss >> s;
		fy = std::stoi(s);
		iss >> s;
		tx = std::stoi(s);
		iss >> s;
		ty = std::stoi(s);
		agent_list.push_back(Agent(fx, fy, tx, ty));
	}
	my_stream.close();
	return agent_list;
}

bool Reader::readMap(std::vector<Agent> agents, std::string dir)
{
	if(!dir.empty())
	{
		map_name = dir;
	}
	//Declaration
	unsigned short int x;
	unsigned short int y;
	std::ifstream map_stream(map_name);
	if(!map_stream.is_open())
	{
		return false;
	}
	std::string actual_line;
	std::istringstream iss;
	std::string s;
	//Declaration - END
	
	std::getline(map_stream, actual_line);
	std::getline(map_stream, actual_line);
	iss = std::istringstream(actual_line); ;
	iss >> s >> s;
	y = std::stoi(s);
	std::getline(map_stream, actual_line);
	iss = std::istringstream(actual_line);
	iss >> s >> s;
	x = std::stoi(s);
	std::getline(map_stream, actual_line);

	std::string prev_line;
	std::string next_line;
	unsigned int vertices_count = 0;
	std::vector<std::vector<unsigned int>> adj_list;
	unsigned int prev_vertex= 0;
	unsigned int actual_agent = 0;
	std::vector<unsigned int> agent_vertices;
	for (int i = 0; i < x; i++)
		prev_line += ASCII_at_sign;
	for (int i = 0; i < y; i++)
	{
		std::getline(map_stream, actual_line);
		unsigned int actualline_count = 0;
		for (int j = 0; j < x; j++)
		{
			if(actual_line[j] == ASCII_point)
			{
				actualline_count++;
				adj_list.push_back(std::vector<unsigned int>());
				if(j > 0 && actual_line[j - 1] == ASCII_point)
				{
					adj_list[vertices_count].push_back(vertices_count - 1);
				}
				if (j < x && actual_line[j + 1] == ASCII_point)
				{
					adj_list[vertices_count].push_back(vertices_count + 1);
				}
				if(prev_line[j] == ASCII_point)
				{
					adj_list[prev_vertex].push_back(vertices_count);
					adj_list[vertices_count].push_back(prev_vertex);
				}
				if(actual_agent < agents.size() && agents[actual_agent].from_x == j && agents[actual_agent].from_y == i)
				{
					agent_vertices.push_back(vertices_count);
					
					actual_agent++;
				}
				vertices_count++;
			}
			if (prev_line[j] == ASCII_point)
			{
				prev_vertex++;
			}
		}
		prev_line = actual_line;
	}
	my_map = new Map(vertices_count, adj_list, agent_vertices);
	map_stream.close();
	return true;
}

Map* Reader::getMap()
{
	return my_map;
}

void Reader::sort_agents(std::vector<Agent>&agents)
{
	std::sort(agents.begin(), agents.end(), AgentComparer());
}


//--------------------------------
//Definition - END
//--------------------------------
