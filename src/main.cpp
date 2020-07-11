#include <Kaizen.h>
#include <Logger.h>

int main() {
	//auto console = spdlog::stdout_color_mt("console");
	
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Core Logger intialized");
	Imp::Logger::clientLog()->info("Hello ya 3m kaizen");
	
	kai->run();
	
	
	return 0;
}