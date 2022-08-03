#pragma once
#include <string>

struct _TTF_Font;
namespace Bogo
{

	class Font
	{
		public:
			Font() = default;
			Font(const std::string& filename, int fontsize);
			~Font();

			void Load(const std::string& filename, int fontsize);
			friend class Text;
	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}	
