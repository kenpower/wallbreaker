#ifndef GUI_THEME_HPP
#define GUI_THEME_HPP

#include <map>
#include <string>
#include "BitmapFont.hpp"

namespace gui
{

class Theme
{
public:
	static void load(const std::string& path);

	static const BitmapFont& getFont();

private:
	static BitmapFont m_font;
};

}

#endif // GUI_THEME_HPP