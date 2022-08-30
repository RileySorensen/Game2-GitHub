#pragma once
#include "FrameWork/Component.h"
#include "Physic/Collision.h"
#include "Physic/PhysicsSystem.h"
#include <functional>
namespace Bogo
{
	class CollisionComponent : public Component, public ICollision
	{
	public:

		using functionPtr = std::function<void(Actor*)>;

		virtual void Update() override;

		virtual void Initialize() override;

		CLASS_DECLARATION(CollisionComponent)

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		void SetCollisionEnter(functionPtr function) { m_enterFunction = function; }
		void SetCollisionExit(functionPtr function) { m_exitFunction = function; }
		
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	private:
		PhysicsSystem::CollisionData data;

		functionPtr m_enterFunction;
		functionPtr m_exitFunction;
	};
}