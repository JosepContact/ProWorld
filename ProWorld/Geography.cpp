#include "Geography.h"
#include "HelperFunctions.h"
#include "App.h"

using namespace std;

Geography::Geography()
{
}

Geography::Geography(GeographyType type)
{
	geotype = type;
	switch (type)
	{
	case AboveLand:
		geowater_cells = GetRandomNumber(2, 4);

		for (uint i = 0; i < 3; ++i)
			for (uint j = 0; j < 3; ++j)
			{
				geoarray_land[i][j].gtype = Land;
				geoarray_land[i][j].is_coastline = false;
			}

		break;
	case Underwater:
		geowater_cells = GetRandomNumber(6, 9);
		break;
	case Underground:
		break;
	default:
		break;
	}

	geoarray_land[0][0].cardinal = NORTHWEST;
	geoarray_land[0][1].cardinal = NORTH;	
	geoarray_land[0][2].cardinal = NORTHEAST;			
	geoarray_land[1][0].cardinal = WEST;			
	geoarray_land[1][1].cardinal = CENTER;				
	geoarray_land[1][2].cardinal = EAST;			
	geoarray_land[2][0].cardinal = SOUTHWEST;		
	geoarray_land[2][1].cardinal = SOUTH;			
	geoarray_land[2][2].cardinal = SOUTHEAST;
}

Geography::~Geography()
{
}

void Geography::DistributeLand(Climate::ClimatesType cl_type)
{
	int wtcel = geowater_cells;
		
	while (wtcel > 0)
	{
			for (uint i = 0; i < 3; ++i)
			{
				for (uint j = 0; j < 3; ++j)
				{
					if (GetBoolByRandom(MEDIUM_LOW_CHANCE) == true && wtcel > 0)
					{
						geoarray_land[i][j].gtype = Water;
						wtcel--;
					}
				}
			}
		}
	}

void Geography::SetCoastlines()
{
	for (uint i = 0; i < 3; ++i)
	{
		for (uint j = 0; j < 3; ++j)
		{
			if (geoarray_land[i][j].gtype == Water) continue;
			if ((i - 1) >= 0)
			{
				if (geoarray_land[i - 1][j].gtype == Water)
				{
					geoarray_land[i][j].is_coastline = true;
					continue;
				}
			}
			if ((j - 1) >= 0)
			{
				if (geoarray_land[i][j - 1].gtype == Water)
				{
					geoarray_land[i][j].is_coastline = true;
					continue;
				}
			}
			if ((i + 1) < 3)
			{
				if (geoarray_land[i + 1][j].gtype == Water)
				{
					geoarray_land[i][j].is_coastline = true;
					continue;
				}
			}
			if ((j + 1) < 3)
			{
				if (geoarray_land[i][j + 1].gtype == Water)
				{
					geoarray_land[i][j].is_coastline = true;
					continue;
				}
			}
		}
	}
}

std::vector<Geography::CellLand> Geography::GetGeovector()
{
	vector<CellLand> ret;

	for (uint i = 0; i < 3; ++i)
		for (uint j = 0; j < 3; ++j)
			ret.push_back(geoarray_land[i][j]);

	return ret;
}

Geography::CellLand::~CellLand()
{
	for (vector<Society*>::reverse_iterator rit = societies.rbegin(); rit != societies.rend(); ++rit)
		RELEASE(*rit);
}

void Geography::CellLand::CreateSociety(Location * tLoc)
{
	Society* society = new Society();

	society->SetName(app->namegenerator->GenerateClassicName());

	if (!society->AssignLocationPtr(tLoc))
	{
		LOG("Assigned NULL Location at Geography::CellLand::CreateSociety(Location* tLoc)");
		return;
	}

	switch (society->GetLocationPtr()->GetLocationType())
	{
	case Location::tCity:
		society->SetScale(Society::LCity);
		break;
	case Location::tTown:
		society->SetScale(Society::MTown);
		break;
	case Location::tPort:
		society->SetScale(Society::MTown);
		break;
	case Location::tVillage:
		society->SetScale(Society::SVillage);
		break;
	default:
		break;
	}

	SetRaces(society);

	societies.push_back(society);
}

void Geography::CellLand::SetRaces(Society * s)
{
	//--- Set Races -----

	int n_races = 1;

	if (s->GetScale() == Society::LCity) n_races = GetRandomNumber(1, MAX_RACE_L);
	else if (s->GetScale() == Society::LCity) n_races = GetRandomNumber(1, MAX_RACE_M);

	vector<Race*> prep_races;
	vector<Race*> total_races = app->conceptmanager->GetRacesVectorByClimate();

	while (prep_races.size() < n_races)
	{
		Race* race = total_races[GetRandomNumber(0, total_races.size() - 1)];

		if (std::find(prep_races.begin(), prep_races.end(), race) != prep_races.end())
			continue;

		if (race->GetInSea() == CheckWater())
		{
			if (race->GetIsCoastal() || race->GetIsCoastal() == is_coastline)
			{
				prep_races.push_back(race);
				s->AddRace(race);
			}
		}
	}
	int a = 2;
}

bool Geography::CellLand::CheckWater() const
{
	return (gtype == Water);
}
