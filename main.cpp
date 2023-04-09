#include <iostream>
#include <stdlib.h>
#include "World.h"

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	World world(50,20);
	for (int i = 2; i < 10; i+=2) {
		for (int j = 2; j < 3; j++) {
			world.instanceCreate(Organisms::FOX, i, j);
		}
	}
	for (int i = 2; i < 8; i++) {
		for (int j = 4; j < 5; j++) {
			world.instanceCreate(Organisms::TURTLE, i, j);
		}
	}
	for (int i = 5; i < 10; i++) {
		for (int j = 9; j < 10; j++) {
			world.instanceCreate(Organisms::SOW_THISTLE, i, j);
		}
	}
	world.drawWorld();
	while (getchar()) {
		system("CLS");
		world.makeTurn();
		world.drawWorld();
	}
	return 0;
}