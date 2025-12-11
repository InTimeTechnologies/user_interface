#include "Font.h"

namespace ui {
	// struct Font

	// Static | public

	// Properties
	int Font::s_defaultHeight{ 32 };
	int Font::s_defaultWidth{ 0 };
	int Font::s_defaultAngle{ 0 };
	int Font::s_defaultOrientation{ 0 };
	Font::Weight Font::s_defaultFontWeight{ Weight::NORMAL };
	bool Font::s_defaultItalic{ false };
	bool Font::s_defaultStrikeOut{ false };
	bool Font::s_defaultUnderline{ false };
	Font::Charset Font::s_defaultCharset{ Charset::ANSI };
	Font::OutPrecision Font::s_defaultOutPrecision{ OutPrecision::DEFAULT };
	Font::ClipPrecision Font::s_defaultClipPrecision{ ClipPrecision::DEFAULT };
	Font::Quality Font::s_defaultQuality{ Quality::DEFAULT };
	Font::Pitch Font::s_defaultPitch{ Pitch::DEFAULT };
	Font::Family Font::s_defaultFamily{ Family::SWISS };
	std::string Font::s_defaultFontName{ "Arial" };

	// Object | public

	// Functions
	[[nodiscard]] HFONT Font::toHandle() const {
		return CreateFontA(
			height,
			width,
			angle, orientation,
			static_cast<int>(fontWeight),
			italic, strikeOut, underline,
			static_cast<int>(charset),
			static_cast<int>(outPrecision),
			static_cast<int>(clipPrecision),
			static_cast<int>(quality),
			static_cast<int>(fontPitch | fontFamily),
			fontName.c_str()
		);
	}
}