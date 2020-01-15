#pragma once

#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include "Location.h"
#include "Adjective.h"

#include <string.h>
#include <iostream>


std::string toLowercase(std::string string);

std::string toUppercase(std::string string);

std::string AdjectiveandNameOutput(bool isCapitalized, bool allplural, Adjective* adjective, Location* name);

#endif //HELPER_FUNCTIONS_H