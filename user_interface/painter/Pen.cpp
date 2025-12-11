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
	HPEN Pen::createHandle(Style style) {
		destroyHandle();
		handle = CreatePen(static_cast<int>(style), 2, RGB(255, 0, 0));
		return handle;
	}
	void Pen::destroyHandle() {
		if (handle != nullptr) {
			DeleteObject(handle);
			handle = nullptr;
		}
	}
}
