#include <Kaizen.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main() {
	auto console = spdlog::stdout_color_mt("console");
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	kai->run();
	return 0;
}