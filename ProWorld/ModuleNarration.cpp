#include "ModuleNarration.h"
#include "HelperFunctions.h"
#include "App.h"
#include "Geography.h"

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
		for (auto it2 = (*it).places.begin(); it2 != (*it).places.end(); ++it2)
		{
			if ((*it2)->has_name == true)
			{
				Geography += "There's a place called " + (*it2)->name + ".\n";
			}
			else
			{
				Geography += "There's a " + (*it2)->name + ".\n";
			}

			if ((*it2)->location->GetWord() == "City") {
				//print "It's a city named " << 
			}
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

update_status ModuleNarration::Update()
{
	// ----- START -----
	/*
	string input;

	do {
		cout << "Would you like to start a new world?\n";
		cout << "(Input yes/y to start a world)\n";
		cout << "(Input no/n to close the application)\n";

		cin >> input;

		if (input == "n" || input == "no")
			return UPDATE_STOP;

	} while (input != "n" && input != "no" && input != "yes" && input != "y");

	cout << "\n";
	cout << "Let's begin!\n\n";
	app->world->StartWorld();

	Sky* nsky = app->world->wsky;
	bool seemoon = false, seesun = false;
	switch (nsky->GetVisibility())
	{
	case Sky::SkyVisibility::Visible:
		print "\nYour world's sky is clear.\n";
		seemoon = true;
		seesun = true;
		break;
	case Sky::SkyVisibility::PartiallyVisible:
		print "Your world's sky is partially clear, the moon isn't visibile.\n";
		seemoon = false;
		seesun = true;
		break;
	case Sky::SkyVisibility::NonVisible:
		print "Your world's sky is hardly visbile.";
		seemoon = false;
		seesun = false;
		break;
	}

	if (nsky->IsMultimoon() && nsky->IsMultisun() && seemoon == true && seesun && true)
	{
		print "The sky has " << nsky->getNMoons() << " moons and " << nsky->getNSuns() << " suns.";
	}
	else if (nsky->IsMultimoon() && seemoon == true)
	{
		print "The sky has " << nsky->getNMoons() << " moons.";
	}
	else if (nsky->IsMultisun() && seesun == true)
	{
		print "The sky has " << nsky->getNSuns() << " suns.";
	}

	if (nsky->isDaytimeRegular() == false)
	{
		if (nsky->GetDaytimeType() == Sky::DaytimeType::Months)
		{
			print "In your world, daytime lasts " << nsky->getdaytimeDuration() << " months.";
		}
		else print "In your world, daytime lasts " << nsky->getdaytimeDuration() << " days.";
	}

	Climate* nclimate = app->world->wclimate;

	print "\n";
	print "Your world has climate: " << nclimate->GetWord() << "\n";

	print "\n";

	for (vector<Geography::CellLand>::iterator it = app->world->geoVector.begin(); it != app->world->geoVector.end(); ++it)
	{
		switch ((*it).cardinal)
		{
		case Geography::CardinalPoints::NORTHWEST:
			print "\nNORTHWEST: \n";
			break;
		case Geography::CardinalPoints::NORTH:
			print "\nNORTH: \n";
			break;
		case Geography::CardinalPoints::NORTHEAST:
			print "\nNORTHEAST: \n";
			break;
		case Geography::CardinalPoints::WEST:
			print "\nWEST: \n";
			break;
		case Geography::CardinalPoints::CENTER:
			print "\nCENTER: \n";
			break;
		case Geography::CardinalPoints::EAST:
			print "\nEAST: \n";
			break;
		case Geography::CardinalPoints::SOUTHWEST:
			print "\nSOUTHWEST: \n";
			break;
		case Geography::CardinalPoints::SOUTH:
			print "\nSOUTH: \n";
			break;
		case Geography::CardinalPoints::SOUTHEAST:
			print "\nSOUTHEAST: \n";
			break;
		}
		switch ((*it).gtype)
		{
		case Geography::LandType::Water:
			print "- It's mostly water.\n";
			break;
		case Geography::LandType::Land:
			print "- It's mostly land.\n";
			break;
		}
		for (auto it2 = (*it).locations.begin(); it2 != (*it).locations.end(); ++it2)
		{
			print "There's a " << (*it2)->GetWord() << ".\n";

			if ((*it2)->GetWord() == "City") {
				//print "It's a city named " << 
			}
		}
		for (auto it3 = (*it).societies.begin(); it3 != (*it).societies.end(); ++it3)
		{
			switch ((*it3)->GetLocationPtr()->GetLocationType())
			{
			case Location::tCity:

				print "There's a city named " << (*it3)->GetName() << ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					print "- " << (*it3)->GetRaces()[i]->GetWord() << ".\n";
				break;
			case Location::tTown:

				print "There's a town named " << (*it3)->GetName() << ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					print "- " << (*it3)->GetRaces()[i]->GetWord() << ".\n";
				break;
			case Location::tPort:

				print "There's a port named " << (*it3)->GetName() << ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					print "- " << (*it3)->GetRaces()[i]->GetWord() << ".\n";
				break;
			case Location::tVillage:

				print "There's a village named " << (*it3)->GetName() << ".\nThe following races live in it:\n";
				for (int i = 0; i < (*it3)->GetRaces().size(); i++)
					print "- " << (*it3)->GetRaces()[i]->GetWord() << ".\n";
				break;
			}
		}
	}

	getchar();*/
	return UPDATE_CONTINUE;
}
