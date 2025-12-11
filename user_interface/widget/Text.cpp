#include "Text.h"

namespace ui {
	// class Text

	// Object | public

	// Constructor / Destructor
	Text::Text(Widget* parent) : Widget(parent) {

	}
	Text::Text(Widget* parent, const std::string& string) : Widget(parent), string(string) {

	}
	Text::Text(const std::string& string) : Widget(nullptr), string(string) {

	}
	Text::~Text() {

	}

	// Getters
	std::string Text::getString() const {
		return string;
	}
	size_t Text::getLength() const {
		return string.length();
	}

	// Setters
	void Text::setText(const std::string& string) {
		this->string = string;
	}
}
