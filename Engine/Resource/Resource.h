#pragma once
#include <string>
namespace Bogo
{
	class Resource
	{
	public:
		virtual bool Create(std::string name,...) = 0;
	};
}
