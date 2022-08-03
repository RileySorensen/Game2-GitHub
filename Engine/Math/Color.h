#pragma once
#include <cstdint>
namespace Bogo
{
	//typedef unsigned char u8_t
	//using u8_t = unsigned char;
	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);
		std::string str;
		
		str = line.substr(line.find("{") + 1,line.find(",") - line.find("{") - 1);
		color.r = (uint8_t)(stof(str) * 255);

		str = line.substr(line.find(",") + 1, line.find_last_of(",") - line.find(",") - 1);
		color.g = (uint8_t)(stof(str) * 255);
		
		str = line.substr(line.find_last_of(",") + 1, line.find("}") - line.find_last_of(",") - 1);
		color.b = (uint8_t)(stof(str) * 255);


		color.a = 255;

		return stream;
	}
}

