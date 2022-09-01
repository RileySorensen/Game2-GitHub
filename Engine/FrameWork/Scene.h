#pragma once
#include "Actor.h"
#include<list>
#include <memory>
namespace Bogo
{
	class Actor;
	class Renderer;
	class Game;

	class Scene :public GameObject, public ISerializable
	{
	public:
		Scene() = default;
		Scene(Game* game) : m_game{ game } {}
		Scene(const Scene& other) {}
		~Scene() = default;

		CLASS_DECLARATION(Scene)

		void Update() override;
		void Initialize() override;
		void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();
		template <typename T>
		T* GetActor();

		Game* GetGame() { return m_game; }

		template <typename T = Actor>
		T* GetActorFromName(const std::string& name);

		template <typename T = Actor>
		std::vector<T*> GetActorsFromTag(const std::string& tag);

	private:
		Game* m_game;
		std::list<std::unique_ptr<Actor>> m_actors;

		// Inherited via ISerializable
		
	};
	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}

		return nullptr;
	}
	template<typename T>
	inline T* Scene::GetActorFromName(const std::string& name)
	{
		for (auto& actor : m_actors)
		{
			if (name == actor->GetName())
			{
				return dynamic_cast<T*>(actor.get());
			}
		}
		return nullptr;
	}
	template<typename T>
	inline std::vector<T*> Scene::GetActorsFromTag(const std::string& tag)
	{
		std::vector<T*> result;

		for(auto& actor : m_actors)
		{
			if (actor->GetTag()) 
				{
				T* tagActor = dynamic_cast<T*>(actor.get());
				if (tagActor) result.push_back(tagActor);
				 }
		}
		return result;
	}
}
