#include"user.h"


int user (){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("�û���Ϣϵͳ\n");
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
			if (i == 0) printf(" �鿴�û���Ϣ ");
			if (i == 1) printf(" �û�ע�� ");
			if (i == 2) printf(" �����޸� ");
			if (i == 3) printf(" �˳� ");
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

int login_user (){
	while (1) {
		int flag = user();
		if (flag == 0) {
			//ע��  
		}
		else if (flag == 1) {
			// ���� 
		}
		else if (flag == 2) {
			// �鿴��Ϣ
		}
		else break;
	}
} 
