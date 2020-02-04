#pragma once

#ifndef CITY_H
#define CITY_H

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>


#include "Race.h"

#define MAX_RACE_L 4
#define MAX_RACE_M 2


class City
{
public:
	enum Scale {
		SVillage,
		MTowm,
		LCity
	};

	City();
	~City();


	Geography::CardinalPoints cardinal;

private:
	std::string name;

	std::vector<Race*> races;
	bool inSea;
	bool isCoastal;
	Scale scale;

	Location* location;

public:
	
	void SetName(std::string);
	std::string GetName() const;
	std::vector<Race*> GetRaces() const;

	void SetScale(Scale);
	Scale GetScale() const;

	void SetIsCoastal(bool);
	bool GetIsCoastal() const;

	void SetInSea(bool);
	bool GetInSea() const;

	void AddRace(Race*);


	Location* GetLocationPtr() const;
	bool AssignLocationPtr(Location*);
};


#endif // !CITY_H
