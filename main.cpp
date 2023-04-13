#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "World.h"

using namespace std;


int main() {
	srand((unsigned)time(NULL));
	World world(75,40);
	world.instanceCreate(Organisms::HUMAN, 15, 20);
	for (int i = 2; i < 8; i++) {
		for (int j = 4; j < 5; j++) {
			world.instanceCreate(Organisms::TURTLE, i, j);
		}
	}
	for (int i = 2; i < 10; i+=2) {
		for (int j = 2; j < 3; j++) {
			//world.instanceCreate(Organisms::FOX, i, j);
		}
	for (int i = 5; i < 6; i++) {
	}
		for (int j = 9; j < 10; j++) {
			//world.instanceCreate(Organisms::SOSNOWSKY, i, j);
		}
	}
	world.instanceCreate(Organisms::CYBER_SHEEP, 10, 9);
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
		system("CLS");
		world.makeTurn();
		world.drawWorld();
		c = 0;
	}
	return 0;
}
