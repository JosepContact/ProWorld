#include "Character.h"
#include "App.h"
#include "HelperFunctions.h"


Character::Character()
{

	// Age should ideally be between 13 and 60 for now.
	age = GetRandomNumber(MIN_AGE, MAX_AGE);
	// Gender is way more common to be male or female than others.
	if (GetBoolByRandom(VERY_LOW_CHANCE))
	{
		if (GetBoolByRandom(MEDIUM_LOW_CHANCE))
		{
			gender = Non_binary;
		}
		else if (GetBoolByRandom(MEDIUM_CHANCE))
			gender = Maletrans;
		else gender = Femaletrans;
	}
	else if (GetBoolByRandom(MEDIUM_CHANCE))
		gender = Male;
	else gender = Female;

	moral = (MoralAlignment)GetRandomNumber(0, 2);
	attitude = (AttitudeAlignment)GetRandomNumber(0, 2);
	archetype = (Archetype)GetRandomNumber(0, 14);

	// if the character is evil, shadow will be set to true later.
}

Character::~Character()
{
}

void Character::SetShadow(bool s)
{
	shadow = s;
}

bool Character::GetShadow() const
{
	return shadow;
}

void Character::SetAlignment(MoralAlignment ma, AttitudeAlignment aa)
{
	moral = ma;
	attitude = aa;
}

Character::MoralAlignment Character::GetMorality() const
{
	return moral;
}

Character::AttitudeAlignment Character::GetAttitude() const
{
	return attitude;
}

void Character::SetArchetype(Archetype arc)
{
	archetype = arc;
}

Character::Archetype Character::GetArchetype() const
{
	return archetype;
}

void Character::SetAge(int a)
{
	age = a;
}

int Character::GetAge() const
{
	return age;
}

void Character::SetRace(Race * ptr)
{
	race = ptr;
}

Race * Character::GetRace() const
{
	return race;
}

Character::Gender Character::GetGender() const
{
	return gender;
}
