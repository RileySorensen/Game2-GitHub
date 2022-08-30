#include "RBPhysicsComponent.h"
#include "Physic/PhysicsSystem.h"
#include "Engine.h"
namespace Bogo
{
	RBPhysicComponent::~RBPhysicComponent()
	{
		if(m_body) g_physicsSystem.DestroyBody(m_body);
	}
	void RBPhysicComponent::Initialize()
	{
		m_body = g_physicsSystem.CreateBody(m_owner->m_transform.position, m_owner->m_transform.rotation, data);
		m_body->SetGravityScale(data.gravity_scale);
		m_body->SetLinearDamping(dampening);
	}
	void RBPhysicComponent::Update()
	{
		Vector2 position = B2VEC2_TO_VECTOR2(m_body->GetPosition());
		m_owner->m_transform.position = PhysicsSystem::WorldToScreen(position);
		m_owner->m_transform.rotation = m_body->GetAngle();
	}
	void RBPhysicComponent::ApplyForce(const Vector2& force)
	{
		b2Vec2 v{ force.x, force.y };
		m_body->ApplyForceToCenter(VECTOR2_TO_B2VEC2(force), true);
	}
	bool RBPhysicComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool RBPhysicComponent::Read(const rapidjson::Value& value)
	{
		PhysicsComponents::Read(value);
		READ_DATA(value, data.gravity_scale);
		READ_DATA(value, data.constrain_angle);
		READ_DATA(value, data.is_dynamic);

		return true;
	}
}
