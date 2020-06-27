#include "ModuleWorld.h"
#include "App.h"
#include "Location.h"
#include "Adjective.h"
#include "HelperFunctions.h"
#include "CharacterGoals.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define print cout <<
#define read cin >>>

ModuleWorld::ModuleWorld(bool start_enabled) : Module(start_enabled)
{
}

ModuleWorld::~ModuleWorld()
{
	RELEASE (wsky);
	//RELEASE(wclimate);
	RELEASE(wgeography);
	//for (vector<Society*>::reverse_iterator rit = wsocieties.rbegin(); rit != wsocieties.rend(); ++rit)
		//RELEASE(*rit);
	for (vector<Character*>::reverse_iterator rit = wcharacters.rbegin(); rit != wcharacters.rend(); ++rit)
		RELEASE(*rit);

	geoVector.clear();
	wsocieties.clear();
	wcharacters.clear();

	// mem_leaks we need to properly clean memory when looping through the app :)
	// this does the trick for now
}

bool ModuleWorld::Start()
{
	StartWorld();
	return true;
}

bool ModuleWorld::CleanUp()
{
	return true;
}

update_status ModuleWorld::Update()
{
	if (app->graphics->create_world == true)
	{
		DeleteWorld();
		StartWorld();
		app->graphics->create_world = false;
	}


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

	wname = app->namegenerator->GenerateName();

	/*cout << "Your world has "<<AdjectiveandNameOutput(false, true, (Adjective*)woverview[0][1], (Location*)woverview[0][0]);
	cout << ", " << AdjectiveandNameOutput(false, true, (Adjective*)woverview[1][1], (Location*)woverview[1][0]);
	cout << " and " << AdjectiveandNameOutput(false, true, (Adjective*)woverview[2][1], (Location*)woverview[2][0]) << ".";*/

	//getchar();

	// ------ CLIMATE ------

	SetClimate(); // Since Sky affects climate we create it first;
	wclimate = app->conceptmanager->GetClimateVector()[GetRandomNumber(Climate::ClimatesType::Tropical, Climate::ClimatesType::Polar)];

	// ------ SKY ------

	SetSky();

	// ----- GEOGRAPHY --------
		
	SetGeography();

	// ----- CREATE MAP -------

	CreateMap();

	// ------ CREATE CHARACTERS ---------

	CreateCharacters();

	//------ CREATE STORY -------------
	app->story->CreateStory();
}

void ModuleWorld::DeleteWorld()
{
	RELEASE(wsky);
	//RELEASE(wclimate);
	RELEASE(wgeography);
	//for (vector<Society*>::reverse_iterator rit = wsocieties.rbegin(); rit != wsocieties.rend(); ++rit)
		//RELEASE(*rit);
	for (vector<Character*>::reverse_iterator rit = wcharacters.rbegin(); rit != wcharacters.rend(); ++rit)
		RELEASE(*rit);

	geoVector.clear();
	wsocieties.clear();
	wcharacters.clear();
}

ModuleWorld::WorldType ModuleWorld::GenerateWorldType()
{
	return WorldType(GetRandomNumber(0, 4));
}

