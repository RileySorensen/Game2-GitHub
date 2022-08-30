#include "Model.h"
#include "../Core/File.h"
#include "../Core/Logger.h"
#include "Math/Transform.h"
#include <sstream>
#include <iostream>


namespace Bogo
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}
	bool Model::Create(std::string filename,...)
	{
		// could not load
		if (!Load(filename))
		{
			LOG("Error could not load model %s", filename.c_str());
			return false;
		}
		return true;
	}
	void Model::Draw(Renderer& renderer, const Vector2& position, float angle,const Vector2& scale)
	{
		/*Bogo::Color color;
		color.r = Bogo::random(256);
		color.g = Bogo::random(256);
		color.b = Bogo::random(256);
		color.a = 255;*/

		//draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			Bogo::Vector2 p1 = Vector2::Rotate((m_points[i] * scale),angle) + position;
			Bogo::Vector2 p2 = Vector2::Rotate( (m_points[i + 1] * scale),angle) + position;
			renderer.DrawLine(p1, p2, m_color);
		}
	}
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Matrix3x3 mx = transform.matrix;
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			Bogo::Vector2 p1 = mx * m_points[i];
			Bogo::Vector2 p2 = mx * m_points[i + 1];
			renderer.DrawLine(p1, p2, m_color);
		}
	}
	bool Model::Load(const std::string& filename)
	{
		std::string buffer;
		if (!Bogo::ReadFile(filename, buffer))
		{
			LOG("Error, Could not read file %s", filename);
			return false;
		}
		

		std::istringstream stream(buffer);
		stream >> m_color;

		std::string line;
		std::getline(stream, line);

		size_t numPoints = std::stoi(line);
		
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;

			m_points.push_back(point);
		}
		return true;
	}
	float Model::CalculateRadius()
	{
		float radius = 0;
		//find the largest length
		for (auto points : m_points)
		{
			if (points.Length() > radius) radius = points.Length();
		}

		return radius;
	}
}