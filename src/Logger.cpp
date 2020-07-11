#include <Logger.h>

namespace Imp {

	std::shared_ptr<spdlog::logger> Logger::coreLogger;
	std::shared_ptr<spdlog::logger> Logger::clientLogger;

	Logger::Logger() { std::cout << "Logger System Initilized\n"; }
	Logger::~Logger() { std::cout << "Logger Desturctor called\n"; }
	
	void Logger::init() {

		spdlog::set_pattern("%^[%T] %n: %v%$");
		coreLogger = spdlog::stdout_color_mt("Kaizen");
		coreLogger->set_level(spdlog::level::trace);
		
		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}
}