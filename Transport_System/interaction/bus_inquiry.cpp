#include"bus_inquiry.h"

int draw_bus_inquiry(){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf(u8"������ѯ\n");
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
			if (i == 0) printf(u8" վ���ѯ ");
			if (i == 1) printf(u8" ��·��ѯ ");
			if (i == 2) printf(u8" վվ��ѯ ");
			if (i == 3) printf(u8" ��̾����ѯ ");
			if (i == 4) printf(u8" ���ٻ��˲�ѯ ");
			if (i == 5) printf(u8" �˳� ");
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
			//վ���ѯ 
		}
		else if (flag == 1) {
			query_line();
			// ��·��ѯ  
		}
		else if (flag == 2) {
			query_station_station();
			// վվ��ѯ 
		}
		else if (flag == 3) {
			query_sort_path();
			// ��̾����ѯ 
		}
		else if (flag == 4) {
			query_less_path();
			// ���ٻ��˲�ѯ 
		}

		else break;
	}
} 
