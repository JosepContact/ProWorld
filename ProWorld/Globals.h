#pragma once

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

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

#endif //GLOBALS_H
