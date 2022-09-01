#pragma once
#pragma once
#include "Component/CharacterComponent.h"

	class EnemyComponent : public Bogo::CharacterComponent
	{
	public:
		CLASS_DECLARATION(EnemyComponent)

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Bogo::Actor* other) override;
		virtual void OnCollisionExit(Bogo::Actor* other) override;

		virtual void OnNotify(const Bogo::Event& event) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	protected:

		int speedBoostTimer = 100;

	};
