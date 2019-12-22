#include "user_system.h"

int login (){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("登陆成功\n");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 40; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(" 公交查询 ");
			if (i == 1) printf(" 用户编辑 ");
			if (i == 2) printf(" 线路站点编辑 ");
			if (i == 3) printf(" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 3) y++;
		else if(input == 80) y = 0;
		if (input == 72 && y > 0) y--;
		else if (input == 72) y = 3;
		if (input == 13) break;
	}
	return y;
} 

void  user_system_login (){

	while (1) {
		int flag = login ();
		if (flag == 0) {
			//公交查询 
		}
		else if (flag == 1) {
			// 用户编辑 
		}
		else if (flag == 2) {
			// 线路站点编辑 
		}
		else break;
	}
} 
