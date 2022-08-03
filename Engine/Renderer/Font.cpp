#include "Font.h"
#include <SDL_ttf.h>
Bogo::Font::Font(const std::string& filename, int fontsize)
{
	Load(filename, fontsize);
}

Bogo::Font::~Font()
{
	if (!m_ttfFont)
	{
		TTF_CloseFont(m_ttfFont);
		m_ttfFont = nullptr;
	}
}

void Bogo::Font::Load(const std::string& filename, int fontsize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontsize);
}
