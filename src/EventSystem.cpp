#pragma once
#include <functional>
#include <atomic>
#include <list>

namespace Imp {
	template <typename ... Args> class eventHandler {
	public:
		typedef std::function<void(Args ...)> handelr_func_type;
		handelr_func_type m_handeler_func;
		eventHandler(const handelr_func_type& handlerfunc) :m_handeler_func(handlerfunc) {
			m_handleId = ++m_handlerCounterId;
		}
		bool operator==(const eventHandler& other) const {
			return m_handleId == other.m_handleId;
		}
		inline unsigned int id() const {
			return m_handleId;
		}
	private:
		unsigned int m_handleId;
		static std::atomic_uint m_handlerCounterId;

	};

	template <typename ... Args> std::atomic_uint eventHandler<Args ...>::m_handlerCounterId(0);

	template<typename ... Args> class Event{
	public:
		typedef eventHandler<Args ...> handler_type;
	protected:
		typedef std::list<handler_type> handler_collection_type;
	private:
		typedef  handler_collection_type m_handlers;
	};
}


