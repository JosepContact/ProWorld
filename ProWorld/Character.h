#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Race.h"
#include "Society.h"

#define MIN_AGE 13
#define MAX_AGE 60

class Character
{
public:

	enum MoralAlignment
	{
		MGood = 1,
		MNeutral,
		MEvil,
	};
	enum AttitudeAlignment
	{
		ALawful = 1,
		ANeutral,
		AChaotic,
	};
	enum Archetype
	{
		Busisnessman = 0,
		Protector,
		Recluse,
		Fool,
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
		Martyr,
	};

	enum Gender
	{
		Male,
		Female,
		Non_binary,
		Maletrans,
		Femaletrans
	};
	enum CharacterType
	{
		Hero,
		Secondary,
		Neutral,
		MainVillain,
		SecondaryVillain
	};

	Character();
	Character(Character::MoralAlignment moral, Character::AttitudeAlignment attitude, Character::Archetype archetype, Character::CharacterType type);
	virtual ~Character();

private:
	bool shadow;
	MoralAlignment moral;
	AttitudeAlignment attitude;
	Archetype archetype;

	int age;
	Race* race;
	Gender gender;
	std::string goal;
	std::string flaw;
	std::string name;
	Society* origin;

	
public:
	CharacterType character_type;


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
	std::string GetGoal() const;
	void SetGoal(std::string);
	std::string GetFlaw() const;
	void SetFlaw(std::string);
	void SetName(std::string);
	std::string GetName() const;
	void SetSocietyOrigin(Society*);
	Society* GetSocietyOrigin() const;


	// ------------

	void GenerateName();
	void GenerateRace();

};

#endif //CHARACTER_H