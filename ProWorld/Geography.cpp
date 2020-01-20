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
				geoarray_land[i][j].gtype = Land;

		break;
	case Underwater:
		geowater_cells = GetRandomNumber(6, 9);
		break;
	case Underground:
		break;
	default:
		break;
	}
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
					if (GetBoolByRandom(LOW_CHANCE) == true && wtcel > 0)
					{
						geoarray_land[i][j].gtype = Water;
						wtcel--;
					}

				}
			}
		} while (wtcel > 0);
	}
