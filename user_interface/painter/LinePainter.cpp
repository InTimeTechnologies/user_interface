#include "LinePainter.h"

namespace ui {
	// class LinePainter

	// Static | public

	// Functions
	void LinePainter::s_render(HDC deviceContext, const LinePainter& linePainter) {
		const LineI line = linePainter.line;
		MoveToEx(deviceContext, line.p1.x, linePainter.line.p1.y, nullptr);
		LineTo(deviceContext, line.p2.x, line.p2.y);
	}

	// Functions
	void LinePainter::render(HDC deviceContext) {
		MoveToEx(deviceContext, line.p1.x, line.p1.y, nullptr);
		LineTo(deviceContext, line.p2.x, line.p2.y);
	}
}
