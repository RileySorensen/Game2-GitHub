#include "Transform.h"

bool Bogo::Transform::Write(const rapidjson::Value& value) const
{

    return true;
}

bool Bogo::Transform::Read(const rapidjson::Value& value)
{
    READ_DATA(value, position);
    READ_DATA(value, scale);
    READ_DATA(value, rotation);

    return true;
}
