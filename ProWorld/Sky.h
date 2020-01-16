#pragma once

#ifndef __SKY_H__
#define __SKY_H__

#include "Globals.h"
#include <vector>

class Moon
{
public:
	enum MoonColors {
		Red,
		Blue,
		Yellow,
		White,
		Gray,
		Orange,
		Pale,
		Purple,
		Lime,
		Dark_Gray,
		Pearl,
		Silver,
		Teal,
	};

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
public:
private:
	std::string name;
public:
	std::string GetName() const;

	void SetName(std::string name);
};

class Sky
{
public:
	enum SkyVisibility {
		Visible,
		PartiallyVisible,
		NonVisible
	};

	enum DaytimeType {
		Days,
		Months,
	};

	Sky(SkyVisibility vis, int nSun, int nMon, int nCon, bool reg_dayt, int dayt_dur, DaytimeType dayt_type);
	Sky();
	virtual ~Sky();
private:
	Moon* moon = nullptr;
	Sun* sun = nullptr;
	// --------------
	SkyVisibility visibility;
	bool multisun = false;
	bool multimoon = false;
	std::vector<Moon*> vector_moons;
	std::vector<Sun*> vector_suns;

	std::string color;

	uint nSuns = 0;
	uint nMoons = 0;
	uint nConstellations = 0;
	bool regular_daytime;
	uint daytime_duration;
	DaytimeType daytime_type; 

	Sun* CreateSun();
	Moon* CreateMoon();

public:
	SkyVisibility GetVisibility() const;

	Moon* GetMoon() const;
	Sun* GetSun() const;
	bool IsMultisun() const;
	bool IsMultimoon() const;
	std::vector<Moon*>  GetMoonVector() const;
	std::vector<Sun*>  GetSunVector() const;

	std::string GetColor() const;
	void SetColor(std::string color);

	uint getNSuns() const;
	uint getNMoons() const;
	uint getNConstellations() const;
	uint getdaytimeDuration() const;
	DaytimeType GetDaytimeType() const;
	bool isDaytimeRegular() const;
};

#endif // SKY_H