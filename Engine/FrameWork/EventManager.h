#pragma once
#include"Event.h"
#include <map>
#include <list>
namespace Bogo
{
	class EventManger
	{
	public:
		struct Observer
		{
			GameObject* receiver = nullptr;
			Event::functionPtr function;
		};
	public:
		void Initialize();
		void Shutdown();
		void Update();

		void Subscribe(const std::string& name, Event::functionPtr function, GameObject* receiver = nullptr);
		void UnSubscribe(const std::string& name, GameObject* receiver);
		
		void Notify(const Event& event_);

	private:
		std::map<std::string, std::list<Observer>> m_events;
	};
}