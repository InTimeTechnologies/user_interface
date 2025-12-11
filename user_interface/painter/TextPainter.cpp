#include "TextPainter.h"

namespace ui {
	// class TextPainter

	// Static | public

	// Functions
	void TextPainter::s_render(HDC deviceContext, int x, int y, const std::string& string) {
		TextOutA(deviceContext, x, y, string.c_str(), string.length());
	}

	// Object | public

	// Functions
	void TextPainter::render(HDC deviceContext) const {
		TextOutA(deviceContext, x, y, string.c_str(), string.length());
	}
}
