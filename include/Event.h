#pragma once
#include "Core.h"
namespace es {
	class Event {
	public:
		//Event() = delete;
		virtual ~Event() = default;

		virtual void applyEvent() const = 0;

		virtual std::string getID() const = 0;

	};

	class MouseEvent  : public Event {
	private:
		std::string msg;
	public:
		MouseEvent(std::string id) :msg(id) {}

		void applyEvent() const override {
			std::cout << "Callback for " << msg << " Event has applied"<< std::endl;
		}

		std::string getID() const override {
			return "MouseEvent";
		}
	};

	class KeyBoardEvent : public Event {
	private:
		std::string mType;
		uint32_t mId;
	public:
		
		KeyBoardEvent(uint32_t id,std::string type) :mId(id),mType(type) {

		}

		void applyEvent() const override {
			std::cout << "Callback for " << mType << " Event has applied with id: " << mId << std::endl;
		}

		std::string getID() const override {
			return "KeyBoardEvent";
		}
	};
	using Listener      = std::function<void(const Event&)>;
	using Listeners     = std::vector<Listener>;
	using RefrenceTable = std::unordered_map<std::string, Listeners>;
	

	class Handler {
	private:
			static RefrenceTable map;
	public:
		static void addListener(const std::string& eventID, Listener lis) {
			//map.emplace(eventID, lis);
			map[eventID].emplace_back(lis);
		}

		static void executeEvent(const Event& event) {
			auto itr = map.find(event.getID());
			if (itr == map.end()) {
				return;
			}

			for(auto& func : itr->second) {
				func(event);
			}
		}
	};
}