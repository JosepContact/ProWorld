#pragma once

#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include "pugixml-1.10\src\pugixml.hpp"

#define NULL 0
// Deletes a buffer
#define RELEASE( x ) \
    {                        \
    if( x != NULL )        \
	    {                      \
      delete x;            \
	  x = NULL;              \
	    }                      \
    }
#define ORGANIZATION_NAME "Managicality"
#define APP_NAME "ProWorld 0.1"



class FileSystem
{
public:

	FileSystem();

	// Destructor
	virtual ~FileSystem();

	// Called before quitting
	bool CleanUp();

private:

};

#endif // __FILESYSTEM_H__
