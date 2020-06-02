#include "Character.h"
#include "App.h"
#include "HelperFunctions.h"
#include "ModuleNameGenerator.h"


Character::Character()
{

	// Age should ideally be between 13 and 60 for now.
	age = GetRandomNumber(MIN_AGE, MAX_AGE);
	// Gender is way more common to be male or female than others.
	if (GetBoolByRandom(VERY_LOW_CHANCE))
	{
		if (GetBoolByRandom(LOW_CHANCE))
		{
			gender = Non_binary;
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenRegularFemaleCharName();
			else name = app->namegenerator->GenRegularMaleCharName();
		}
		else if (GetBoolByRandom(MEDIUM_CHANCE))
		{
			gender = Maletrans;
			name = app->namegenerator->GenRegularMaleCharName();
		}
		else
		{
			gender = Femaletrans;
			name = app->namegenerator->GenRegularFemaleCharName();
		}
	}
	else if (GetBoolByRandom(MEDIUM_CHANCE))
	{
		gender = Male;
		name = app->namegenerator->GenRegularMaleCharName();
	}
	else 
		{
		gender = Female;
		name = app->namegenerator->GenRegularFemaleCharName();
	}


	moral = (MoralAlignment)GetRandomNumber(0, 2);
	attitude = (AttitudeAlignment)GetRandomNumber(0, 2);
	archetype = (Archetype)GetRandomNumber(0, 14);
	shadow = false;

	// if the character is evil, shadow will be set to true later.
}

Character::~Character()
{
	goal = "";
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

std::string Character::GetGoal() const
{
	return goal;
}

void Character::SetGoal(std::string str)
{
	goal = str;
}

std::string Character::GetFlaw() const
{
	return flaw;
}

void Character::SetFlaw(std::string str)
{
	flaw = str;
}

void Character::SetName(std::string str)
{
	name = str;
}

std::string Character::GetName() const
{
	return name;
}

void Character::SetSocietyOrigin(Society * soc)
{
	origin = soc;
}

Society* Character::GetSocietyOrigin() const
{
	return origin;
}

void Character::GenerateName()
{

	switch (gender)
	{
	case Non_binary:
		if (origin->IsTribal() == true)
		{
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenMTribalName();
			else name = app->namegenerator->GenFTribalName();
		}
		if (origin->IsAsianBased() == true)
		{
			if (GetBoolByRandom(MEDIUM_CHANCE))
			{
				if (GetBoolByRandom(MEDIUM_CHANCE))
				{
					name = app->namegenerator->GenChineseMName();
				} else name = app->namegenerator->GenChineseFName();
			}
			else
			{
				if (GetBoolByRandom(MEDIUM_CHANCE))
				{
					name = app->namegenerator->GenJapaneseMName();
				} else name = app->namegenerator->GenJapaneseFName();
			}
		}
		break;
	case Femaletrans:
		if (origin->IsTribal() == true)
			name = app->namegenerator->GenFTribalName();

		if (origin->IsAsianBased() == true)
		{
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenChineseFName();
			else name = app->namegenerator->GenJapaneseFName();
		}

		break;
	case Maletrans:
		if (origin->IsTribal() == true)
			name = app->namegenerator->GenMTribalName();

		if (origin->IsAsianBased() == true)
		{
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenChineseMName();
			else name = app->namegenerator->GenJapaneseMName();
		}

		break;
	case Female:
		if (origin->IsTribal() == true)
			name = app->namegenerator->GenFTribalName();

		if (origin->IsAsianBased() == true)
		{
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenChineseFName();
			else name = app->namegenerator->GenJapaneseFName();
		}

		break;
	case Male:
		if (origin->IsTribal() == true)
			name = app->namegenerator->GenMTribalName();

		if (origin->IsAsianBased() == true)
		{
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenChineseMName();
			else name = app->namegenerator->GenJapaneseMName();
		}

		break;
	default:
		break;

	}
}

void Character::GenerateRace()
{
	race = origin->GetRaces()[GetRandomNumber(0, origin->GetRaces().size() - 1)];

	archetype = static_cast<Character::Archetype>(race->GetArchetypes()[GetRandomNumber(0, race->GetArchetypes().size() - 1)]);

}
