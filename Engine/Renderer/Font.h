#pragma once
#include <string>
#include "Resource/Resource.h"
struct _TTF_Font;
namespace Bogo
{

	class Font : public Resource
	{
		public:
			Font() = default;
			Font(const std::string& filename, int fontsize);
			~Font();

			bool Create(std::string filename,...);

			void Load(const std::string& filename, int fontsize);
			friend class Text;
	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}	
