#include <iostream>
#include "Engine.h"

int main()
{
	std::cout << "Hello World" << std::endl;


	Bogo::InitializeMemory();
	Bogo::SetFilePath("../Assets");


	Bogo::g_renderer.Initialize();
	Bogo::g_inputSystem.Initialize();
	Bogo::g_audio.Initialize();

	Bogo::g_renderer.CreateWindow("Neumont", 1500, 1000);
	Bogo::g_renderer.setClearColor(Bogo::Color{ 0, 0, 0, 255 });

	std::shared_ptr<Bogo::Texture> texture = std::make_shared<Bogo::Texture>();
	texture->Create(Bogo::g_renderer,"sprite.bmp");


	bool quit = false;
	{
		while (!quit)
		{
			Bogo::g_time.Tick();
			Bogo::g_inputSystem.Update();
			Bogo::g_audio.Update();
			if (Bogo::g_inputSystem.GetKeyDown(Bogo::key_escape)) quit = true;


			Bogo::g_renderer.Beginframe();
			Bogo::g_renderer.Draw(texture, { 400,300 }, 0);
			Bogo::g_renderer.Endframe();
		}
	}
	Bogo::g_renderer.Shutdown();
	Bogo::g_audio.Shutdown();
}