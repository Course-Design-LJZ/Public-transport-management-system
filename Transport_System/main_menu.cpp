#include "main_menu.h"

int darw_main_menu()
{
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("���й�����ѯϵͳ\n");
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
			if (i == 0) printf(" ������ѯ ");
			if (i == 1) printf(" �û���¼ ");
			if (i == 2) printf(" �˳� ");
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

void main_menu()
{
	while (1) {
		int flag = darw_main_menu();
		if (flag == 0) {
			//
		}
		else if (flag == 1) {
			// 
		}
		else break;
	}
}

int main() {
	main_menu();
}