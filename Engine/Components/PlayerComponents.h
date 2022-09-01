#pragma once
#include "FrameWork/Component.h"
#include "Physic/Collision.h"
#include "Component/CharacterComponent.h"
namespace Bogo
{
	class PlayerComponents : public CharacterComponent
	{
	public:
		PlayerComponents() = default;

		void Initialize() override;
		void Update();

		virtual void OnNotify(const Event& event) override;
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		CLASS_DECLARATION(PlayerComponents)

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float jump = 3000;
	};
}
