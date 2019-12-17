#pragma once

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define _OK_ 1
#define _NO_ 0

#define VI vector

class line {

};

class Graph {
public:
	struct edge {
		int v, w, line;
		edge(int v, int w, int line) {
			this->v = v;
			this->w = w;
			this->line = line;
		}
	};

	VI <VI <edge>> G;
	VI <bool> vis;
	stack <int> Available;

	int Ins();

	void Ins_Edge(int u, int v, int w, int c);

	int Del(int u);

	int Del_Edge(int u, int v);

	int change(int u, int v, int w, int c);
};
