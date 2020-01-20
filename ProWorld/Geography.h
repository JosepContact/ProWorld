#pragma once

#ifndef __GEOGRAPHY_H__
#define __GEOGRAPHY_H__

#include "Concept.h"

#include <array>
#include <vector>
#include "Climate.h"

class Geography
{
public:

	enum GeographyType {
		AboveLand,
		Underwater,
		Underground,
	};

	enum CardinalPoints
	{
		NORTHWEST,		//0	//0.0
		NORTH,			//1	//0.1
		NORTHEAST,		//2	//0.2	
		WEST,			//3	//1.0
		CENTER,			//4	//1.1	
		EAST,			//5	//1.2
		SOUTHWEST,		//6	//2.0
		SOUTH,			//7	//2.1
		SOUTHEAST		//8	//2.2
	};

	enum LandType
	{
		Land,
		Water
	};

	struct CellLand
	{
		LandType gtype;
		std::vector<Concept*> locations;
		bool is_coastline;
		CardinalPoints cardinal;
	};

public:
	Geography();
	Geography(GeographyType type);
	~Geography();

	void DistributeLand(Climate::ClimatesType cl_type);
	void SetCoastlines();

private:
	CellLand geoarray_land[3][3];
	int geowater_cells;
	GeographyType geotype = AboveLand;
};

#endif //GEOGRAPHY_H