#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Race.h"

#define MIN_AGE 13
#define MAX_AGE 60

class Character
{
public:
	Character();
	virtual ~Character();

	enum MoralAlignment
	{
		MGood,
		MNeutral,
		MEvil
	};
	enum AttitudeAlignment
	{
		ALawful,
		ANeutral,
		AChaotic
	};
	enum Archetype
	{
		Busisnessman,
		Protector,
		Recluse,
		Casanova,
		Revolutionary,
		Artist,
		King,
		Seductress, // n = 7
		Amazon,
		Daughter,
		Matriarch,
		Nurturer,
		Maiden,
		Mystic,
		Martyr
	};

	enum Gender
	{
		Male,
		Female,
		Non_binary,
		Maletrans,
		Femaletrans
	};

private:
	bool shadow = false;
	MoralAlignment moral;
	AttitudeAlignment attitude;
	Archetype archetype;

	int age;
	Race* race;
	Gender gender;
public:


public:
	// Setters - Getters
	void SetShadow(bool);
	bool GetShadow() const;
	void SetAlignment(MoralAlignment, AttitudeAlignment);
	MoralAlignment GetMorality() const;
	AttitudeAlignment GetAttitude() const;
	void SetArchetype(Archetype);
	Archetype GetArchetype() const;
	void SetAge(int);
	int GetAge() const;
	void SetRace(Race*);
	Race* GetRace() const;
	Gender GetGender() const;
};

#endif //CHARACTER_H