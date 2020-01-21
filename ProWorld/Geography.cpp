#include "Geography.h"
#include "HelperFunctions.h"

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
		
	do {
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
		} while (wtcel > 0);
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


