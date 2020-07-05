#include <Logger.h>

namespace Imp {
	Logger::Logger() { std::cout << "Logger System Initilized\n"; }
	Logger::~Logger() { std::cout << "Logger Desturctor called\n"; }
}