#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>


    void EnemyComponent::Initialize()
    {
        CharacterComponent::Initialize();
    }

    void EnemyComponent::Update()
    {
        auto actor = m_owner->GetScene()->GetActorFromName("Player");
        if (speedBoostTimer < 0)
        {
            speed = 20;
            speedBoostTimer = 200;
        }
        if (actor)
        {
            Bogo::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
            Bogo::Vector2 force = direction.Normalized() * speed;

            auto component = m_owner->GetComponent<Bogo::PhysicsComponents>();
            if (component) component->ApplyForce(force);
            if (speed > 2)
            {
                speed--;
            }
            speedBoostTimer--;
        }
    }

    void EnemyComponent::OnCollisionEnter(Bogo::Actor* other)
    {
        if (other->GetTag() == "Player")
        {
            Bogo::Event event;
            event.name = "EVENT_DAMAGE";
            event.data = damage;
            event.receiver = other;

            Bogo::g_eventManager.Notify(event);
        }
    }

    void EnemyComponent::OnCollisionExit(Bogo::Actor* other)
    {
    }

    void EnemyComponent::OnNotify(const Bogo::Event& event)
    {
        if (event.name == "EVENT_DAMAGE")
        {
            health -= std::get<float>(event.data);
            if (health <= 0)
            {
                m_owner->setDestroy();
            }
        }

    }

    bool EnemyComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool EnemyComponent::Read(const rapidjson::Value& value)
    {
        CharacterComponent::Read(value);

        return true;
    }
