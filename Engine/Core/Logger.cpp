#include "Logger.h"
#include <cstdarg>
#include <iostream>
namespace Bogo
{
	Logger g_logger;
	void Bogo::Logger::Log(const char* format, ...)
	{
		va_list args;
		va_start(args, format);

		char str[1024];
		vsprintf_s(str, 1024, format, args);

		std::cout << str << std::endl;

		va_end(args);
	}
}
