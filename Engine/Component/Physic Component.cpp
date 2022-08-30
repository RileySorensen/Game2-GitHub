#include "Physic Component.h"
#include "Engine.h"
namespace Bogo
{
	void Bogo::PhysicsComponents::Update()
	{
		Velocity += Acceleration * g_time.deltaTime;
		m_owner->m_transform.position += Velocity * g_time.deltaTime;
		Velocity *= dampening;

		Acceleration = Vector2::zero;

	}

	bool PhysicsComponents::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PhysicsComponents::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, dampening);
		return true;
	}

}