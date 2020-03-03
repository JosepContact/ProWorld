#include "ModuleNarration.h"
#include "HelperFunctions.h"
#include "App.h"
#include "Geography.h"
#include "ModuleNameGenerator.h"
#include "CharacterDesc.h"

#include <vector>

using namespace std;

#define print cout <<
#define read cin >>>

ModuleNarration::ModuleNarration(bool start_enabled) : Module(start_enabled)
{
}

ModuleNarration::~ModuleNarration()
{
}

bool ModuleNarration::Start()
{
	return true;
}

bool ModuleNarration::CleanUp()
{
	return true;
}


string ModuleNarration::WorldName()
{
	string world_name = app->world->wname;
	string op = "Your world name is " + toUppercase(world_name) + ".";


	nWorld = toUppercase(world_name);
	return op;
}

string ModuleNarration::WorldSky()
{
	string sky;

	Sky* nsky = app->world->wsky;
	bool seemoon = false, seesun = false;
	switch (nsky->GetVisibility())
	{
	case Sky::SkyVisibility::Visible:
		sky =  "Your world's sky is clear.";
		seemoon = true;
		seesun = true;
		break;
	case Sky::SkyVisibility::PartiallyVisible:
		sky = "Your world's sky is partially clear, the moon isn't visibile.";
		seemoon = false;
		seesun = true;
		break;
	case Sky::SkyVisibility::NonVisible:
		sky = "Your world's sky is hardly visbile.";
		seemoon = false;
		seesun = false;
		break;
	}

	if (nsky->IsMultimoon() && nsky->IsMultisun() && seemoon == true && seesun && true)
	{
		sky += "It has " + to_string(nsky->getNMoons()) + " moons and " + to_string(nsky->getNSuns())+ " suns.";
	}
	else if (nsky->IsMultimoon() && seemoon == true)
	{
		sky += "It has " + to_string(nsky->getNMoons()) + " moons.";
	}
	else if (nsky->IsMultisun() && seesun == true)
	{
		sky+= "It has " + to_string(nsky->getNSuns()) + " suns.";
	}

	if (nsky->isDaytimeRegular() == false)
	{
		if (nsky->GetDaytimeType() == Sky::DaytimeType::Months)
		{
			sky += "In your world, daytime lasts " + to_string(nsky->getdaytimeDuration()) + " months.";
		}
		else sky+= "In your world, daytime lasts " + to_string(nsky->getdaytimeDuration()) + " days.";
	}

	return sky;
}

string ModuleNarration::WorldClimate()
{
	Climate* nclimate = app->world->GetClimate();

	string climate = nWorld + " has climate: ";
	
	climate+= nclimate->GetWord() + ".";

	this->nClimate = nclimate->GetWord();

	return climate;
}

