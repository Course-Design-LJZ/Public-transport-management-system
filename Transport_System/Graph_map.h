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
	void init(string name, int id); 
};

class line {
public:
	string name;
	int id;
	void init(string name, int id);
	vector <station> list;
	map <string, int> set;
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

	int Ins_station(string name);
	int Del_station(int id);
	int change_station(int id, string rename);

	int Ins_line(string name,station star);
	void Ins_line_station(int lid,int sid,int w);
	void Del_line(int id);
};