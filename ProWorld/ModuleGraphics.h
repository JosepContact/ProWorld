#pragma once

#ifndef MODULEGRAPHICS_H
#define MODULEGRAPHICS_H

#include "Module.h"


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>


class ModuleGraphics : public Module {
public:
	ModuleGraphics(bool start_enabled = true);

	virtual ~ModuleGraphics();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();

public:

	GLFWwindow* window = nullptr;
	const char* glsl_version = nullptr;

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	bool new_world = false;
};

#endif // !MODULEGRAPHICS

