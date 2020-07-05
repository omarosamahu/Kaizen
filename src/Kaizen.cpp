#include <Kaizen.h>

namespace Imp {
	Kaizen::Kaizen(){

	}
	Kaizen::~Kaizen() {
		std::cout << "Destructor called" << std::endl;
	}
	void Kaizen::run(){
		printf("Welcome to Kaizen\n");
	}
}