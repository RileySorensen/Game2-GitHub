#include "EventManager.h"

void Bogo::EventManger::Initialize()
{
	//
}

void Bogo::EventManger::Shutdown()
{
	//
}

void Bogo::EventManger::Update()
{
	//
}

void Bogo::EventManger::Subscribe(const std::string& name, Event::functionPtr function, GameObject* receiver)
{
	Observer observer;
	observer.receiver = receiver;
	observer.function = function;
	m_events[name].push_back(observer);
}

void Bogo::EventManger::UnSubscribe(const std::string& name, GameObject* receiver)
{

}

void Bogo::EventManger::Notify(const Event& event_)
{
	auto& observers = m_events[event_.name];
	for (auto& observer : observers)
	{
		if (event_.receiver == nullptr || event_.receiver == observer.receiver)
		{
			observer.function(event_);
		}
	}
}
