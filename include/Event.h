#pragma once
#include "Core.h"
namespace es {
	class Event {
	public:
		//Event() = delete;
		virtual ~Event(){}
	private:
		virtual void applyEvent() const = 0;
	};
	class MouseEvent  : public Event {
	private:
		std::string msg;
	public:
		MouseEvent(std::string id) :msg(id) {

		}
		virtual void applyEvent() const {
			std::cout << "Callback for " << msg << " Event has applied"<< std::endl;
		}
	};
	class KeyBoardEvent : public Event {
	private:
		std::string mType;
		uint32_t mId;
	public:
		
		KeyBoardEvent(uint32_t id,std::string type) :mId(id),mType(type) {

		}
		virtual void applyEvent() const {
			std::cout << "Callback for " << mType << " Event has applied with id: " << mId << std::endl;
		}
	};
	using Listener = std::function<const void(const Event&)>;
	using RefrenceTable = std::unordered_map<const std::type_info*, std::function<const void(const Event&)>>;

	class Handler {
	private:
			static RefrenceTable map;
	public:
		template<typename EventWanted>
		static void addListener(const Listener& lis) {
			Handler::map.emplace(&typeid(EventWanted), lis);
		}
		static void executeEvent(const Event& event) {
			for (const auto& item : map) {
				item.second(event);
			}
		}
	};
}