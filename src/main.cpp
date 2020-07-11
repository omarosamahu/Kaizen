#include <Kaizen.h>
#include <Logger.h>


//enum LOGGING
//{
//	KAIZEN_CORE Imp::Logger::coreLog()->warn("Intialized Log")
//};
int main() {
	
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
<<<<<<< HEAD
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Core Logger intialized");
	Imp::Logger::clientLog()->info("Hello ya 3m kaizen");
	
=======
>>>>>>> 5e522e335790d9ad5cdc3b306a266e8d19d1cba7
	kai->run();
	// Intialize logger
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Intialized Log");
	Imp::Logger::clientLog()->info("Hello");
	
	
	
	return 0;
}