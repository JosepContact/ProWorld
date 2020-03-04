#include "ModuleGraphics.h"
#include "App.h"

#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include <GL/gl3w.h>    // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#include <GL/glew.h>    // Initialize with glewInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include <glad/glad.h>  // Initialize with gladLoadGL()
#else
#include IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#endif

#include <GLFW/glfw3.h>

using namespace std;

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

ModuleGraphics::ModuleGraphics(bool start_enabled)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
	{
		LOG("glfwInit() error!");
		return;
	}

#if __APPLE__
		// GL 3.2 + GLSL 150
		glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
// GL 3.0 + GLSL 130
 glsl_version = "#version 130";
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

	// Create window with graphics context
window = glfwCreateWindow(1400, 900, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
if (window == NULL)
{
	LOG("window was Null!");
	return;
}
glfwMakeContextCurrent(window);
glfwSwapInterval(1); // Enable vsync

// Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
bool err = gl3wInit() != 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
bool err = glewInit() != GLEW_OK;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
bool err = gladLoadGL() == 0;
#else
bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
	if (err)
	{
		LOG("Failed to initialize OpenGL loader!\n");
		return;
	}
}

ModuleGraphics::~ModuleGraphics()
{
	//RELEASE(window);
}

bool ModuleGraphics::Start()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	if(glsl_version!= nullptr)
	ImGui_ImplOpenGL3_Init(glsl_version);

	return true;
}

bool ModuleGraphics::CleanUp()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return true;
}

update_status ModuleGraphics::Update()
{

		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//if (show_demo_window)
			//ImGui::ShowDemoWindow(&show_demo_window);

		//show settings in the top left corner
		{
			if(ImGui::BeginMainMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if(ImGui::MenuItem("New")) 
					{
						create_world = true;
						show_world = false;
					}
					if (ImGui::MenuItem("Load")) {
					}
					if (ImGui::MenuItem("Save")) {
					}
					if (ImGui::MenuItem("Quit")) {
					}
					ImGui::EndMenu();
				}
				ImGui::EndMainMenuBar();
			}
		}

		// Start App Window
		if (show_world == false){
			ImGui::SetNextWindowPos(ImVec2(500, 150));
			ImGui::SetNextWindowSize(ImVec2(520, 220));

		ImGui::Begin("ProWorld 0.1");

		ImGui::Text("Welcome to ProWorld version 0.1.");
		ImGui::Text("This application was created to simulate proceduarlly generated worlds\n in a narrated fashion.");
		ImGui::Text("Fantasy worlds created with this program are converted into - so called\n - world bibles."); 
		ImGui::Text("These, hold information about pretty much every important aspect that the\n creator thinks important for a story - from the main characters ideals,\n to each race living in most cities involving the action.");
		ImGui::Separator();
		if (ImGui::Button("Create me a world!"))
		{
			show_world = true;
		}
		ImGui::End();
		}
		//Let's create our small intro world.

		else if(show_world == true) {

			ImGui::Begin("WORLD");
			ImGui::Text(app->narration->WorldName().c_str()); // Print World Name
			ImGui::Separator();
			ImGui::Text(app->narration->WorldSky().c_str());
			ImGui::Text(app->narration->WorldClimate().c_str());
			ImGui::Separator();
			ImGui::Text("GEOGRAPHY");
			ImGui::Text(app->narration->WorldGeography().c_str());
			ImGui::End();
		}

		if (show_world == true) {
			ImGui::Begin("CHARACTERS");
			//ImGui::Separator();
			for (auto it = app->world->wcharacters.begin(); it != app->world->wcharacters.end(); ++it)
			{
				ImGui::Text(app->narration->WorldCharacters((*it)).c_str());			
				ImGui::Text(app->narration->WorldCharactersArchetype((*it)).c_str());
				ImGui::BulletText(app->narration->WorldCharactersGoal((*it)).c_str());
				ImGui::BulletText(app->narration->WorldCharactersFlaw((*it)).c_str());
				ImGui::BulletText(app->narration->WorldCharactersOrigin((*it)).c_str());
				ImGui::BulletText(app->narration->WorldCharactersRace((*it)).c_str());
				ImGui::Separator();
			}
			
			
			ImGui::End();
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);


		if (glfwWindowShouldClose(window))
			app->quit = true;

		return UPDATE_CONTINUE;
}
