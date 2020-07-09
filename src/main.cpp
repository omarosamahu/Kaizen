#include <Kaizen.h>
#include <Logger.h>


//enum LOGGING
//{
//	KAIZEN_CORE Imp::Logger::coreLog()->warn("Intialized Log")
//};
int main() {
	
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	kai->run();
	// Intialize logger
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Intialized Log");
	Imp::Logger::clientLog()->info("Hello");
	
	
	
	return 0;
}