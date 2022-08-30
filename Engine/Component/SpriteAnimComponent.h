#pragma once
#include "Components/RenderComponent.h"
#include "Math/Rect.h"
namespace Bogo
{
	class Texture;

	class SpriteAnimComponent : public RenderComponent
	{
	public:
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		Rect& GetSource() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		CLASS_DECLARATION(SpriteAnimComponent)

	public:
		float fps = 0;
		int num_columns = 0;
		int num_rows = 0;

		int start_frame;
		int end_frame;

		int frame = 0;
		float frameTimer = 0;

		Rect source;
		std::shared_ptr<Texture> m_texture;
	};
}

