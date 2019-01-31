#include "move.h"

int move(char arr[10][20], char key, int Y, int X) {
	int aras;

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