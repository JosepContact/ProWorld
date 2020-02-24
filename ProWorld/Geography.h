#pragma once

#ifndef __GEOGRAPHY_H__
#define __GEOGRAPHY_H__

#include "Climate.h"
#include "Location.h"
#include "Society.h"

#include <array>
#include <vector>


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

	struct Place
	{
		Location* location;
		std::string name;
		bool has_name = false;
		void SetRandomGeoName();
		std::string desc;
	};

	struct CellLand
	{
		CellLand() {}
		~CellLand();

		LandType gtype;
		std::vector<Place*> places;
		std::vector<Society*> societies;
		bool is_coastline;
		CardinalPoints cardinal;

		void CreateSociety(Location* tLoc);
		Place* CreatePlace();
	private:
		void SetRaces(Society*);
		bool CheckWater() const;
	};

public:
	Geography();
	Geography(GeographyType type);
	~Geography();

	void DistributeLand(Climate::ClimatesType cl_type);
	void SetCoastlines();

	std::vector<CellLand> GetGeovector();

private:
	CellLand geoarray_land[3][3];
	int geowater_cells;
	GeographyType geotype = AboveLand;
};

#endif //GEOGRAPHY_H