#include"bus_inquiry.h"


int bus_inquiry(){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf("������ѯϵͳ\n");
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
			if (i == 0) printf(" վ���ѯ ");
			if (i == 1) printf(" ��·��ѯ ");
			if (i == 2) printf(" վվ��ѯ ");
			if (i == 3) printf(" ��̾����ѯ ");
			if (i == 4) printf(" ���ٻ��˲�ѯ ");
			if (i == 5) printf(" �˳� ");
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
			//վ���ѯ 
		}
		else if (flag == 1) {
			// ��·��ѯ  
		}
		else if (flag == 2) {
			// վվ��ѯ 
		}
		else if (flag == 3) {
			// ��̾����ѯ 
		}
		else if (flag == 4) {
			// ���ٻ��˲�ѯ 
		}

		else break;
	}
} 
