#include "ModuleWorld.h"
#include "App.h"
#include "Location.h"
#include "Adjective.h"
#include "HelperFunctions.h"

#include <cstdlib>
#include <ctime>

using namespace std;

#define print cout <<
#define read cin >>>

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
	
	// ----- OVERVIEW --------
	world_type = GenerateWorldType();

	string input;
	do {

	world_name = app->namegenerator->GenerateName();
	cout << "\n";
	cout << "World name is: "<< toUppercase(world_name) << "\nDo you would you like to keep it(yes/y/no/n?)";

	cin >> input;

	} while (input != "y" && input != "yes");

	SetWorldOverview();

	cout << "Your world has "<<AdjectiveandNameOutput(false, true, (Adjective*)world_overview[0][1], (Location*)world_overview[0][0]);
	cout << ", " << AdjectiveandNameOutput(false, true, (Adjective*)world_overview[1][1], (Location*)world_overview[1][0]);
	cout << " and " << AdjectiveandNameOutput(false, true, (Adjective*)world_overview[2][1], (Location*)world_overview[2][0]) << ".";

	getchar();

	// ------ SKY ------

}

ModuleWorld::WorldType ModuleWorld::GenerateWorldType()
{
	return WorldType(GetRandomNumber(0, 4));
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
	}
}

void ModuleWorld::SetSky()
{

	// is sky visible?

	if (GetBoolByRandom(LOW_CHANCE))
	{
		// days longer than 24 hours
	}
	else if (GetBoolByRandom(LOW_CHANCE))
	{
		// days shorter than 24 hours
	}

	if (GetBoolByRandom(MEDIUM_CHANCE))
	{
		// more than one moon
	
	}
	else
	{
		// the moon
	}


	if (GetBoolByRandom(MEDIUM_LOW_CHANCE))
	{
		// more than one sun
		
	}
	else
	{
		// the sun
	}


	// constellations
}
