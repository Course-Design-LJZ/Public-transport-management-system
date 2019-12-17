#pragma once

#include <vector>
#include <string>

using namespace std;

class station {
public:
	string name;
	vector <int> pass_line;
	int id;
	station(string name, int id) {
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

class Grap_map {
public:

};