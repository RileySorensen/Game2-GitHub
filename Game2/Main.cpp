#include "Engine.h"
#include "MyGame.h"
#include <iostream>

int main()
{
	Bogo::InitializeMemory();
	Bogo::SetFilePath("../Assets");



	Bogo::g_renderer.Initialize();
	Bogo::g_inputSystem.Initialize();
	Bogo::g_audio.Initialize();
	Bogo::g_resources.Initialize();
	Bogo::g_physicsSystem.Initialize();
	Bogo::g_evenManager.Initialize();

	Bogo::Engine::Instance().Register();

	Bogo::g_renderer.CreateWindow("Bogomont", 1500, 1000);
	Bogo::g_renderer.setClearColor(Bogo::Color{ 0, 0, 0, 255 });

	std::unique_ptr<MyGame> game = std::make_unique<MyGame>();
	game->Initialize();
	float angle = 0;

	bool quit = false;
	{
		while (!quit)
		{
			Bogo::g_time.Tick();
			Bogo::g_inputSystem.Update();
			Bogo::g_audio.Update();
			Bogo::g_physicsSystem.Update();

			if (Bogo::g_inputSystem.GetKeyDown(Bogo::key_escape)) quit = true;

			game->Update();

			Bogo::g_renderer.Beginframe();
			game->Draw(Bogo::g_renderer);
			Bogo::g_renderer.Endframe();
		}
	}
	game->Shutdown();
	Bogo::Factory::Instance().Shutdown();
	Bogo::g_renderer.Shutdown();
	Bogo::g_audio.Shutdown();
	Bogo::g_evenManager.Shutdown();
}