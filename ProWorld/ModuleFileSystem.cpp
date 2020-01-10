#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

#include "App.h"
#include "ModuleFileSystem.h"
#include "PhysFS/include/physfs.h"

#pragma comment( lib, "PhysFS/libx86/physfs.lib" )

using namespace std;

ModuleFileSystem::ModuleFileSystem(bool start_enabled) : Module(start_enabled)
{
	name = "FileSystem";
}

ModuleFileSystem::~ModuleFileSystem()
{
}

bool ModuleFileSystem::CleanUp()
{
	return true;
}

bool ModuleFileSystem::Start()
{
	//CreateFolder("", "Concepts");
	return true;
}

unsigned int ModuleFileSystem::Load(const char * path, char ** buffer) const
{
	unsigned int ret = 0;

	if (path == nullptr)
		return ret;

	//ofstream;
	FILE* load_file = fopen(path, "rb");

	if (load_file)
	{
		int size = 0;

		ifstream in(path, ifstream::ate | ifstream::binary);
		size = in.tellg();

		if (size > 0)
		{
			*buffer = new char[(unsigned int)size];
			unsigned int read = (unsigned int)fread(*buffer, sizeof(char), size, load_file);
			if (read != size)
			{
				LOG("ERROR while reading file:\n\t%s \n", path);
				if (*buffer != nullptr)
					RELEASE(*buffer);
			}
			else
			{
				ret = (unsigned int)read;
			}
		}
		if (fclose(load_file) != 0)
		{
			LOG("ERROR while opening file:\n\t%s\n\t%s \n", path, strerror(errno));
		}
	}
	else
	{
		LOG("ERROR while opening file:\n\t%s\n\t%s \n", path, strerror(errno));
	}


	return ret;
}
/*
unsigned int ModuleFileSystem::Load(const char* file, char** buffer) const
{
	unsigned int ret = 0;

	PHYSFS_file* fs_file = PHYSFS_openRead(file);

	if (fs_file != NULL)
	{
		PHYSFS_sint64 size = PHYSFS_fileLength(fs_file);

		if (size > 0)
		{
			*buffer = new char[(unsigned int)size];
			PHYSFS_sint64 read = PHYSFS_read(fs_file, *buffer, 1, (PHYSFS_sint32)size);
			if (read != size)
			{
				LOG("File System error while reading from file %s: %s\n", file, PHYSFS_getLastError());
				RELEASE(buffer);
			}
			else
				ret = (unsigned int)read;
		}

		if (PHYSFS_close(fs_file) == 0)
			LOG("File System error while closing file %s: %s\n", file, PHYSFS_getLastError());
	}
	else
		LOG("File System error while opening file %s: %s\n", file, PHYSFS_getLastError());

	return ret;
}*/

string ModuleFileSystem::CreateFolder(const char * path, const char * folder_name)
{
	string ret;

	string fldrPath = path;
	if (fldrPath.length() > 0 && fldrPath[fldrPath.length() - 1] != '\\')
	{
		fldrPath += '\\';
	}
	fldrPath += folder_name;

	if (CreateDirectory(fldrPath.c_str(), NULL) == 0)
	{
		LOG("ERROR Creating Directory %s[%s] \n", folder_name, strerror(errno));
		return ret;
	}

	ret = fldrPath + '\\';

	return ret;
}

pugi::xml_node ModuleFileSystem::LoadXML(const char * filename, const char* child, pugi::xml_document & file) const
{
	pugi::xml_node ret;

	char* buf = NULL;
	unsigned int size = Load(filename, &buf);
	pugi::xml_parse_result result = file.load_buffer(buf, size);
	RELEASE(buf);

	if (result == NULL) 
	{
		LOG("Could not load map xml file. pugi error: %s \n", result.description());
	}
	else
		ret = file.child(child);

	/*if (result != NULL)
	{
		ret = file.child(child);
	}*/

	return ret;
}
