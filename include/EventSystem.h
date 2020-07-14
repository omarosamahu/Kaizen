#pragma once
#include <memory>
#include <functional>
#include <unordered_map>
#include <string>
#include <iostream>

namespace es{
	class EventListerHandle {
		template<typename U>
		friend class EventChannel;
	private: 
		std::function<void()> removeFunction;
		bool removed;
		EventListerHandle() = delete;
		inline EventListerHandle(std::function<void()> remove_function) :removed(false) {
			this->removeFunction = remove_function;
		}
	public:
		inline void remove() {
			this->removed = true;
			removeFunction();
		}
};
	template <typename T>
	class EventChannel {
	private:
		using idType = unsigned int;
		static const idType& getNextId();
	public:
	};
}