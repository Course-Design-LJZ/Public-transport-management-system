#include "user_edit.h"

int draw_user_edit_user() {
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		cout << u8"�û���Ϣ����"<< endl;
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
			if (i == 0) printf(u8" �û���Ϣ�޸� ");
			if (i == 1) printf(u8" �û������޸� ");
			if (i == 2) printf(u8" ע�� ");
			if (i == 3) printf(u8" �˳� ");
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

int draw_user_edit_admin() {
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		cout << u8"�û���Ϣ����" << endl;
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
			if (i == 0) printf(u8" �û���Ϣ�޸� ");
			if (i == 1) printf(u8" �û������޸� ");
			if (i == 2) printf(u8" �û�Ȩ�޹��� ");
			if (i == 3) printf(u8" ע�� ");
			if (i == 4) printf(u8" �˳� ");
			for (int k = 1; k < 5; k++) printf(" ");
			printf("\n");
		}
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 20; i++) printf("*");
		printf("\n");
		char input;
		input = _getch();
		if (input == 80 && y < 4) y++;
		else if (input == 80) y = 0;
		if (input == 72 && y > 0) y--;
		else if (input == 72) y = 4;
		if (input == 13) break;
	}
	return y;
}


void  user_edit() {
	while (1) {
		int flag;
		if (now_user.query_admin() == _USER) {
			flag = draw_user_edit_user();
			if (flag == 0) {
				change_info();
			}
			else if (flag == 1) {
				change_password();
			}
			else if (flag == 2) {
				del_user();
				if (now_user.username == "") break;
			}
			else break;
		}
		else if (now_user.query_admin() == _ADMIN || now_user.query_admin() == _0ADMIN) {
			flag = draw_user_edit_admin();
			if (flag == 0) {
				change_info();
			}
			else if (flag == 1) {
				change_password();
			}
			else if (flag == 2) {
				change_admin();
			}
			else if (flag == 3) {
				del_user();
				if(now_user.username=="") break;
			}
			else break;
		}
		else break;
	}
}