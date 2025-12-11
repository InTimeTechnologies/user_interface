#pragma once

// Dependencies | OS
#include <Windows.h>

// Dependencies | std
#include <string>

namespace ui {
	class TextPainter {
		// Static
		public:
			// Functions
			static void s_render(HDC deviceContext, int x, int y, const std::string& string);

		// Object
		public:
			// Properties
			int x{ 0 };
			int y{ 0 };
			std::string string{};

		public:
			void render(HDC deviceContext) const;
	};
}
