#include "PlayerComponents.h"
#include "Engine.h"
#include "../Input/InputSystem.h"
#include <iostream>
#include "../FrameWork/Actor.h"

void Bogo::PlayerComponents::Initialize()
{
	CharacterComponent::Initialize();
}

void Bogo::PlayerComponents::Update()
{
	
	float thrust = 0;
	Bogo::Vector2 direction{ 0,0 };
	//update transform with input

	if (g_inputSystem.GetKeyDown(key_up))
	{
		thrust = speed;
	}
	if (g_inputSystem.GetKeyDown(key_right))
	{
		if (g_inputSystem.GetKeyState(key_sprint) == InputSystem::State::Held && g_inputSystem.GetKeyState(key_right) == InputSystem::State::Held)
		{
			direction = Vector2::right * 1.5;
		}
		else
		{
			direction = Vector2::right;
		}
	}
	
	
	if (g_inputSystem.GetKeyDown(key_left))
	{
		if (g_inputSystem.GetKeyState(key_sprint) == InputSystem::State::Held && g_inputSystem.GetKeyState(key_left) == InputSystem::State::Held)
		{
			direction = Vector2::left * 1.5;
		}
		else
		{
		direction = Vector2::left;
		}
	}
	Vector2 velocityx;

	auto component = m_owner->GetComponent<PhysicsComponents>();
	if (component)
	{
		component->ApplyForce(direction * speed);
		velocityx = component->Velocity;
	}
	
	Vector2 velocity;
	if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
	{
		auto component = m_owner->GetComponent<PhysicsComponents>();
		if (component)
		{
			component->ApplyForce(Vector2::up * 700);
		}
	}
	auto renderComponent = m_owner->GetComponent<RenderComponent>();
	if (renderComponent)
	{
		if (velocity.x != 0) renderComponent->setFlipHorizontal(velocity.x < 0);
	}
}

void Bogo::PlayerComponents::OnCollisionEnter(Actor* other)
{
	if (other->GetName() == "Coin")
	{
		Event event_;
		event_.name = "EVENT_ADD_POINTS";
		event_.data = 100;

		g_eventManager.Notify(event_);
		other->setDestroy();
	}
	if (other->GetTag() == "Enemy")
	{
		Event event_;
			event_.name = "EVENT_DAMAGE";
			event_.data = damage;
			event_.receiver = other;
			g_eventManager.Notify(event_);
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
	CharacterComponent::Read(value);

	READ_DATA(value, jump);

	return true;
}

void Bogo::PlayerComponents::OnNotify(const Event& event)
{
	if (event.name == "EVENT_DAMAGE")
	{
		health -= std::get<float>(event.data);
		if (health <= 0)
		{
			m_owner->setDestroy();
			Event event;
			event.name = "EVENT_PLAYER_DEAD";

			g_eventManager.Notify(event);
		}
	}
}
