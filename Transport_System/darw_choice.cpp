#include "darw_choice.h"

int draw_station(string title, Graph_map G)
{
	int y;
	while (1)
	{
		system("cls");
		cout << title << endl;
		for (int i = 1,j = 1; i < G.station_list.size(); i++) {
			if (G.vis_station[i] == 0) continue;
			if (j % 8 == 0)cout << endl;
			cout << i << ": " << G.station_list[i].name << " ";
			j++;
		}
		cout << endl;
		cout << u8"请输入要选择的站点编号:(输入0退出)\n";
		cin >> y;
		if (y == 0) return 0;
		if (0 < y && y < G.station_list.size() && G.vis_station[y] == 1) {
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
		for (int i = 1,j = 1; i < G.line_list.size(); i++) {
			if (G.vis_line[i] == 0) continue;
			if (j % 8 == 0)cout << endl;
			cout << i << ": " << G.line_list[i].name << " ";
			j++;
		}
		cout << endl;
		cout << u8"请输入要选择的路线编号:(输入0退出)\n";
		cin >> y;
		if (y == 0) return 0;
		if (0 < y && y < G.line_list.size() && G.vis_line[y] == 1) {
			return y;
		}
		else {
			cout << u8"输入非法" << endl;
			system("pause");
		}
	}
}

int draw_sex()
{
	int y = 0;
	while (1) {
		system("cls");
		printf(u8"请选择性别:\n");
		for (int i = 0; i < 3; i++) {
			if (i == y) {
				printf(">");
			}
			else printf(" ");
			if (i == 0) printf(u8" 男 ");
			if (i == 1) printf(u8" 女 ");
			if (i == 2) printf(u8" 保密 ");
			printf("\n");
		}
		char input;
		input = _getch();
		if (input == 80 && y < 2) y++;
		else if (input == 80) y = 0;
		if (input == 72 && y > 0) y--;
		else if (input == 72) y = 2;
		if (input == 13) break;
	}
	if (y == 0) return _male;
	if (y == 1) return _female;
	if (y == 2) return _none;
}

