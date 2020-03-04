#pragma once

#ifndef SOCIETY_H
#define SOCIETY_H

#include "Race.h"
#include "Location.h"

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>

#define MAX_RACE_L 4
#define MAX_RACE_M 2


class Society
{
public:
	enum Scale {
		SVillage,
		MTown,
		LCity
	};

	Society();
	~Society();

private:
	std::string name;

	std::vector<Race*> races;

	Scale scale;

	Location* location;

	bool is_asian_based; // 50% chance of true when placed at the EAST
	bool is_tribal; // 50% chance of true when NOT coastal and climate ARID or TROPICAL
public:


public:
	
	void SetName(std::string);
	std::string GetName() const;
	std::vector<Race*> GetRaces() const;

	void SetScale(Scale);
	Scale GetScale() const;

	void AddRace(Race*);


	Location* GetLocationPtr() const;
	bool AssignLocationPtr(Location*);

	void SetIsAsianBased(bool);
	bool IsAsianBased() const;
	void SetIsTribal(bool);
	bool IsTribal() const;
};


#endif // !SOCIETY_H
