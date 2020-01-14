#include "ModuleWorld.h"
#include "App.h"
#include "Location.h"
#include "Adjective.h"

#include <cstdlib>
#include <ctime>

using namespace std;

ModuleWorld::ModuleWorld(bool start_enabled) : Module(start_enabled)
{
}

ModuleWorld::~ModuleWorld()
{
}

bool ModuleWorld::Start()
{
	return true;
}

bool ModuleWorld::CleanUp()
{
	return true;
}

update_status ModuleWorld::Update()
{
	// ----- START -----
	string input;

	do {
		cout << "Would you like to start a new world?\n";
		cout << "(Input yes/y to start a world)\n";
		cout << "(Input no/n to close the application)\n";

		cin >> input;

		if (input == "n" || input == "no")
			return UPDATE_STOP;

	} while (input != "n" && input != "no" && input != "yes" && input != "y");

	cout << "\n";
	cout << "Let's begin!\n";
	StartWorld();

		return UPDATE_CONTINUE;
}

// ------------------------------
// ------------------------------
// ------------------------------

void ModuleWorld::StartWorld()
{
	// Name World???
	// Describe World:	1. Overview (world seed)  
	//					2. Sky		(Moons, Suns, Calendar)
	//					3. Geography (Lots of rivers, waters, sea, lots of desert, ice, jungle, etc...)
	//					4. Flora & Fauna

	// Locations:		1. Natural formations. (Common and uncommon: Bays, landscapes, reefs, dunes, stone forests, rarities.)
	//					2. Human creations. (Cities, towns, ports, statues, churches, castles, etc.)

	// to be continued...
	
	world_type = GenerateWorldType();

	string input;
	do {

	world_name = app->namegenerator->GenerateName();
	cout << "\n";
	cout << "World name is: "<< world_name<< "\nDo you would you like to keep it(yes/y/no/n?)";

	cin >> input;

	} while (input != "y" && input != "yes");

	SetWorldOverview();
}

ModuleWorld::WorldType ModuleWorld::GenerateWorldType()
{
	srand((int)time(0));

	int randtofour = (rand() % 4);

	return WorldType(randtofour);
}

void ModuleWorld::SetWorldOverview()
{
	srand((int)time(0));

	for (int i = 0; i < 3; ++i)
	{
		vector<Location*>locations = app->conceptmanager->GetLocationVector();

		int randloc = (rand() % locations.size());

		int randandj = (rand() % locations[randloc]->GetAdjectives().size());
	
		vector<Adjective*>adjectives = app->conceptmanager->GetAdjectivesByKey(locations[randloc]->GetAdjectives()[randandj]);

		world_overview[i][0] = locations[randloc];
		
		world_overview[i][1] = adjectives[(rand() % adjectives.size())];
		cout << adjectives[(rand() % adjectives.size())]->GetString() << " ";
		cout << locations[randloc]->GetString() << " ";
	}
	getchar();
	int a = 2;
}
