#include"bus_inquiry.h"

int draw_bus_inquiry(){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf(u8"公交查询\n");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j <= 40; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(u8" 站点查询 ");
			if (i == 1) printf(u8" 线路查询 ");
			if (i == 2) printf(u8" 站站查询 ");
			if (i == 3) printf(u8" 最短距离查询 ");
			if (i == 4) printf(u8" 最少换乘查询 ");
			if (i == 5) printf(u8" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 5) y++;
		else if(input == 80) y = 0;
		if (input == 72 && y > 0) y--;
		else if (input == 72) y = 5;
		if (input == 13) break;
	}
	return y;
}    
	

void bus_inquiry (){
	while (1) {
		int flag = draw_bus_inquiry();
		if (flag == 0) {
			query_station();
			//站点查询 
		}
		else if (flag == 1) {
			query_line();
			// 线路查询  
		}
		else if (flag == 2) {
			query_station_station();
			// 站站查询 
		}
		else if (flag == 3) {
			query_sort_path();
			// 最短距离查询 
		}
		else if (flag == 4) {
			query_less_path();
			// 最少换乘查询 
		}

		else break;
	}
} 
