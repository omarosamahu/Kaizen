#pragma once
#include "Event.h"
namespace es {
	using Listener = std::function<void(Event&)>;
	using Listeners = std::list<Listener>;

	class EventManager {

	public:
		void addListener(EventId id, const Listener& lis) {
			mListeners[id].push_back(lis);
		}
		void SendEvent(Event& event) {
			auto type = event.GetType();
			for (auto const& item : mListeners[type]) {
				item(event);
			}
		}
		void SendEvent(EventId eventId) {
			Event event(eventId);

			for (auto const& item : mListeners[eventId]) {
				item(event);
			}
		}
	private:
		std::unordered_map<EventId, Listeners> mListeners;
	};
}