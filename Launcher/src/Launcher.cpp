#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "LauncherLayer.h"




Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Launcher";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<LauncherLayer>();
	

	return app;
}