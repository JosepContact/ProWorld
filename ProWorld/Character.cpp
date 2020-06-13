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
			pronoun = "they";
			reflective_pronoun = "them";
			posessive_pronoun = "their";
			if (GetBoolByRandom(MEDIUM_CHANCE))
				name = app->namegenerator->GenRegularFemaleCharName();
			else name = app->namegenerator->GenRegularMaleCharName();
		}
		else if (GetBoolByRandom(MEDIUM_CHANCE))
		{
			gender = Maletrans;
			pronoun = "he";
			reflective_pronoun = "him";
			posessive_pronoun = "his";
			name = app->namegenerator->GenRegularMaleCharName();
		}
		else
		{
			gender = Femaletrans;
			pronoun = "she";
			reflective_pronoun = "her";
			posessive_pronoun = "her";
			name = app->namegenerator->GenRegularFemaleCharName();
		}
	}
	else if (GetBoolByRandom(MEDIUM_CHANCE))
	{
		gender = Male;
		pronoun = "he";
		reflective_pronoun = "him";
		posessive_pronoun = "his";
		name = app->namegenerator->GenRegularMaleCharName();
	}
	else 
		{
		gender = Female;
		pronoun = "she";
		reflective_pronoun = "her";
		posessive_pronoun = "her";
		name = app->namegenerator->GenRegularFemaleCharName();
	}


	moral = (MoralAlignment)GetRandomNumber(0, 2);
	attitude = (AttitudeAlignment)GetRandomNumber(0, 2);
	archetype = (Archetype)GetRandomNumber(0, 14);
	shadow = false;

	strength = GetRandomNumber(0, 1);
	dexterity = GetRandomNumber(0, 1);
	intelligence = GetRandomNumber(0, 1);
	charisma = GetRandomNumber(0, 1);

	SetStatsFromArchetype();
}

Character::Character(Character::MoralAlignment moral, Character::AttitudeAlignment attitude, Character::Archetype archetype, Character::CharacterType type, 
	int str, int intel, int dex, int cha)
{
	this->moral = moral;
	this->attitude = attitude;
	this->archetype = archetype;
	this->character_type = type;
	strength = str;
	intelligence = intel;
	dexterity = dex;
	charisma = cha;
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

std::string Character::GetPronoun() const
{
	return pronoun;
}

std::string Character::GetReflectivePronoun() const
{
	return reflective_pronoun;
}

std::string Character::GetPosessivePronoun() const
{
	return posessive_pronoun;
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

	archetype = static_cast<Character::Archetype>(race->GetArchetypes()[GetRandomNumber(0, race->GetArchetypes().size()-1)]);

}

void Character::SetStatsFromArchetype()
{
	switch (archetype)
	{
	case Character::Busisnessman:
		intelligence += 3;
		break;
	case Character::Protector:
		strength += 1;
		dexterity += 1;
		break;
	case Character::Recluse:
		intelligence += 3;
		charisma -= 1;
		dexterity -= 1;
		break;
	case Character::Fool:
		intelligence -= 1;
		charisma += 3;
		break;
	case Character::Casanova:
		charisma += 3;
		break;
	case Character::Revolutionary:
		intelligence += 2;
		strength += 1;
		break;
	case Character::Artist:
		intelligence += 1;
		charisma += 2;
		break;
	case Character::King:
		strength += 1;
		intelligence += 1;
		dexterity += 1;
		break;
	case Character::Seductress:
		charisma += 1;
		dexterity += 1;
		intelligence += 1;
		break;
	case Character::Amazon:
		strength += 1;
		dexterity += 2;
		break;
	case Character::Daughter:
		charisma += 2;
		dexterity += 1;
		break;
	case Character::Matriarch:
		charisma += 1;
		strength += 1;
		intelligence += 1;
		break;
	case Character::Nurturer:
		dexterity += 1;
		charisma += 1;
		break;
	case Character::Maiden:
		dexterity += 3;
		intelligence -= 1;
		break;
	case Character::Mystic:
		intelligence += 2;
		dexterity += 1;
		strength -= 1;
		break;
	case Character::Martyr:
		strength += 1;
		charisma += 2;
		break;
	default:
		break;
	}

	if (intelligence > 3) intelligence = 3;
	if (intelligence < 0) intelligence = 0;
	if (strength > 3) strength = 3;
	if (strength < 0) strength = 0;
	if (dexterity > 3) dexterity = 3;
	if (dexterity < 0) dexterity = 0;
	if (charisma > 3) charisma = 3;
	if (charisma < 0) charisma = 0;

	int a = 2;
}
