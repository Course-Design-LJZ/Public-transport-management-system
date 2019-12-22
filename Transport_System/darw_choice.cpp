#include "darw_choice.h"

int draw_station(string title, Graph_map G)
{
	int y;
	while (1)
	{
		system("cls");
		cout << title << endl;
		for (int i = 1; i < G.station_list.size(); i++) {
			if (i % 8 == 0)cout << endl;
			cout << i << ": " << G.station_list[i].name << " ";
		}
		cout << endl;
		cout << u8"请输入要选择的站点编号:(输入0退出)\n" ;
		cin >> y;
		if (y == 0) return 0;
		if (0 < y && y < G.station_list.size()) {
			return y;
		}
		else {
			cout << u8"输入非法" << endl;
			system("pause");
		}
	}
}

int draw_line(string title, Graph_map G)
{
	int y;
	while (1)
	{
		system("cls");
		cout << title << endl;
		for (int i = 1; i < G.line_list.size(); i++) {
			if (i % 8 == 0)cout << endl;
			cout << i << ": " << G.line_list[i].name << " ";
		}
		cout << endl;
		cout << u8"请输入要选择的路线编号:(输入0退出)\n";
		cin >> y;
		if (0 < y && y < G.line_list.size()) {
			return y;
		}
		else {
			cout << u8"输入非法" << endl;
			system("pause");
		}
	}
}

