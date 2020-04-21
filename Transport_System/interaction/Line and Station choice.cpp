#include "Line and Station choice.h"

int draw_line_and_station_choice (){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf(u8"路线站点编辑\n");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j <= 40; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(u8" 线路编辑 ");
			if (i == 1) printf(u8" 站点编辑 ");
			if (i == 2) printf(u8" 从文件中导入 ");
			if (i == 3) printf(u8" 从文件中导出 ");
			if (i == 4) printf(u8" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 3) y++;
		else if (input = 80)y = 0;
		if (input == 72 && y > 0)y--;
		else if (input == 72)y = 3;
		if (input == 13) break;
	}
	return y;
} 

void line_and_station_choice(){
	while (1) {
		int flag = draw_line_and_station_choice();
		if (flag == 0) {
			line_choice();
			// 线路编辑
		}
		else if (flag == 1) {
			station_choice();
			// 站点编辑
		}
		else if (flag == 2) {
			infile();
		}
		else if (flag == 3) {
			outfile();
		}
		else break;
	}
} 
