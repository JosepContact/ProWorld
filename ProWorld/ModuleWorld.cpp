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
	delete wsky;
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


	bool seemoon = false, seesun = false;
	switch (wsky->GetVisibility())
	{
	case Sky::SkyVisibility::Visible:
		print "Your world's sky is clear.\n";
		seemoon = true;
		seesun = true;
		break;
	case Sky::SkyVisibility::PartiallyVisible:
		print "Your world's sky is partially clear, the moon isn't visibile.\n";
		seemoon = false;
		seesun = true;
		break;
	case Sky::SkyVisibility::NonVisible:
		print "Your world's sky is hardly visbile.";
		seemoon = false;
		seesun = false;
		break;
	}

	if (wsky->IsMultimoon() && wsky->IsMultisun() && seemoon == true && seesun && true)
	{
		print "The sky has " << wsky->getNMoons() << " moons and " << wsky->getNSuns() << " suns.";
	}
	else if (wsky->IsMultimoon() && seemoon == true)
	{
		print "The sky has " << wsky->getNMoons() << " moons.";
	}
	else if (wsky->IsMultisun() && seesun == true)
	{
		print "The sky has " << wsky->getNSuns() << " suns.";
	}
	
	if (wsky->isDaytimeRegular() == false)
	{
		if (wsky->GetDaytimeType() == Sky::DaytimeType::Months)
		{
			print "In your world, daytime lasts " << wsky->getdaytimeDuration() << " months.";
		}
		else print "In your world, daytime lasts " << wsky->getdaytimeDuration() << " days.";
	}

	print "\n";
	print "Your world has climate: " << wclimate->GetWord() << "\n";

	print "\n";

	for (vector<Geography::CellLand>::iterator it = geoVector.begin(); it != geoVector.end(); ++it)
	{
		switch ((*it).cardinal)
		{
		case Geography::CardinalPoints::NORTHWEST:
			print "\nNORTHWEST: \n";
			break;
		case Geography::CardinalPoints::NORTH:
			print "\nNORTH: \n";
			break;
		case Geography::CardinalPoints::NORTHEAST:
			print "\nNORTHEAST: \n";
			break;
		case Geography::CardinalPoints::WEST:
			print "\nWEST: \n";
			break;
		case Geography::CardinalPoints::CENTER:
			print "\nCENTER: \n";
			break;
		case Geography::CardinalPoints::EAST:
			print "\nEAST: \n";
			break;
		case Geography::CardinalPoints::SOUTHWEST:
			print "\nSOUTHWEST: \n";
			break;
		case Geography::CardinalPoints::SOUTH:
			print "\nSOUTH: \n";
			break;
		case Geography::CardinalPoints::SOUTHEAST:
			print "\nSOUTHEAST: \n";
			break;
		}
		switch ((*it).gtype)
		{
		case Geography::LandType::Water:
			print "- It's mostly water.\n";
			break;
		case Geography::LandType::Land:
			print "- It's mostly land.\n";
			break;
		}
		for (auto it2 = (*it).locations.begin(); it2 != (*it).locations.end(); ++it2)
			print "There's a " << (*it2)->GetWord() << ".\n";
		
	}

	getchar();

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
	wtype = GenerateWorldType();

	string input;
	do {

	wname = app->namegenerator->GenerateName();
	cout << "\n";
	cout << "World name is: "<< toUppercase(wname) << "\nDo you would you like to keep it(yes/y/no/n?)";

	cin >> input;

	} while (input != "y" && input != "yes");

	SetWorldOverview();

	/*cout << "Your world has "<<AdjectiveandNameOutput(false, true, (Adjective*)woverview[0][1], (Location*)woverview[0][0]);
	cout << ", " << AdjectiveandNameOutput(false, true, (Adjective*)woverview[1][1], (Location*)woverview[1][0]);
	cout << " and " << AdjectiveandNameOutput(false, true, (Adjective*)woverview[2][1], (Location*)woverview[2][0]) << ".";*/

	getchar();

	// ------ CLIMATE ------

	SetClimate(); // Since Sky affects climate we create it first;
	wclimate = app->conceptmanager->GetClimateVector()[GetRandomNumber(Climate::ClimatesType::Tropical, Climate::ClimatesType::Polar)];

	// ------ SKY ------

	SetSky();

	// ----- GEOGRAPHY --------
		
	SetGeography();

	// ----- CREATE MAP -------

	CreateMap();
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

		woverview[i][0] = locations[randloc];
		
		woverview[i][1] = adjectives[(rand() % adjectives.size())];
	}
}

void ModuleWorld::SetClimate()
{
	wclimate = new Climate();
}

