#pragma once
#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "FrameWork/Scene.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Audio/AudioSystems.h"

#include <iostream>
namespace Bogo
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audio;
}
