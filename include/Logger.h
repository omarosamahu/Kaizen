#pragma once
#include <Core.h>


namespace Imp {
	class  Logger {
	public:
		static void init();
		Logger();
<<<<<<< HEAD
		~Logger();
		
		inline static std::shared_ptr<spdlog::logger> coreLog() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger> clientLog() { return clientLogger; }

		void getData(...);
=======
		~Logger();	
		inline static std::shared_ptr<spdlog::logger>& coreLog() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& clientLog() { return clientLogger; }
>>>>>>> 5e522e335790d9ad5cdc3b306a266e8d19d1cba7
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}