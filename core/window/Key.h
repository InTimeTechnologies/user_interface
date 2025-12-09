#pragma once

// Dependencies | std
#include <string>

// Dependencies | ui
#include "KeyCode.h"

namespace ui {
	struct Key {
		// Properties
		KeyCode keyCode{ KeyCode::UNKNOWN };
		bool justPressed{ false };
		bool repeat{ false };
		bool justReleased{ false };
		bool pressed{ false };
		std::string description{};

		// Contructor / Destructor
		Key() = default;
		Key(KeyCode keyCode, const std::string& description) : keyCode(keyCode), description(description) {

		}
		~Key() = default;
	};
}