void ModuleWorld::SetClimate()
{
	//wclimate = new Climate();
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
		int randcell = GetRandomNumber(0, geoVector.size() - 1);
			if (geoVector[randcell].gtype != Geography::LandType::Water && nCities > 0)
			{
				Location* tLoc = app->conceptmanager->GetLocationByName("City");
				Society* soc = geoVector[randcell].CreateSociety(tLoc);
				SetSociety(soc, geoVector[randcell]);
				nCities--;
			}
	}

	// ---- CREATE TOWNS, VILLAGES & PORTS ----
	// 2 - 4 TOWNS-VILLAGES-PORTS
	int nTowns = GetRandomNumber(2, 4);
	nLocations -= nTowns;

	while (nTowns > 0)
	{
		int randcell = GetRandomNumber(0, geoVector.size() - 1);
			if (geoVector[randcell].gtype == Geography::LandType::Water) continue;

			if (GetBoolByRandom(LOW_CHANCE) && nTowns > 0)
			{
				switch (GetRandomNumber(1, 3))
				{
				case 1:
				{
					if (geoVector[randcell].is_coastline) {
						Location* tLoc = app->conceptmanager->GetLocationByName("Port");
						Society* soc = geoVector[randcell].CreateSociety(tLoc);
						SetSociety(soc, geoVector[randcell]);
					}
					break;
				}
				case 2:
				{
					Location* tLoc = app->conceptmanager->GetLocationByName("Town");
					Society * soc = geoVector[randcell].CreateSociety(tLoc);
					SetSociety(soc, geoVector[randcell]);
					break;
				}
				case 3:
				{
					Location* tLoc = app->conceptmanager->GetLocationByName("Village");
					Society * soc = geoVector[randcell].CreateSociety(tLoc);
					SetSociety(soc, geoVector[randcell]);
					break;
				}
				}
				nTowns--;
			}
	}


	// ---- CREATE REST OF THE WORLD ----

	while (nLocations > 0)
	{
		for (vector<Geography::CellLand>::iterator it = geoVector.begin(); it != geoVector.end(); ++it)
		{
			
			int random_number_loc = GetRandomNumber((int)Location::LocationType::tTemple,
				((int)app->conceptmanager->GetLocationVector().size()) - 1);

			Location* random_location = app->conceptmanager->GetLocationVector()[random_number_loc];

			if (random_location->CompareClimate(wclimate->GetClimateType()) && random_location->SpawnInSea((*it).gtype)
				&& random_location->GetIsCoastal() == (*it).is_coastline && nLocations > 0)
			{
				//(*it).locations.push_back(random_location);

				Geography::Place* place = (*it).CreatePlace();
				place->location = random_location;

				place->SetRandomGeoName();

				nLocations--;
			}
		}
	}
}

void ModuleWorld::CreateCharacters()
{
	int n_cha = GetRandomNumber(MIN_CHARACTERS, MAX_CHARACTERS);

	for (int i = 0; i < n_cha; ++i)
	{
		Character* character = new Character();
		wcharacters.push_back(character);
		wcharacters[i]->SetShadow(false);
		wcharacters[i]->SetGoal(string(HeroGoals[GetRandomNumber(0, 34)]));
		wcharacters[i]->SetFlaw(string(Flaws[GetRandomNumber(0, 20)]));
		wcharacters[i]->SetSocietyOrigin(wsocieties[GetRandomNumber(0, wsocieties.size() - 1)]);
		character->GenerateName();
		character->GenerateRace();
		if (character->GetMorality() == Character::MEvil)
		{
			character->SetShadow(true);
			character->character_type = Character::CharacterType::SecondaryVillain;
		} else
			character->character_type = Character::CharacterType::Secondary;

	}

	int evil_cha = n_cha / 3;

	for (int i = (n_cha-1); i > evil_cha; i--)
	{
		wcharacters[i]->SetAlignment(Character::MEvil, wcharacters[i]->GetAttitude());
		wcharacters[i]->SetShadow(true);
		wcharacters[i]->SetGoal(string(VillainGoals[GetRandomNumber(0, 22)]));

		wcharacters[i]->character_type = Character::CharacterType::SecondaryVillain;
		if(i == n_cha-1) wcharacters[i]->character_type = Character::CharacterType::MainVillain;
	}
	int sec_cha = 0;

	wcharacters[0]->SetAlignment((Character::MoralAlignment)GetRandomNumber(0, 1), wcharacters[0]->GetAttitude());
	wcharacters[0]->SetShadow(false);
	wcharacters[0]->character_type = Character::CharacterType::Hero;

	for (auto it = wcharacters.begin(); it != wcharacters.end(); ++it)
	{
		if ((*it)->character_type == Character::CharacterType::SecondaryVillain)
			++sec_cha;

		if (sec_cha > 1)
			(*it)->character_type = Character::CharacterType::ThirdVillain;
	}
	int a = 3;

}

