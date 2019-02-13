#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "move.h";
#include "apple.h";

char map[10][20] = {
	218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,/*
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,
	179, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 179,*/
	192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217
};

//function to show map on the screen
void showMap() {
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 20; k++) {
			printf("%c", map[j][k]);
		}
		printf("\n");
	}
}

int main() {
	//initialising the first position of the snake
	int startPosX = 10, startPosY = 5;
	int positionX = startPosX;
	int positionY = startPosY;
	map[startPosY][startPosX] = '#';

	//initialising control variable
	int keyInput = 0;
	char control = 'L';

	//initialising some conditions
	int countEat = 0;
	apple(map);

	while (1) {

		while (!_kbhit()) {
			//changing the position and moving the snake
			if (control == 'U' || control == 'B')
				positionY += move(map, control, positionY, positionX);
			else
				positionX += move(map, control, positionY, positionX);
			system("cls");

			//generate apple if there is none
			if (checkApple(map) == 0) {
				countEat++;
				apple(map);
			}

			//printing map
			showMap();
			printf("%d\n", countEat);
			printf("%d %d\n", positionY, positionX);
		}

		//input arrow keys
		//do {
			keyInput = _getch();
			if (keyInput == 0xE0) keyInput = _getch();
		//} while ((keyInput != 72 && keyInput != 80 && keyInput != 75 && keyInput != 77));

		//check which arrow keys are chosen
		switch (keyInput) {
		case 72:
			control = 'U';
			break;
		case 80:
			control = 'B';
			break;
		case 75:
			control = 'L';
			break;
		case 77:
			control = 'R';
			break;
		}

		

	}

	getchar();

	return 0;
}