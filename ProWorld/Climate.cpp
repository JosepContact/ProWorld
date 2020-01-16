#include "Climate.h"

Climate::Climate()
{
}

Climate::Climate(std::string argword, ConceptType argtype)
{
	word = argword;
	type = argtype;
}

Climate::~Climate()
{
}

void Climate::SetTemperature(std::string temperature)
{
	this->temperature = temperature;
}

void Climate::SetClimateType(ClimatesType climatetype)
{
	climate_type = climatetype;
}

std::string Climate::GetTemperature() const
{
	return temperature;
}

Climate::ClimatesType Climate::GetClimateType() const
{
	return climate_type;
}
