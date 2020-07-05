#include <Kaizen.h>
#include <Logger.h>


int main() {
	auto console = spdlog::stdout_color_mt("console");
	//Imp::Logger::init();
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	std::unique_ptr<Imp::Logger> log = std::make_unique<Imp::Logger>();
	log->init();
	kai->run();
	return 0;
}