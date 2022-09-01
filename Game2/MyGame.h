#pragma once
#include "FrameWork/Game.h"
#include "FrameWork/Event.h"

class MyGame :public Bogo::Game, public Bogo::INotify
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
	virtual void OnNotify(const Bogo::Event& event) override;

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
	int cooldown = 0;
	int enemyCooldown = 0;
};