string ModuleNarration::WorldGeography()
{

	string Geography;

	for (vector<Geography::CellLand>::iterator it = app->world->geoVector.begin(); it != app->world->geoVector.end(); ++it)
	{
		switch ((*it).cardinal)
		{
		case Geography::CardinalPoints::NORTHWEST:
			Geography+= "\nNORTHWEST: \n";
			break;
		case Geography::CardinalPoints::NORTH:
			Geography += "\nNORTH: \n";
			break;
		case Geography::CardinalPoints::NORTHEAST:
			Geography += "\nNORTHEAST: \n";
			break;
		case Geography::CardinalPoints::WEST:
			Geography += "\nWEST: \n";
			break;
		case Geography::CardinalPoints::CENTER:
			Geography += "\nCENTER: \n";
			break;
		case Geography::CardinalPoints::EAST:
			Geography += "\nEAST: \n";
			break;
		case Geography::CardinalPoints::SOUTHWEST:
			Geography += "\nSOUTHWEST: \n";
			break;
		case Geography::CardinalPoints::SOUTH:
			Geography += "\nSOUTH: \n";
			break;
		case Geography::CardinalPoints::SOUTHEAST:
			Geography += "\nSOUTHEAST: \n";
			break;
		}
		switch ((*it).gtype)
		{
		case Geography::LandType::Water:
			Geography += "- It's mostly water.\n";
			break;
		case Geography::LandType::Land:
			Geography += "- It's mostly land.\n";
			break;
		}

		Geography::Place* place = nullptr;
		int repeat_place = 0;
		bool repeat = false;

		for (auto it2 = (*it).places.begin(); it2 != (*it).places.end(); ++it2)
		{
			if ((*it2)->has_name == true)
			{
				Geography += "There's a place called " + (*it2)->name + ".\n";
				
				if (!(*it2)->desc.empty())
				{
					switch ((ModuleNameGenerator::PlaceNameType)(*it2)->nametype)
					{
					case ModuleNameGenerator::PlaceNameType::OwnPlaceName:
						Geography += (*it2)->desc;
						break;
					case ModuleNameGenerator::PlaceNameType::ColorName:
						Geography += (*it2)->desc;
					}
				}
			}
			else
			{
				if (place != nullptr && place->location->GetWord() == (*it2)->location->GetWord())
				{
					repeat_place++;
				}
				else repeat = true;
			}
			
			if (place != nullptr && repeat_place == 0 && repeat == true && place->location->GetWord() != (*it2)->location->GetWord()) {
				Geography += "There's " + GetAorAn((*it2)->location->GetWord()) + " " + toLowercase((*it2)->location->GetWord()) + ".\n";
				repeat == false;
			}
			else
				if (place != nullptr && repeat_place > 0 && place->location->GetWord() != (*it2)->location->GetWord())
				{
					Geography += "There are " + to_string(repeat_place + 1) + " " + toLowercase(place->location->GetPlural()) + ".\n";
					repeat_place = 0;
				}			

			if((*it2)->has_name == false) 
			place = (*it2);
		}
		for (auto it3 = (*it).societies.begin(); it3 != (*it).societies.end(); ++it3)
		{
			switch ((*it3)->GetLocationPtr()->GetLocationType())
			{
			case Location::tCity:

				Geography += "There's a city named " + (*it3)->GetName() + ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					Geography += "- " + (*it3)->GetRaces()[i]->GetWord() + ".\n";
				break;
			case Location::tTown:

				Geography += "There's a town named " + (*it3)->GetName() + ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					Geography += "- " + (*it3)->GetRaces()[i]->GetWord() + ".\n";
				break;
			case Location::tPort:

				Geography += "There's a port named " + (*it3)->GetName() + ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					Geography += "- " + (*it3)->GetRaces()[i]->GetWord() + ".\n";
				break;
			case Location::tVillage:

				Geography += "There's a village named " + (*it3)->GetName() + ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					Geography += "- " + (*it3)->GetRaces()[i]->GetWord() + ".\n";
				break;
			}
		}
	}
	return Geography;
}

string ModuleNarration::WorldCharacters(Character * it)
{
	string Characters;


		Characters += "Name: \n";
		Characters += "Age: " + to_string((it)->GetAge()) +".\n";
		Characters += "Gender: ";
		
		switch ((it)->GetGender())
		{
		case Character::Male:
			Characters += "Male.\n";
			break;
		case Character::Female:
			Characters += "Female.\n";
			break;
		case Character::Femaletrans:
			Characters += "Trans Female.\n";
			break;
		case Character::Maletrans:
			Characters += "Trans Male.\n";
			break;
		case Character::Non_binary:
			Characters += "Non-binary.\n";
			break;
		default:
			break;
		}

		Characters += "Alignment: ";
		switch ((it)->GetAttitude())
		{
		case Character::AChaotic:
			Characters += "Chaotic ";
			break;
		case Character::ANeutral:
			Characters += "Neutral ";
			break;
		case Character::ALawful:
			Characters += "Neutral ";
			break;
		default:
			break;
		}
		switch ((it)->GetMorality())
		{
		case Character::MGood:
			Characters += "Good.\n";
			break;
		case Character::MNeutral:
			Characters += "Neutral.\n";
			break;
		case Character::MEvil:
			Characters += "Evil.\n";
			break;
		default:
			break;
		}

		Characters += "Archetype: ";
		switch ((it)->GetArchetype())
		{
		case Character::Busisnessman:
			Characters += "Bussinessman.\n";
			break;
		case Character::Protector:
			Characters += "Protector.\n";
			break;
		case Character::Recluse:
			Characters += "Recluse.\n";
			break;
		case Character::Fool:
			Characters += "Fool.\n";
			break;
		case Character::Casanova:
			Characters += "Casanova.\n";
			break;
		case Character::Revolutionary:
			Characters += "Revolutionary.\n";
			break;
		case Character::Artist:
			Characters += "Artist.\n";
			break;
		case Character::King:
			Characters += "King.\n";
			break;
		case Character::Seductress:
			Characters += "Seductress.\n";
			break;
		case Character::Amazon:
			Characters += "Amazon.\n";
			break;
		case Character::Daughter:
			Characters += "Daughter.\n";
			break;
		case Character::Matriarch:
			Characters += "Matriarch.\n";
			break;
		case Character::Nurturer:
			Characters += "Nurturer.\n";
			break;
		case Character::Maiden:
			Characters += "Maiden.\n";
			break;
		case Character::Mystic:
			Characters += "Mystic.\n";
			break;
		case Character::Martyr:
			Characters += "Martyr.\n";
			break;
		default:
			break;
		}

		Characters += "\n";
		
	return Characters;
}

