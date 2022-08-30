#include "MyGame.h"
#include "Engine.h"

void MyGame::Initialize()
{
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

	
	Bogo::g_evenManager.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnAddPoints, this, std::placeholders::_1));
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
		for (int i = 0; i < 20; i++)
		{
			auto actor = Bogo::Factory::Instance().Create<Bogo::Actor>("Coin");
			actor->m_transform.position = { Bogo::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		break;
	case MyGame::gameState::game:
		break;
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

void MyGame::OnAddPoints(const Bogo::Event& event_)
{
	addPoints(std::get<int>(event_.data));

	std::cout << event_.name << std::endl;

	std::cout << std::get<int>(event_.data) << std::endl;
	std::cout << GetScore() << std::endl;
}

void MyGame::OnPlayerDead(const Bogo::Event& event_)
{
	m_gameState = gameState::playerDead;
	m_stateTimer = 3;
}
