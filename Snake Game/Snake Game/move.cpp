#include "move.h"
#include <time.h>

//function to delay time
void delay(float number_of_seconds)
{
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time 
	clock_t start_time = clock();

	// looping till required time is not acheived 
	while (clock() < start_time + milli_seconds);
}

//move function
//returns value to change position of the snake head
int move(char arr[10][20], char key, int Y, int X) {
	int aras;
	delay(0.5);

	switch (key) {
		//move up
	case 'U':
		if (arr[Y - 1][X] == -60) {
			return 0;
		}
		else {
			arr[Y][X] = ' ';
			arr[Y - 1][X] = '#';
			return -1;
		}
		break;

		//move down
	case 'B':
		if (arr[Y + 1][X] == -60) {
			return 0;
		}
		else {
			arr[Y][X] = ' ';
			arr[Y + 1][X] = '#';
			return 1;
		}
		break;

		//move right
	case 'R':
		aras = arr[Y][X + 1] - 0;

		if (arr[Y][X + 1] == -77) {
			return 0;
		}
		else {
			arr[Y][X] = ' ';
			arr[Y][X + 1] = '#';
			return 1;
		}
		break;

		//move left
	case 'L':
		if (arr[Y][X - 1] == -77) {
			return 0;
		}
		else {
			arr[Y][X] = ' ';
			arr[Y][X - 1] = '#';
			return -1;
		}
		break;
	}
}