Climate * ModuleWorld::GetClimate() const
{
	return wclimate;
}

Character * ModuleWorld::GetHero() const
{
	return wcharacters[0];
}

std::vector<Character*> ModuleWorld::GetSecondaries() const
{
	std::vector<Character*> secondaries;

	for (auto it = wcharacters.begin(); it != wcharacters.end(); ++it)
		if ((*it)->character_type == Character::CharacterType::Secondary)
			secondaries.push_back((*it));

	return secondaries;
}

std::vector<Character*> ModuleWorld::GetSecondaryVillains() const
{
	std::vector<Character*> secondaryvillains;

	for (auto it = wcharacters.begin(); it != wcharacters.end(); ++it)
	{
		if ((*it)->character_type == Character::CharacterType::SecondaryVillain)
			secondaryvillains.push_back((*it));
	}

	return secondaryvillains;
}

std::vector<Character*> ModuleWorld::GetThirdVillains() const
{
	std::vector<Character*> thirdvillains;

	for (auto it = wcharacters.begin(); it != wcharacters.end(); ++it)
	{
		if ((*it)->character_type == Character::CharacterType::ThirdVillain)
			thirdvillains.push_back((*it));
	}

	return thirdvillains;
}

std::vector<string> ModuleWorld::GetCharacterAdjectives(Character* cha)
{
	std::vector<string> ret;
	vector<RaceAdjective*> adjs = cha->GetRace()->GetAdjectives();
	for (vector<RaceAdjective*>::iterator it = adjs.begin(); it != adjs.end(); ++it)
		ret.push_back((*it)->Adjective);

	return ret;
}

std::string ModuleWorld::GetCharacterRace(Character* cha) const
{
	return cha->GetRace()->GetWord();
}

std::string ModuleWorld::GetCharacterName(Character*cha) const
{
	return cha->GetName();
}

std::string ModuleWorld::GetCharacterOriginType(Character* cha) const
{
	return cha->GetSocietyOrigin()->GetLocationPtr()->GetWord();
}

std::string ModuleWorld::GetCharacterOriginName(Character* cha) const
{
	return cha->GetSocietyOrigin()->GetName();
}

std::string ModuleWorld::GetCharacterPronoun(Character* cha) const
{
	return cha->GetPronoun();
}

std::string ModuleWorld::GetCharacterReflectivePronoun(Character* cha) const
{
	return cha->GetReflectivePronoun();
}

std::string ModuleWorld::GetCharacterPosessivePronoun(Character *c) const
{
	return c->GetPosessivePronoun();
}

std::string ModuleWorld::GetRandomLocation(Character * c) const
{
	Society* s = c->GetSocietyOrigin();

	string ret;
	do
	{
		ret = wsocieties[GetRandomNumber(0, wsocieties.size() - 1)]->GetName();
	} while (ret == s->GetName());

	return ret;
}


void ModuleWorld::SetSociety(Society * soc, Geography::CellLand &cell)
{
	if (cell.cardinal == Geography::CardinalPoints::NORTHEAST || cell.cardinal == Geography::CardinalPoints::EAST
		|| cell.cardinal == Geography::CardinalPoints::SOUTHEAST)
	{
		if (GetBoolByRandom(MEDIUM_CHANCE))
		soc->SetIsAsianBased(true);
	}
	if (wclimate->GetClimateType() == Climate::Arid || wclimate->GetClimateType() == Climate::Tropical)
	{
		if(cell.is_coastline == false && GetBoolByRandom(MEDIUM_CHANCE))
			soc->SetIsTribal(true);
	}
	wsocieties.push_back(soc);
}