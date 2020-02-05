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
	//bool inSea;
	//bool isCoastal;
	Scale scale;

	Location* location;

public:
	
	void SetName(std::string);
	std::string GetName() const;
	std::vector<Race*> GetRaces() const;

	void SetScale(Scale);
	Scale GetScale() const;

	//void SetIsCoastal(bool);
	//bool GetIsCoastal() const;

	//void SetInSea(bool);
	//bool GetInSea() const;

	void AddRace(Race*);


	Location* GetLocationPtr() const;
	bool AssignLocationPtr(Location*);
};


#endif // !SOCIETY_H
