#include "Pen.h"

namespace ui {
	// class Pen

	// Object | public

	// Constructor / Destructor
	Pen::~Pen() {
		destroyHandle();
	}

	// Getters
	HPEN Pen::getHandle() const {
		return handle;
	}

	// Functions
	HPEN Pen::createHandle() {
		destroyHandle();
		handle = CreatePen(static_cast<int>(style), thickness, RGB(rgb.r, rgb.g, rgb.b));
		return handle;
	}
	void Pen::destroyHandle() {
		if (handle != nullptr) {
			DeleteObject(handle);
			handle = nullptr;
		}
	}
}
