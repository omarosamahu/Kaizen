#include <Kaizen.h>
#include <Logger.h>
#include <atomic>
#include <thread>
#include <functional>
#include <unordered_map>
#include <Event.h>
 
es::RefrenceTable es::Handler::map;

int main() {
	{
		es::Handler::addListener<es::MouseEvent>([](const es::Event & e) {
			static_cast<const es::MouseEvent&>(e).applyEvent();
			});

		es::Handler::executeEvent(es::MouseEvent("Mouse"));
	}
	
	es::Handler::executeEvent(es::KeyBoardEvent(10,"KeyBoard"));
	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Core Logger intialized");
	Imp::Logger::clientLog()->info("Hello ya 3m kaizen");
	
	kai->run();
		
	return 0;
}