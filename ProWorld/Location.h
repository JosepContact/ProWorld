#pragma once
#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "Concept.h"
#include<vector>

class Adjective;

class Location : public Concept {

public:
	Location();
	Location(std::string argword, std::string argplural, ConceptType argtype);
	~Location();

public:
	enum ClimateType {
		Continental, 
		Cold,
		Tropical,
		Arid,
		None
	};

	ClimateType climate;


private:

	std::vector<int> adjectives;

public:
	void SetName(std::string argname);

	void AddAdjective(int n);
	std::vector<int> GetAdjectives() const;
};

#endif