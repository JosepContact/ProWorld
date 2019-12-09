#include <stdio.h>
#include "Location.h"


void main()
{
	Location* loc = new Location();
	loc->SetName("city", "cities");
	Location* loc1 = new Location();
	loc->SetName("mountain", "mountains");
	Location* loc2 = new Location();
	loc->SetName("forest", "forests");
	Location* loc3 = new Location();
	loc->SetName("desert", "deserts");
	Location* loc4 = new Location();
	loc->SetName("ice", "ice");
	Location* loc5 = new Location();
	loc->SetName("jungle", "jungles");
	Location* loc6 = new Location();
	loc->SetName("ocean", "oceans");


	getchar();

	delete loc, loc1, loc2, loc3, loc4, loc5, loc6;
}