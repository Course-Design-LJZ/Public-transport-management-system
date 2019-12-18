#include"bus_inquiry.h"


int bus_inquiry(){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("公交查询系统\n");
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
			if (i == 0) printf(" 站点查询 ");
			if (i == 1) printf(" 线路查询 ");
			if (i == 2) printf(" 站站查询 ");
			if (i == 3) printf(" 最短距离查询 ");
			if (i == 4) printf(" 最少换乘查询 ");
			if (i == 5) printf(" 退出 ");
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
	

void login_bus_inquiry (){
	while (1) {
		int flag = bus_inquiry();
		if (flag == 0) {
			//站点查询 
		}
		else if (flag == 1) {
			// 线路查询  
		}
		else if (flag == 2) {
			// 站站查询 
		}
		else if (flag == 3) {
			// 最短距离查询 
		}
		else if (flag == 4) {
			// 最少换乘查询 
		}

		else break;
	}
} 
