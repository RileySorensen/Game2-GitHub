#pragma once
#include "FrameWork/Component.h"
#include "Math/Vector2.h"
namespace Bogo
{
	class PhysicsComponents : public Component
	{
	public:
		PhysicsComponents() = default;
		void Update();
		virtual void ApplyForce(const Vector2& force) { Acceleration += force; }
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		CLASS_DECLARATION(PhysicsComponents)

		float dampening = 1;
		Vector2 Velocity = 0;
		Vector2 Acceleration = 0;
	private:

	};
}