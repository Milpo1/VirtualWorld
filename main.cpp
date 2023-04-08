#include <iostream>
#include <stdlib.h>
#include "World.h"

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	World world(7,4);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			world.instanceCreate(Organisms::HUMAN, i, j);
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