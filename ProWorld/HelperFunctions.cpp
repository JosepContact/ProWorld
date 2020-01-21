#include "HelperFunctions.h"
#include "Globals.h"
#include "App.h"

#include <cstdlib>
#include <ctime>
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
			ret += toUppercase(adjective->GetWord());
		else ret += toLowercase(adjective->GetWord());

		if (adjective->GetToPlural() || allplural)
			ret += ' ' + toLowercase(name->GetPlural());
		else ret += ' ' + toLowercase(name->GetWord());
	}
	else {
		LOG("ERROR: Location or Adjective pointer was NULL at AdjectiveandNameOutput func on HelperFunctions.cpp");
		return ret;
	}

	return ret;
}

bool GetBoolByRandom(uint chance)
{
	srand((int)time(0));
	
	int a = (rand() % 100 + 1);
	
	return ((rand() % 100 + 1) < chance);
}

int GetRandomNumber(int min, int max)
{
	if (max < 1) return 0;

	srand((int)time(0));

	if (max != 1)
		return ((rand() % (max - 1)) + min);
	else if (max == 1)
		return ((rand() % (max)));
}

