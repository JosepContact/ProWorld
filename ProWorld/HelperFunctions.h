#pragma once

#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include "Location.h"
#include "Adjective.h"
#include "Globals.h"

#include <string.h>
#include <iostream>


std::string toLowercase(std::string string);

std::string toUppercase(std::string string);

std::string AdjectiveandNameOutput(bool isCapitalized, bool allplural, Adjective* adjective, Location* name);

bool GetBoolByRandom(uint chance);

int GetRandomNumber(int min, int max);

#endif //HELPER_FUNCTIONS_H