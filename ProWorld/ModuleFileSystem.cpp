#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

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

unsigned int ModuleFileSystem::Load(const char * path, char ** buffer)
{
	unsigned int ret = 0;

	if (path == nullptr)
		return ret;

	ofstream;
	FILE* load_file = fopen(path, "rb");

	if (load_file)
	{
		int size = 0;

		ifstream in(path, ifstream::ate | ifstream::binary);
		size = in.tellg();

		if (size > 0)
		{
			*buffer = new char[size];
			unsigned int read = (unsigned int)fread(*buffer, sizeof(char), size, load_file);
			if (read != size)
			{
				//LOG("ERROR while reading file:\n\t%s", path);
				if (*buffer != nullptr)
					delete[] *buffer;
			}
			else
			{
				ret = read;
			}
		}
		/*if (fclose(load_file) != 0)
		{
			LOG("ERROR ehile opening file:\n\t%s\n\t%s", path, strerror(errno));
		}*/
	}
	/*else
	{
		LOG("ERROR while opening file:\n\t%s\n\t%s", path, strerror(errno));
	}*/


	return ret;
}

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
		// FOR LATER
		// LOG("ERROR Creating Directory %s[%s]", folder_name, strerror(errno));
		return ret;
	}

	ret = fldrPath + '\\';

	return ret;
}
