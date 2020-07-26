#include <Kaizen.h>
#include <Logger.h>
#include <atomic>
#include <thread>
#include <functional>
#include <unordered_map>
#include <Event.h>
 
es::RefrenceTable es::Handler::map;

int main() {
	es::KeyBoardEvent keyBoardEvent(10, "Data");
	es::MouseEvent mouseEvent("Mouse");

	es::Handler::addListener(mouseEvent.getID(), [](const es::Event& e) {
		std::cout << "First:" << '\n';
		e.applyEvent();
	});

	es::Handler::addListener(mouseEvent.getID(), [](const es::Event& e) {
		std::cout << "Second:" << '\n';
		e.applyEvent();
	});

	es::Handler::executeEvent(mouseEvent);
	es::Handler::executeEvent(es::KeyBoardEvent(10, "KeyBoard"));

	std::cout << "Finish First TEST\n\n";

	es::Handler::addListener(keyBoardEvent.getID(), [](const es::Event& e) {
		std::cout << "First Key:" << '\n';
		e.applyEvent();
	});

	es::Handler::addListener(keyBoardEvent.getID(), [](const es::Event& e) {
		std::cout << "Third Key:" << '\n';
		e.applyEvent();
	});

	es::Handler::executeEvent(mouseEvent);
	es::Handler::executeEvent(keyBoardEvent);

	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Core Logger intialized");
	Imp::Logger::clientLog()->info("Hello ya 3m kaizen");
	
	kai->run();
		
	return 0;
}