#include <Kaizen.h>
#include <Logger.h>
#include <atomic>
#include <thread>
#include <functional>
#include <unordered_map>

namespace es {
	class EventListener {
		template<typename U>
		friend class EventChannel;
	private:
		std::function<void()> removeFunction;
		bool removed;
		EventListener() = delete;
		inline EventListener(std::function<void()> remove_function) :removed(false) {
			this->removeFunction = remove_function;
		}
	public:
		inline void remove() {
			this->removed = true;
			removeFunction();
		}
	};
}
int main() {

	std::unique_ptr<Imp::Kaizen> kai = std::make_unique<Imp::Kaizen>();
	
	Imp::Logger::init();
	Imp::Logger::coreLog()->warn("Core Logger intialized");
	Imp::Logger::clientLog()->info("Hello ya 3m kaizen");
	
	kai->run();
		
	return 0;
}