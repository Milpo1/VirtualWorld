#include <iostream>
#include <stdlib.h>
#include "World.h"

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	World world(50,35);
	Organism* instance = world.instanceCreate(Organisms::HUMAN, 0, 0);
	Organism* instance2 = world.instanceCreate(Organisms::HUMAN, 49, 34);
	world.drawWorld();
	while (getchar()) {
		system("CLS");
		world.makeTurn();
		world.drawWorld();
	}
	return 0;
}