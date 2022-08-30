#include "AudioComponents.h"

Bogo::AudioComponent::~AudioComponent()
{
	m_channel.Stop();
}

void Bogo::AudioComponent::Initialize()
{
	if (play_on_start)
	{
		Play();
	}
}

void Bogo::AudioComponent::Update()
{

}

void Bogo::AudioComponent::Play()
{
	m_channel.Stop();
	m_channel = g_audio.PlayAudio(sound_name, volume, pitch, loop);
}

void Bogo::AudioComponent::Stop()
{
	m_channel.Stop();
}

bool Bogo::AudioComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool Bogo::AudioComponent::Read(const rapidjson::Value& value)
{
	READ_DATA(value, sound_name);
	READ_DATA(value, volume);
	READ_DATA(value, pitch);
	READ_DATA(value, play_on_start);
	READ_DATA(value, loop);

	g_audio.AddAudio(sound_name, sound_name);
	return true;
}
