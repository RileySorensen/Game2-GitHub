#pragma once

#include "../Components/RenderComponent.h"

namespace Bogo
{
	class Model;
	class ModelComponent : public RenderComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		CLASS_DECLARATION(ModelComponent)

		std::shared_ptr<Model> m_model;

		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}