#include <iostream>
#include "World.h"

using namespace std;

int main() {
	World world(10,10);
	world.instanceCreate(HUMAN, 0, 0);

	return 0;
}