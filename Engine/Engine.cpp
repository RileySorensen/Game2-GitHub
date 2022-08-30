#include "Engine.h"

namespace Bogo
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	Time g_time;
	AudioSystem g_audio;
	ResourceManager g_resources;
	PhysicsSystem g_physicsSystem;
	EventManger g_evenManager;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponents);
		REGISTER_CLASS(PlayerComponents);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(RBPhysicComponent);
		REGISTER_CLASS(TilemapComponent);
	}
}