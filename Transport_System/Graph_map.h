#pragma once

#include <vector>
#include <stack>
#include <map>
#include <string>
#include "Graph.h"

using namespace std;

class station {
public:
	string name;
	vector <int> pass_line;
	int id;
	void init(string name, int id) {
		this->name = name;
		this->id = id;
		this->pass_line.clear();
	}
};

class line {
public:
	int s, t;
	int length;
	int id;
	vector <station> line;
};

class Graph_map {
public:
	Graph G;
	vector <station> station_list;
	vector <bool> vis_station;
	stack <int> station_Available;
	map<string, int> s_station;
	map<int, int> i_station;

	vector <line> line_list;
	vector <bool> vis_line;
	stack <int> line_Available;
	map<string, int> s_line;
	map<int, int> i_line;

	int Ins_station(string name);
	int Del_station(int id);
	int change_station(int id, string rename);

	int Ins_line();
	int Ins_line_station();
	int Del_line_station();
	int Del_line();
	int change_line();
};