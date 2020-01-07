#include <stdio.h>
#include <iostream>
#include "Location.h"
#include "World.h"

using namespace std;

void main()
{
	World* world = new World();
	Location* loc = new Location();
	loc->SetName("city", "cities");

	if (loc!= nullptr) cout << loc->GetChar();

	getchar();

	delete loc, world;
}