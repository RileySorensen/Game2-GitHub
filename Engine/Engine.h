#pragma once
#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Components/PlayerComponents.h"
#include "Components/SpriteComponent.h"
#include "Component/AudioComponents.h"
#include "Component/Physic Component.h"
#include "Component/ModelComponent.h"
#include "Component/SpriteAnimComponent.h"
#include "Component/CollisionComponent.h"
#include "Component/TilemapComponent.h"
#include "Component/CharacterComponent.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Singleton.h"
#include "FrameWork/Factory.h"
#include "FrameWork/Actor.h"
#include "FrameWork/EventManager.h"
#include "FrameWork/GameObject.h"

#include "Serialization/JSON.h"

#include "Physic/PhysicsSystem.h"

#include "Component/RBPhysicsComponent.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Audio/AudioSystems.h"
#include "Resource/ResourceManager.h"
#include <iostream>
namespace Bogo
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audio;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManger g_eventManager;
	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}
