#pragma once

// Dependencies | OS
#include <Windows.h>

// Dependencies | ui | core
#include "../core/Line.h"

// Dependencies | ui | painter
#include "../painter/Pen.h"

namespace ui {
	class LinePainter {
		// Static
		public:
			// Functions
			static void s_render(HDC deviceContext, const LinePainter& linePainter);

		public:
			// Properties
			LineI line{};

			// Functions
			void render(HDC deviceContext);
	};
}
