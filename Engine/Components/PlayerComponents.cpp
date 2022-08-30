#include "PlayerComponents.h"
#include "Engine.h"
#include "../Input/InputSystem.h"
#include <iostream>
#include "../FrameWork/Actor.h"

void Bogo::PlayerComponents::Initialize()
{
	auto component = m_owner->GetComponent<CollisionComponent>();
	if (component)
	{
		component->SetCollisionEnter(std::bind(&PlayerComponents::OnCollisionEnter, this, std::placeholders::_1));
		component->SetCollisionExit(std::bind(&PlayerComponents::OnCollisionExit, this, std::placeholders::_1));
	}
}

void Bogo::PlayerComponents::Update()
{
	
	float thrust = 0;
	Bogo::Vector2 direction{ 1,0 };
	//update transform with input

	if (g_inputSystem.GetKeyDown(key_up))
	{
		thrust = speed;
	}
	if (g_inputSystem.GetKeyDown(key_right))
	{
		direction = Vector2::right;
	}
	if (g_inputSystem.GetKeyDown(key_left))
	{
		direction = Vector2::left;
	}
	auto component = m_owner->GetComponent<PhysicsComponents>();
	if (component)
	{
		component->ApplyForce(direction * speed);
	}
	

	if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
	{
		auto component = m_owner->GetComponent<PhysicsComponents>();
		if (component)
		{
			component->ApplyForce(Vector2::up * 30);
		}
	}
}

void Bogo::PlayerComponents::OnCollisionEnter(Actor* other)
{
	if (other->GetName() == "Coin")
	{
		Event event_;
		event_.name = "EVENT_ADD_POINTS";
		event_.data = 100;

		g_evenManager.Notify(event_);
		other->setDestroy();
	}
}

void Bogo::PlayerComponents::OnCollisionExit(Actor* other)
{
	std::cout << "player exit\n";
}

bool Bogo::PlayerComponents::Write(const rapidjson::Value& value) const
{
	return true;
}

bool Bogo::PlayerComponents::Read(const rapidjson::Value& value)
{
	READ_DATA(value, speed);

	return true;
}
