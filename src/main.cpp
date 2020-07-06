#include <Kaizen.h>
#include <Logger.h>

int main() {
	//auto console = spdlog::stdout_color_mt("console");
	
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	
	std::shared_ptr<Imp::Logger> log = std::make_shared<Imp::Logger>();
	log->init();
	kai->run();
	
	
	return 0;
}