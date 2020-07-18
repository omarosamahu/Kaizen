#pragma once
#include "Core.h"
namespace es {
	class Event {
	public:

	public:
		Event() = delete;
		Event(EventId type) :mType(type) {}

		template<typename T>
		void setParam(EventId id, T value) {
			mData[id] = value;
		}

		template<typename T>
		T getParam(EventId id) const {
			return std::any_cast<T>(mData[id]);
		}

		EventId GetType() const { return mType; }
	private:
		EventId mType{};
		std::array<std::any, MAX_PARAM> mData{};
	};
}