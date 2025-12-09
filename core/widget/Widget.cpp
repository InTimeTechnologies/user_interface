#include "Widget.h"

namespace ui {
	// class Widget

	// Object | public

	// Constructor / Destructor
	Widget::Widget(Widget* parent) : parent(parent) {
		// Attach to parent
		if (this->parent)
			this->parent->children.push_back(this);
	}
	Widget::~Widget() {
		// Delete children
		for (Widget* child : children)
			delete child;
		children.clear();

		// Detach from parent
		if (parent != nullptr) {
			parent->children.remove(this);
			parent = nullptr;
		}
	}

	// Getters
	RectI Widget::getGeometry() const {
		return geometry;
	}

	// Settters
	RectI Widget::setGeometry(const RectI& newGeometry) {
		geometry = newGeometry;
		return geometry;
	}
}
