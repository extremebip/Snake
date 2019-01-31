#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

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

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time 
	clock_t start_time = clock();

	// looping till required time is not acheived 
	while (clock() < start_time + milli_seconds);
}

//function for randomly places apple inside the box
void apple() {
	time_t t;
	srand((unsigned)time(&t));
	int x = 0, y = 0;

	x = rand() % 18;
	y = rand() % 8;

	if (x == 0 || x == 10) x++;
	if (y == 0 || y == 5) y++;

	map[y][x] = '*';
}


//function to search the location of apple
int checkApple() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 20; x++) {
			if (map[y][x] == '*') {
				return 1;
			}
		}
	}


	return 0;
}

//function to show map on the screen
void showMap() {
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 20; k++) {
			printf("%c", map[j][k]);
		}
		printf("\n");
	}
}

int move(char key, int Y, int X) {

	switch (key) {
		//move up
	case 'U':
		if (map[Y - 1][X] == 196) {
			return 0;
		}
		else {
			map[Y][X] = ' ';
			map[Y - 1][X] = '#';
			return -1;
		}
		break;

		//move down
	case 'D':
		if (map[Y + 1][X] == 196) {
			return 0;
		}
		else {
			map[Y][X] = ' ';
			map[Y + 1][X] = '#';
			return 1;
		}
		break;

		//move right
	case 'R':
		if (map[Y][X + 1] == 179) {
			return 0;
		}
		else {
			map[Y][X] = ' ';
			map[Y][X + 1] = '#';
			return 1;
		}
		break;

		//move left
	case 'L':
		if (map[Y][X - 1] == 179) {
			return 0;
		}
		else {
			map[Y][X] = ' ';
			map[Y][X - 1] = '#';
			return -1;
		}
		break;
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
	char control = ' ';

	//initialising some conditions
	int countEat = 0;
	apple();

	while (1) {
		//generate apple if there is none
		if (checkApple() == 0) {
			countEat++;
			apple();
		}

		//printing map
		showMap();
		printf("%d\n", countEat);
		printf("%d %d\n", positionY, positionX);

		//input arrow keys
		do {
			keyInput = _getch();
			if (keyInput == 0xE0) keyInput = _getch();
		} while (keyInput != 72 && keyInput != 80 && keyInput != 75 && keyInput != 77);

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

		//changing the position and moving the snake
		if (control == 'U' || control == 'B') {
			positionY += move(control, positionY, positionX);
		}
		else {
			positionX += move(control, positionY, positionX);
		}

		system("cls");
	}

	getchar();

	return 0;
}