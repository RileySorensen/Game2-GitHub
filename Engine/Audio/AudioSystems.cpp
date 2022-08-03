#include "AudioSystems.h"
#include <fmod.hpp>
void Bogo::AudioSystem::Initialize()
{
	FMOD::System_Create(&m_fmodSystem);

	void* extradriverdata = nullptr;
	m_fmodSystem->init(32, FMOD_INIT_NORMAL, extradriverdata);
}

void Bogo::AudioSystem::Shutdown()
{
	for (auto sounds : m_sounds)
	{
		sounds.second->release();
	}
	m_sounds.clear();
	m_fmodSystem->close();
	m_fmodSystem->release();
}

void Bogo::AudioSystem::Update()
{
	m_fmodSystem->update();
}

void Bogo::AudioSystem::AddAudio(const std::string& name, const std::string& filename)
{
	if (m_sounds.find(name) == m_sounds.end())
	{
		FMOD::Sound* sound = nullptr;
		m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
		m_sounds[name] = sound;
	}
}

void Bogo::AudioSystem::PlayAudio(const std::string& name, bool loop)
{
	auto iter = m_sounds.find(name);
	if (iter != m_sounds.end())
	{
		FMOD::Sound* sound = iter->second;
		sound->setMode(FMOD_LOOP_OFF);

	FMOD::Channel* channel;
	m_fmodSystem->playSound(sound, 0, false, &channel);
	}
}
