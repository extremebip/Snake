#include <time.h>
#include <stdlib.h>

#include "apple.h"

//function for randomly places apple inside the box
void apple(char arr[10][20]) {
	time_t t;
	srand((unsigned)time(&t));
	int x = 0, y = 0;

	x = rand() % 18;
	y = rand() % 8;

	if (x == 0 || x == 10) x++;
	if (y == 0 || y == 5) y++;

	arr[y][x] = '*';
}

//function to search the location of apple
int checkApple(char arr[10][20]) {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 20; x++) {
			if (arr[y][x] == '*') {
				return 1;
			}
		}
	}

	return 0;
}