string ModuleNarration::WorldCharactersArchetype(Character * cha)
{
	string Characters;

	switch ((cha)->GetArchetype())
	{
	case Character::Busisnessman:
		Characters += ArchetypeDesc[Character::Busisnessman *3];
		Characters += ArchetypeDesc[Character::Busisnessman * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Busisnessman * 3 + 2];
		break;
	case Character::Protector:
		Characters += ArchetypeDesc[Character::Protector * 3];
		Characters += ArchetypeDesc[Character::Protector * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Protector * 3 + 2];
		break;
	case Character::Recluse:
		Characters += ArchetypeDesc[Character::Recluse * 3];
		Characters += ArchetypeDesc[Character::Recluse * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Recluse * 3 + 2];
		break;
	case Character::Fool:
		Characters += ArchetypeDesc[Character::Fool * 3];
		Characters += ArchetypeDesc[Character::Fool * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Fool * 3 + 2];
		break;
	case Character::Casanova:
		Characters += ArchetypeDesc[Character::Casanova * 3];
		Characters += ArchetypeDesc[Character::Casanova * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Casanova * 3 + 2];
		break;
	case Character::Revolutionary:
		Characters += ArchetypeDesc[Character::Revolutionary * 3];
		Characters += ArchetypeDesc[Character::Revolutionary * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Revolutionary * 3 + 2];
		break;
	case Character::Artist:
		Characters += ArchetypeDesc[Character::Artist * 3];
		Characters += ArchetypeDesc[Character::Artist * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Artist * 3 + 2];
		break;
	case Character::King:
		Characters += ArchetypeDesc[Character::King * 3];
		Characters += ArchetypeDesc[Character::King * 3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::King * 3 + 2];
		break;
	case Character::Seductress:
		Characters += ArchetypeDesc[Character::Seductress *3];
		Characters += ArchetypeDesc[Character::Seductress *3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Seductress *3 + 2];
		break;
	case Character::Amazon:
		Characters += ArchetypeDesc[Character::Amazon *3];
		Characters += ArchetypeDesc[Character::Amazon*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Amazon*3 + 2];
		break;
	case Character::Daughter:
		Characters += ArchetypeDesc[Character::Daughter*3];
		Characters += ArchetypeDesc[Character::Daughter*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Daughter*3 + 2];
		break;
	case Character::Matriarch:
		Characters += ArchetypeDesc[Character::Matriarch*3];
		Characters += ArchetypeDesc[Character::Matriarch*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Matriarch*3 + 2];
		break;
	case Character::Nurturer:
		Characters += ArchetypeDesc[Character::Nurturer*3];
		Characters += ArchetypeDesc[Character::Nurturer*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Nurturer*3 + 2];
		break;
	case Character::Maiden:
		Characters += ArchetypeDesc[Character::Maiden*3];
		Characters += ArchetypeDesc[Character::Maiden*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Maiden*3 + 2];
		break;
	case Character::Mystic:
		Characters += ArchetypeDesc[Character::Mystic*3];
		Characters += ArchetypeDesc[Character::Mystic*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Mystic*3 + 2];
		break;
	case Character::Martyr:
		Characters += ArchetypeDesc[Character::Martyr*3];
		Characters += ArchetypeDesc[Character::Martyr*3 + 1];
		if (cha->GetShadow() == true)
		Characters += ArchetypeDesc[Character::Martyr*3 + 2];
		break;
	default:
		Characters += "this one is missing pls add";
		break;
	}

	return Characters;
}

string ModuleNarration::WorldCharactersGoal(Character *it)
{
	string cha;

	cha += "Goal: " + it->GetGoal();

	return cha;
}

string ModuleNarration::WorldCharactersFlaw(Character * it)
{
	string cha;

	cha += "Flaw: " + it->GetFlaw();

	return cha;
}

update_status ModuleNarration::Update()
{
	
	return UPDATE_CONTINUE;
}

bool ModuleNarration::StartsWithVowel(string word) {

	if (!word.empty())
	{
		switch (word.at(0)) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
		default:
			return false;
		}
	}
}

string ModuleNarration::GetAorAn(string word)
{
	if (StartsWithVowel(word))
		return "an";
	else return "a";
}
