#pragma once

#ifndef __SKY_H__
#define __SKY_H__

#include "Globals.h"
#include <vector>

class Moon
{
private:
	std::string name;
	std::string color;
public:
	std::string GetName() const;
	std::string GetColor() const;

	void SetName(std::string name);
	void SetColor(std::string color);
};

class Sun
{
private:
	std::string name;
	std::string color;
public:
	std::string GetName() const;
	std::string GetColor() const;

	void SetName(std::string name);
	void SetColor(std::string color);
};

class Sky
{
private:
	Moon* moon = nullptr;
	Sun* sun = nullptr;
	// --------------
	bool isvisible = true;
	bool multisun = false;
	bool multimoon = false;
	std::vector<Moon*> vector_moons;
	std::vector<Sun*> vector_suns;

	std::string color;

	uint nSuns = 0;
	uint nMoons = 0;
	uint nConstellations = 0;
	uint daytime_duration;
public:
	bool IsVisible() const;

	Moon* GetMoon() const;
	Sun* GetSun() const;
	bool IsMultisun() const;
	bool IsMultimoon() const;
	std::vector<Moon*>  GetMoonVector() const;
	std::vector<Sun*>  GetSunVector() const;

	std::string GetColor() const;
	void SetColor(std::string color);

	uint getNSuns();
	uint getNMoons();
	uint getNConstellations();
	uint getdaytimeDuration();

};

#endif // SKY_H