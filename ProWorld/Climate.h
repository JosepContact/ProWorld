#pragma once
#ifndef __CLIMATE_H__
#define __CLIMATE_H__

#include "Concept.h"


class Climate : public Concept {

public:
	enum ClimatesType
	{
		Tropical, //HOT 0
		Arid, //HOT 1
		Continental,  //REGULAR 2
		Polar  //COLD 3
	};

	Climate();
	Climate(std::string argword, ConceptType argtype);
	~Climate();
private:
	std::string temperature;
	ClimatesType climate_type;
public:
	void SetTemperature(std::string temperature);
	void SetClimateType(ClimatesType climatetype);

	std::string GetTemperature() const;
	ClimatesType GetClimateType() const;

};

#endif // !CLIMATE_H