void ModuleWorld::SetSky()
{

	//--- Sky visibility
	Sky::SkyVisibility vis = Sky::SkyVisibility::Visible;
	// is sky visible?
	if (GetBoolByRandom(VERY_LOW_CHANCE))
	{
		vis = Sky::SkyVisibility::PartiallyVisible;
		if (GetBoolByRandom(VERY_LOW_CHANCE))
			vis = Sky::SkyVisibility::NonVisible;
	}


	//--- Sky daytime
	bool daytime_regularity = true;

	Sky::DaytimeType type;
	switch (GetRandomNumber(1, 2))
	{
	case 1:
		type = Sky::DaytimeType::Days;
		break;
	case 2:
		type = Sky::DaytimeType::Months;
		break;
	}
	int daytime_duration = 1;

	if (GetBoolByRandom(VERY_LOW_CHANCE))
	{
		// days longer than 24 hours
		daytime_regularity = false;
		if (type == Sky::DaytimeType::Days)
			daytime_duration = GetRandomNumber(2, 30);
		else daytime_duration = GetRandomNumber(1, 3);

		// CLIMATE = COLD!!!!
		wclimate = app->conceptmanager->GetClimateVector()[Climate::ClimatesType::Polar];
	}

	int nMoons = 1;
	//--- Sky moons
	if (GetBoolByRandom(MEDIUM_LOW_CHANCE) && vis == Sky::SkyVisibility::Visible)
	{
		// more than one moon
		nMoons = GetRandomNumber(2, 6);	
	}

	int nSuns = 1;
	if (GetBoolByRandom(LOW_CHANCE) && vis != Sky::SkyVisibility::NonVisible)
	{
		// more than one sun
		nSuns = GetRandomNumber(2, 3);

		//CLIMATE HOT!!!
		wclimate = app->conceptmanager->GetClimateVector()[GetRandomNumber(Climate::ClimatesType::Tropical, Climate::ClimatesType::Arid)];
	}

	wsky = new Sky(vis, nSuns, nMoons, 88, daytime_regularity, daytime_duration, type);

	//int nConst = 88;

	// constellations
}

void ModuleWorld::SetGeography()
{
	wgeography = new Geography(Geography::GeographyType::AboveLand); // for now we only have this one

	wgeography->DistributeLand(wclimate->GetClimateType());
	wgeography->SetCoastlines();


	//AboveLand: // 2 to 4 cells of land

	//Underwater: // 1 to 2 cells of land maybe

	//Underground: // to define...

}

void ModuleWorld::CreateMap()
{
	geoVector = wgeography->GetGeovector();

	int nLocations = N_LOCATIONS;

	// ---- CREATE CITIES ------
	// 3 - 4 CITIES

	int nCities = GetRandomNumber(3, 4);
	nLocations -= nCities;

	while (nCities > 0)
	{
		for (vector<Geography::CellLand>::iterator it = geoVector.begin(); it != geoVector.end(); ++it)
		{
			if ((*it).gtype != Geography::LandType::Water && GetBoolByRandom(MEDIUM_LOW_CHANCE) && nCities > 0)
			{
				(*it).locations.push_back(app->conceptmanager->GetLocationByName("City"));
				nCities--;
			}
		}
	}

	// ---- CREATE TOWNS, VILLAGES & PORTS ----
	// 2 - 4 TOWNS-VILLAGES-PORTS
	int nTowns = GetRandomNumber(2, 4);
	nLocations -= nTowns;

	while (nTowns > 0)
	{
		for (vector<Geography::CellLand>::iterator it = geoVector.begin(); it != geoVector.end(); ++it)
		{
			if ((*it).gtype == Geography::LandType::Water) continue;

			if (GetBoolByRandom(LOW_CHANCE) && nTowns > 0)
			{
				switch (GetRandomNumber(1, 3))
				{
				case 1:
				{
					if ((*it).is_coastline)
						(*it).locations.push_back(app->conceptmanager->GetLocationByName("Port"));
					break;
				}
				case 2:
					(*it).locations.push_back(app->conceptmanager->GetLocationByName("Town"));
					break;
				case 3:
					(*it).locations.push_back(app->conceptmanager->GetLocationByName("Village"));
					break;
				}
				nTowns--;
			}
		}
	}


	// ---- CREATE THE REST OF THE WORLD ----

	while (nLocations > 0)
	{
		for (vector<Geography::CellLand>::iterator it = geoVector.begin(); it != geoVector.end(); ++it)
		{
			
			int random_number_loc = GetRandomNumber((int)Location::LocationType::Temple,
				((int)app->conceptmanager->GetLocationVector().size()) - 1);

			Location* random_location = app->conceptmanager->GetLocationVector()[random_number_loc];

			if (random_location->CompareClimate(wclimate->GetClimateType()) && random_location->SpawnInSea((*it).gtype)
				&& random_location->GetIsCoastal() == (*it).is_coastline && nLocations > 0)
			{
				(*it).locations.push_back(random_location);
				nLocations--;
			}
		}
	}
	int a = 2;
}
