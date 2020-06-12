#pragma once

#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include "Location.h"
#include "Adjective.h"
#include "Globals.h"

#include <string.h>
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <algorithm>
#include <stdlib.h>


inline std::string toLowercase(std::string string);

inline std::string toUppercase(std::string string);

std::string AdjectiveandNameOutput(bool isCapitalized, bool allplural, Adjective* adjective, Location* name);

inline bool GetBoolByRandom(uint chance)
{
	int a = (rand() % 100 + 1);

	return ((rand() % 100 + 1) < chance);
}

inline int GetRandomNumber(int min, int max)
{
	int ret = 0;

	ret = rand() % (max + 1 - min) + min;
	return ret;
}

#endif //HELPER_FUNCTIONS_H