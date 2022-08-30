#pragma once
#include "Physic Component.h"
#include "Physic/PhysicsSystem.h"

#define VECTOR2_TO_B2VEC2(vec) (*(b2Vec2*)(&vec))
#define B2VEC2_TO_VECTOR2(vec) (*(Bogo::Vector2*)(&vec))
namespace Bogo
{
	class RBPhysicComponent : public PhysicsComponents
	{
	public:
		RBPhysicComponent() = default;
		~RBPhysicComponent();

		void Initialize() override;
		void Update() override;
		virtual void ApplyForce(const Vector2& force);
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		CLASS_DECLARATION(RBPhysicComponent)

		friend class CollisionComponent;

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body = nullptr;
	};
}