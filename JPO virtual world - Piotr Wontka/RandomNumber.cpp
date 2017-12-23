#include <stdlib.h>
#include <time.h>
#include "RandomNumber.h"

void RandomNumber::init() {
	srand(time(NULL));
}

int RandomNumber::getRandomNumber(int min, int max) {
	return rand() % max + min;
}