#include <iostream>
#include "World.h"

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	World world(10,10);
	world.instanceCreate(Organisms::HUMAN, 2, 2);
	//world.getInstanceAt(Point(2, 2))->action();
	return 0;
}