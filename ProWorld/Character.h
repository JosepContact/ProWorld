#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Race.h"
#include "Society.h"
#include "Globals.h"

#define MIN_AGE 18
#define MAX_AGE 50

class Character
{
public:

	enum MoralAlignment
	{
		MGood = 0,
		MNeutral,
		MEvil,
		MUnknown
	};
	enum AttitudeAlignment
	{
		ALawful = 0,
		ANeutral,
		AChaotic,
		AUnknown
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
		ArcUnknown
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
		MainVillain,
		SecondaryVillain,
		CTNeutral
	};

	Character();
	Character(Character::MoralAlignment moral, Character::AttitudeAlignment attitude, Character::Archetype archetype, Character::CharacterType type, 
		int str, int intel, int dex, int cha);
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

	std::string pronoun;
	std::string reflective_pronoun;
	std::string posessive_pronoun;
	
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
	std::string GetPronoun() const;
	std::string GetReflectivePronoun() const;
	std::string GetPosessivePronoun() const;


	// ------------

	void GenerateName();
	void GenerateRace();

	// ----------- STATS ----------
	uint strength = 0;
	uint dexterity = 0;
	uint intelligence = 0;
	uint charisma = 0;

	private:

	void SetStatsFromArchetype();

};

#endif //CHARACTER_H