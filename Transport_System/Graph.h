#pragma once

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include "flag.h"

using namespace std;

class Graph {
public:
	struct edge {
		int v, w, c;
		edge(int v, int w, int c) {
			this->v = v;
			this->w = w;
			this->c = c;
		}
	};

	vector <vector <edge>> G;
	vector <bool> vis;
	stack <int> Available;

	int Ins();

	void Ins_Edge(int u, int v, int w, int c);

	int Del(int u);

	int Del_Edge(int u, int v);

	int change(int u, int v, int w, int c);
};