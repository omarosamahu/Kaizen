#pragma once
#include <Core.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Imp {
	class EXPORT Logger {
	public:
		void init();
		Logger();
		~Logger();
		//inline static std::shared_ptr<spdlog::logger>& coreLog() { return coreLogger; }
		//inline static std::shared_ptr<spdlog::logger>& clientLog() { return clientLogger; }
	private:
		 std::shared_ptr<spdlog::logger> coreLogger;
		 std::shared_ptr<spdlog::logger> clientLogger;
	};
}