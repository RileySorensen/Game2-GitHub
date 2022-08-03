#pragma once
#include "Renderer.h"
#include <vector>
#include <string>
namespace Bogo
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<Bogo::Vector2>& points, const Bogo::Color& color) : 
			m_points{points},
			m_color{ color }{}

		Model(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2& position, float angle, const float& scale = 1);

		void Load(const std::string& filename);
		float CalculateRadius();
		
		float GetRadius() { return m_radius; }

	private:
		Bogo::Color m_color{ 0,0,0,0 }; 
		std::vector<Bogo::Vector2> m_points;
		float m_radius = 0;
	};
}