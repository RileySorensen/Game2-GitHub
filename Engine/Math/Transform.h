#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"
#include "Math/MathUtils.h"
#include "Serialization/Serializable.h"

namespace Bogo
{
	struct Transform : public ISerializable
	{
		Vector2 position;
		float rotation{0};
		Vector2 scale{1,1};
		Matrix3x3 matrix;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Update()
		{
			Matrix3x3 mxScale = Matrix3x3::Createscale(scale);
			Matrix3x3 mxRotation = Matrix3x3::Createrotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::Createtranslation(position);

			matrix = {mxTranslation * mxScale * mxRotation};
		}

		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxScale = Matrix3x3::Createscale(scale);
			Matrix3x3 mxRotation = Matrix3x3::Createrotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::Createtranslation(position);

			matrix = { mxTranslation * mxScale * mxRotation};
			matrix = parent * matrix;
		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::Createscale(scale);
			Matrix3x3 mxRotation = Matrix3x3::Createrotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::Createtranslation(position);

			return { mxTranslation * mxScale * mxRotation };
		}		
	};
}
