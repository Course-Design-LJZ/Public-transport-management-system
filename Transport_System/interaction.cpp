#include "interaction.h"

void init()
{
	now = File_input_User_set_AES();
	G = File_input_Graph_map_AES();
}

void outit() {
	File_output_User_set_AES(now);
	File_output_Graph_map_AES(G);
}

void infile() {
	G = File_input_Graph_map();
}

void outfile() {
	File_output_Graph_map(G);
}

void query_station()
{
	int flag = draw_station(u8"请选择要查询的站点", G);
	if (flag == 0) return;
	system("cls");
	if (flag < G.station_list.size()) {
		station s = G.station_list[flag];
		cout << u8"经过" << s.name << u8"的路线有:" << endl;
		for (auto v : s.pass_line) {
			cout << G.line_list[v].name << endl;
		}
	}
	system("pause");
}

void query_line() {
	int flag = draw_line(u8"请选择要查询的路线", G);
	if (flag == 0) return;
	system("cls");
	if (flag < G.line_list.size()) {
		line L = G.line_list[flag];
		cout << L.name << u8"经过的站点有:" << endl;
		for (auto v : L.list) {
			cout << v.name << endl;
		}
	}
	system("pause");
}

void query_station_station()
{
	int flag1 = draw_station(u8"请选择起点", G);
	if (flag1 == 0) return;
	int flag2 = draw_station(u8"请选择终点", G);
	if (flag2 == 0) return;
	get_all_road solve;
	system("cls");
	cout << u8"所有的合法路线为:" << endl;
	solve.init(G.station_list.size());
	solve.dfs(G.station_list[flag1].id, G.station_list[flag2].id, G.G);
	for (auto v : solve.res) {
		while (!v.empty())
		{
			cout << G.station_list[G.i_station[v.front()]].name <<"->";
			v.pop_front();
			if (v.size() == 1)break;
		}
		cout << G.station_list[G.i_station[v.front()]].name << endl;
		v.pop_front();
	}
	system("pause");
}

void query_sort_path()
{
	int flag1 = draw_station(u8"请选择起点", G);
	if (flag1 == 0) return;
	int flag2 = draw_station(u8"请选择终点", G);
	if (flag2 == 0) return;
	DIJ solve;
	system("cls");
	
	int s = G.station_list[flag1].id, t = G.station_list[flag2].id;
	solve.init(s, t, G.station_list.size());
	solve.Dijkstra(G.G);
	solve.getRoad(s, t, G.station_list.size());
	cout << u8"最短路长度为:" << solve.dis[t] << endl;
	cout << u8"路线为:" << endl;
	for (int i = 0; i < solve.road.size();i++) {
		cout << G.station_list[G.i_station[solve.road[i]]].name << 
			((i == (solve.road.size() - 1)) ? "\n" : "->");
	}
	system("pause");
}

void query_less_path()
{
	int flag1 = draw_station(u8"请选择起点", G);
	if (flag1 == 0) return;
	int flag2 = draw_station(u8"请选择终点", G);
	if (flag2 == 0) return;
	less_change solve;
	system("cls");

	int s = G.station_list[flag1].id, t = G.station_list[flag2].id;
	solve.init(s, t, G.station_list.size());
	solve.bfs(s, t, G.G);
	solve.getRoad(s, t, G.station_list.size());
	if (solve.dis[t] - 1 == 0) cout << u8"无需换乘" << endl;
	else cout << u8"最少换乘次数为为:" << solve.dis[t]-1 << endl;
	cout << u8"路线为:" << endl;
	for (int i = 0; i < solve.road.size(); i++) {
		cout << G.station_list[G.i_station[solve.road[i]]].name <<
			((i == (solve.road.size() - 1)) ? "\n" : "->");
	}
	system("pause");
}


