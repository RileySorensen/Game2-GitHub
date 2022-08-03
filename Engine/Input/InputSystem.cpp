#include "InputSystem.h"
#include <SDL.h>
#include <iostream>
namespace Bogo
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_W;
	const uint32_t key_down = SDL_SCANCODE_S;
	const uint32_t key_left = SDL_SCANCODE_A;
	const uint32_t key_right = SDL_SCANCODE_D;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;

	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);
		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}

	void InputSystem::Shutdown()
	{

	}

	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		//save previous keyboardstate
		m_prevKeyboardState = m_keyboardState;
		//get current keyboardstate
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());
		
		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = Bogo::Vector2{ x,y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK;
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK;
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK;
		
	}

	InputSystem:: State InputSystem::GetButtonState(uint32_t button)
	{
		State keyState = State::Idle;
		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		if (buttonDown && prevButtonDown)
		{
			keyState = Held;
		}
		if (!buttonDown && prevButtonDown)
		{
			keyState = Released;
		}
		if (buttonDown && !prevButtonDown)
		{
			keyState = Pressed;
		}
		if (!buttonDown && !prevButtonDown)
		{
			keyState = Idle;
		}

		return keyState;
	}
	InputSystem::State InputSystem::GetKeyState(uint32_t Key)
	{
		State keyState = State::Idle;
		bool buttonDown = GetButtonDown(Key);
		bool prevButtonDown = GetPreviousButtonDown(Key);

		if (buttonDown && prevButtonDown)
		{
			keyState = Held;
		}
		if (!buttonDown && prevButtonDown)
		{
			keyState = Released;
		}
		if (buttonDown && !prevButtonDown)
		{
			keyState = Pressed;
		}
		if (!buttonDown && !prevButtonDown)
		{
			keyState = Idle;
		}

		return keyState;
	}
}
