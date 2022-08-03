#include "Texture.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>

namespace Bogo
{
    Texture::~Texture()
    {
        if (!m_texture)
        {
            SDL_DestroyTexture;
        }
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        SDL_Surface* surface = IMG_Load(filename.c_str());
        m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        SDL_FreeSurface(surface);

        return true;
    }

    Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr,&point.x, &point.y );
        return Vector2().x, Vector2().y;
    }

}
