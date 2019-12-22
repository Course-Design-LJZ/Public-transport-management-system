#include"login.h"


int user_system (){
	int x = 40, y = 0;
	while (1) {
		system("cls");
		for (int i = 1; i <= 37; i++) printf(" ");
		for (int i = 1; i <= 4; i++) printf(" ");
		printf(u8"ÓÃ»§µÇÂ¼ÏµÍ³\n");
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
			if (i == 0) printf(u8" µÇÂ¼ ");
			if (i == 1) printf(u8" ×¢²á ");
			if (i == 2) printf(u8" ÍË³ö ");
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

void main_menu_user_system (){
	while (1) {
		int flag = user_system ();
		if (flag == 0) {
			// µÇÂ¼
		}
		else if (flag == 1) {
			// ×¢²á 
		}
		else break;
	}
} 
