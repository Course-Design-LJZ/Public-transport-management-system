#pragma once

#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
#include "flag.h"
#include "Graph.h"

using namespace std;

class DIJ {
public:
	struct node {
		int u, d;
		bool operator <(const node& rhs) const {
			return d > rhs.d;
		}
		node(int u, int d) {
			this->u = u;
			this->d = d;
		}
	};

	priority_queue <node> Q;
	vector <int> dis, pre;
	vector <int> road;

	void init(int s, int t, int n);

	void Dijkstra(Graph G);

	void getRoad(int s, int t, int n);
};

class get_all_road {
public:
	vector <deque<int>> res;
	deque <int> que;
	vector <bool> vis;

	void init(int n);

	void dfs(int u, int t,Graph G);
};

class less_change {
public:
	vector <int> dis, pre, vis;
	vector <int> road;
	queue <pair<int,int>> q;

	void init(int s, int t, int n);

	void bfs(int s, int t,Graph G);

	void getRoad(int s, int t, int n);
};