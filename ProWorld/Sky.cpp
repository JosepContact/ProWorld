#include "Sky.h"
#include "HelperFunctions.h"

using namespace std;

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


void Sun::SetName(std::string name)
{
	this->name = name;
}

Sky::Sky(SkyVisibility vis, int nSun, int nMon, int nCon, bool reg_dayt, int dayt_dur, DaytimeType dayt_type)
{
	visibility = vis;
	nSuns = nSun;
	nMoons = nMon;
	nConstellations = nCon;
	regular_daytime = reg_dayt;
	daytime_duration = dayt_dur;
	daytime_type = dayt_type;

	if (visibility == NonVisible) return;

	//multisun = (nSun > 1);

	if (multisun = nSun > 1)
	{
		for (uint i = 0; i < nSun; ++i)
			CreateSun();
	}
	else
		sun = CreateSun();

	if (visibility == PartiallyVisible) return;

	//multimoon = (nMon > 1);

	if (multimoon = nMon > 1)
	{
		for (uint i = 0; i < nMon; ++i)
			CreateMoon();
	}
	else
		moon = CreateMoon();
	
}

Sky::Sky()
{
}

Sky::~Sky()
{

	if (multisun > 1)
	{
		for (vector<Sun*>::iterator it = vector_suns.begin(); it != vector_suns.end(); ++it)
			RELEASE((*it));
	}
	else RELEASE(sun);

	if (multimoon > 1)
	{
		for (vector<Moon*>::iterator it = vector_moons.begin(); it != vector_moons.end(); ++it)
			RELEASE((*it));
	}
	else RELEASE(moon);

}

Sun * Sky::CreateSun()
{
	Sun* sun = nullptr;

	sun = new Sun();
	vector_suns.push_back(sun);

	return sun;
}

Moon * Sky::CreateMoon()
{
	Moon* moon = nullptr;

	moon = new Moon();
	vector_moons.push_back(moon);

	return moon;
}

Sky::SkyVisibility Sky::GetVisibility() const
{
	return visibility;
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

uint Sky::getNSuns() const
{
	return nSuns;
}

uint Sky::getNMoons() const
{
	return nMoons;
}

uint Sky::getNConstellations() const
{
	return nConstellations;
}

uint Sky::getdaytimeDuration() const
{
	return daytime_duration;
}

Sky::DaytimeType Sky::GetDaytimeType() const
{
	return daytime_type;
}

bool Sky::isDaytimeRegular() const
{
	return regular_daytime;
}
