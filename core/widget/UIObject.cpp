#include "UIObject.h"

namespace ui {
	// class UIObject

	// Object | public

	// Constructor / Destructor
	UIObject::UIObject(UIObject* parent) : parent(parent) {

	}
	UIObject::~UIObject() {
		// Delete children
		for (UIObject* child : children)
			delete child;
		children.clear();

		// Detach from parent
		if (parent != nullptr) {
			parent->children.remove(this);
			parent = nullptr;
		}
	}

	// Getters
	UIObject* UIObject::getParent() const {
		return parent;
	}

	// Setters
	void UIObject::setParent(UIObject* newParent) {
		// Remove this from current parent
		if (parent != nullptr) {
			parent->children.remove(this);
			parent = nullptr;
		}

		// Attach this to new parent
		if (newParent != nullptr) {
			parent = newParent;
			parent->children.push_back(this);
		}
	}
}