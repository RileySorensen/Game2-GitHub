#pragma once
#include "FrameWork/Game.h"
#include "FrameWork/Event.h"

class MyGame :public Bogo::Game
{
public:
	enum class gameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver,

	};
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(Bogo::Renderer& renderer) override;

	void OnAddPoints(const Bogo::Event& event_);
	void OnPlayerDead(const Bogo::Event& event_);
private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
};