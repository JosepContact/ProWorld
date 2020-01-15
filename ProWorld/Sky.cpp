#include "Sky.h"

std::string Moon::GetName() const
{
	return name;
}

std::string Moon::GetColor() const
{
	return color;
}

void Moon::SetName(std::string name)
{
	this->name = name;
}

void Moon::SetColor(std::string color)
{
	this->color = color;
}

std::string Sun::GetName() const
{
	return name;
}

std::string Sun::GetColor() const
{
	return color;
}

void Sun::SetName(std::string name)
{
	this->name = name;
}

void Sun::SetColor(std::string color)
{
	this->color = color;
}

bool Sky::IsVisible() const
{
	return isvisible;
}

Moon * Sky::GetMoon() const
{
	return moon;
}

Sun * Sky::GetSun() const
{
	return sun;
}

bool Sky::IsMultisun() const
{
	return multisun;
}

bool Sky::IsMultimoon() const
{
	return multimoon;
}

std::vector<Moon*> Sky::GetMoonVector() const
{
	return vector_moons;
}

std::vector<Sun*> Sky::GetSunVector() const
{
	return vector_suns;
}

std::string Sky::GetColor() const
{
	return color;
}

void Sky::SetColor(std::string color)
{
	this->color;
}

uint Sky::getNSuns()
{
	return nSuns;
}

uint Sky::getNMoons()
{
	return nMoons;
}

uint Sky::getNConstellations()
{
	return nConstellations;
}

uint Sky::getdaytimeDuration()
{
	return daytime_duration;
}
