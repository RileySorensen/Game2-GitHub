#include "MyGame.h"
#include "GameComponent/EnemyComponent.h"
#include "Engine.h"

void MyGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);
	m_scene = std::make_unique<Bogo::Scene>();
	rapidjson::Document document;

	std::vector<std::string> sceneNames = { "scenes/prefabs.txt","scenes/tilemap.txt","scenes/level.txt" };

	for (auto& sceneName : sceneNames)
	{
		bool success = Bogo::json::Load(sceneName, document);
		if (!success)
		{
			LOG("could not load scene", sceneName.c_str());
			continue;
		}
		m_scene->Read(document);
	}
	m_scene->Initialize();

	
	Bogo::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnNotify, this, std::placeholders::_1));
	Bogo::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&MyGame::OnNotify, this, std::placeholders::_1));
}


void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	switch (m_gameState)
	{
	case MyGame::gameState::titleScreen:
		if (Bogo::g_inputSystem.GetKeyState(Bogo::key_space) == Bogo::InputSystem::State::Pressed)
		{
			m_gameState = gameState::startLevel;
		}
		break;
	case MyGame::gameState::startLevel:
		/*for (int i = 0; i < 5; i++)
		{
			auto actor = Bogo::Factory::Instance().Create<Bogo::Actor>("Coin");
			actor->m_transform.position = { Bogo::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}*/
		for (int i = 0; i < 3; i++)
		{
			auto actor = Bogo::Factory::Instance().Create<Bogo::Actor>("Ghost");
			actor->m_transform.position = { Bogo::randomf(500,600), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;
	case MyGame::gameState::game:
	{
		if (cooldown <= 0)
		{
			auto actor = Bogo::Factory::Instance().Create<Bogo::Actor>("Coin");
			actor->m_transform.position = { Bogo::randomf(100,1000), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
			cooldown = Bogo::random(100,200);
		}
		cooldown--;
		if (enemyCooldown <= 0)
		{
			auto actor = Bogo::Factory::Instance().Create<Bogo::Actor>("Ghost");
			actor->m_transform.position = { Bogo::randomf(500,600), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
			enemyCooldown = Bogo::random(300, 500);
		}
		enemyCooldown--;
		break;

	}
	case MyGame::gameState::playerDead:
		m_stateTimer -= Bogo::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = gameState::titleScreen;
		}
		break;

	case MyGame::gameState::gameOver:
		break;
	default:
		break;
	}
	m_scene->Update();
}

void MyGame::Draw(Bogo::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnNotify(const Bogo::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		addPoints(std::get<int>(event.data));
	}
	if (event.name == "EVENT_PLAYER_DEAD")
	{
		m_gameState = gameState::playerDead;
		m_stateTimer = 3;
	}
}


