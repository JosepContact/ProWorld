#include "HelperFunctions.h"
#include "Globals.h"
#include "App.h"
#include <algorithm>

using namespace std;

string toLowercase(string str)
{
	string ret = str;
	
	std::for_each(ret.begin(), ret.begin() + 1, [](char &c)
	{	c = ::tolower(c);
	});

	return ret;
}

string toUppercase(string str)
{
	string ret = str;

	std::for_each(ret.begin(), ret.begin() + 1, [](char &c)
	{	c = ::toupper(c);
	});

	return ret;
}

std::string AdjectiveandNameOutput(bool isCapitalized, bool allplural, Adjective * adjective, Location * name)
{
	string ret;

	if (adjective != nullptr && name != nullptr)
	{
		if (isCapitalized)
			ret += toUppercase(adjective->GetString());
		else ret += toLowercase(adjective->GetString());

		if (adjective->GetToPlural() || allplural)
			ret += ' ' + toLowercase(name->GetPlural());
		else ret += ' ' + toLowercase(name->GetString());
	}
	else {
		LOG("ERROR: Location or Adjective pointer was NULL at AdjectiveandNameOutput func on HelperFunctions.cpp");
		return ret;
	}

	return ret;
}

