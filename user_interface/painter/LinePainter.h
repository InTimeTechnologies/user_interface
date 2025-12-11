#pragma once

// Dependencies | OS
#include <Windows.h>

namespace ui {
	class LinePainter {
		// Static
		public:
			// Functions
			static void s_render(int x0, int y0, int x1, int y1);

		public:
			// Properties
			int x0{ 0 }, y0{ 0 }, x1{ 0 }, y1{ 0 };

			// Functions
			void render(HDC deviceContext);
	};
}
