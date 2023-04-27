#include "World.h"

using namespace std;

void spray(World* world, Organisms type, int x, int y, int radius, int glitter = 1) {
	x += intRandRange(-1, 1);
	y += intRandRange(-1, 1);
	for (int i = x - radius; i <= x + radius; i+=glitter) {
		for (int j = y - radius; j <= y + radius; j+=glitter) {
			world->instanceCreate(type, i, j);
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	World world(50,20);
	world.instanceCreate(Organisms::HUMAN, 10, 9);
	
	spray(&world, Organisms::ANTELOPE, 4, 4, 1);
	spray(&world, Organisms::WOLF, 12, 12, 1);
	spray(&world, Organisms::SHEEP, 22, 22, 1);
	spray(&world, Organisms::GRASS, 12, 20, 2);
	spray(&world, Organisms::SOSNOWSKY, 30, 15, 2);
	spray(&world, Organisms::FOX, 8, 8, 1);
	spray(&world, Organisms::TURTLE, 10, 12, 1);
	spray(&world, Organisms::CYBER_SHEEP, 18, 18, 1);
	spray(&world, Organisms::SOW_THISTLE, 35, 8, 0);
	spray(&world, Organisms::GUARANA, 30, 19, 1);
	spray(&world, Organisms::BELLADONNA, 25, 9, 0);

	world.drawWorld();

	int c = _getch();
	while (true) {
		while (c != 224 && c != 32) {
			if (c == 's') world.saveGame();
			else if(c == 'l') world.loadGame();
			world.setInput(c);
			c = _getch();
		}
		if (c != 32) c = _getch();
		world.setInput(c);
		//system("CLS");
		world.makeTurn();
		world.drawWorld();
		c = 0;
	}
	return 0;
}