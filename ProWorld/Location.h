#pragma once
#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "Concept.h"

class Location : public Concept {

public:
	Location();
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
};

#endif