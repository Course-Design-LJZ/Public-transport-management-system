#include "user_system.h"

int draw_user_system_user (){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		cout << u8"欢迎 " << now_user.query_name() << endl;
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= 40; j++) {
				if (j == x && i == y) {
					printf(">");
				}
				else printf(" ");
			}
			if (i == 0) printf(u8" 公交查询 ");
			if (i == 1) printf(u8" 用户编辑 ");
			if (i == 2) printf(u8" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 2) y++;
		else if(input == 80) y = 0;
		if (input == 72 && y > 0) y--;
		else if (input == 72) y = 2;
		if (input == 13) break;
	}
	return y;
} 

int draw_user_system_admin() {
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		cout << u8"欢迎 " << now_user.query_name() << endl;
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
			if (i == 0) printf(u8" 公交查询 ");
			if (i == 1) printf(u8" 用户编辑 ");
			if (i == 2) printf(u8" 线路站点编辑 ");
			if (i == 3) printf(u8" 退出 ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 3) y++;
		else if (input == 80) y = 0;
		if (input == 72 && y > 0) y--;
		else if (input == 72) y = 3;
		if (input == 13) break;
	}
	return y;
}


void  user_system(){
	while (1) {
		int flag;
		if (now_user.query_admin() == _USER) {
			flag = draw_user_system_user();
			if (flag == 0) {
				bus_inquiry();
				//公交查询 
			}
			else if (flag == 1) {

				// 用户编辑 
			}
			else break;
		}
		else if (now_user.query_admin() == _ADMIN || now_user.query_admin() == _0ADMIN) {
			flag = draw_user_system_admin();
			if (flag == 0) {
				bus_inquiry();
				//公交查询 
			}
			else if (flag == 1) {

				// 用户编辑 
			}
			else if (flag == 2) {
				line_and_station_choice();
				// 线路站点编辑 
			}
			else break;
		}
		else break;
	}
} 
