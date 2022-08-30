#pragma once
#include "FrameWork/Component.h"
#include "Physic/Collision.h"
namespace Bogo
{
	class PlayerComponents : public Component, public ICollision
	{
	public:
		PlayerComponents() = default;

		void Initialize() override;
		void Update();

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		CLASS_DECLARATION(PlayerComponents)

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float speed = 0;

	};
}
