#include "algorithm.h"

void DIJ::init(int s, int t, int n)
{
	while (!Q.empty()) {
		Q.pop();
	}
	dis.resize(n + 1);
	pre.resize(n + 1);
	for (int i = 0; i < dis.size(); i++) {
		dis[i] = INF;
		pre[i] = i;
	}
	dis[s] = 0;
	Q.push(node(s, 0));
}

void DIJ::Dijkstra(Graph G)
{
	while (!Q.empty()) {
		node fr = Q.top();
		Q.pop();
		int u = fr.u, d = fr.d, v, w;
		if (d != dis[u]) continue;
		for (auto vv : G.G[u]) {
			if (dis[u] + (w = vv.w) < dis[v = vv.v]) {
				dis[v] = dis[u] + w;
				pre[v] = u;
				Q.push(node(v, dis[v]));
			}
		}
	}
}

void DIJ::getRoad(int s, int t, int n)
{
	road.clear();
	int now = t;
	while (now != s) {
		road.push_back(now);
		now = pre[now];
	}
	road.push_back(s);
	reverse(road.begin(), road.end());
}

void get_all_road::init(int n)
{
	res.clear();
	vis.resize(n + 1);
	fill(vis.begin(), vis.end(), 0);
}

void get_all_road::dfs(int u, int t,Graph G)
{
	if (res.size() >= 3) return;
	que.push_back(u);
	vis[u] = 1;
	if (u == t) {
		res.push_back(que);
		return;
	}
	for (auto v : G.G[u]) {
		if (vis[v.v]==1) continue;
		dfs(v.v, t, G);
	}
	que.pop_back();
	vis[u] = 0;
}

void less_change::init(int s, int t, int n)
{
	while (!q.empty()) {
		q.pop();
	}
	dis.resize(n + 1);
	pre.resize(n + 1);
	vis.resize(n + 1);
	for (int i = 0; i < dis.size(); i++) {
		dis[i] = INF;
		pre[i] = i;
		vis[i] = 0;
	}
	dis[s] = 0;
}

void less_change::bfs(int s, int t, Graph G)
{
	q.push(make_pair(s, -1));
	vis[s] = 1;
	while (!q.empty()){
		auto u = q.front(); q.pop();
		vis[u.first] = 1;
		for (auto v : G.G[u.first]) {
			if (vis[v.v] == 1) continue;
			if (v.c == u.second) {
				if (dis[v.v] >= dis[u.first]) {
					dis[v.v] = dis[u.first];
					pre[v.v] = u.first;
					q.push(make_pair(v.v, v.c));
				}
			}
			else {
				if (dis[v.v] >= dis[u.first] + 1) {
					dis[v.v] = dis[u.first] + 1;
					pre[v.v] = u.first;
					q.push(make_pair(v.v, v.c));
				}
			}
		}
	}
}

void less_change::getRoad(int s, int t, int n)
{
	road.clear();
	int now = t;
	while (now != s) {
		road.push_back(now);
		now = pre[now];
	}
	road.push_back(s);
	reverse(road.begin(), road.end());
}