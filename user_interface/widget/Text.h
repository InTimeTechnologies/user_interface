#pragma once

// Dependencies | OS
#include <Windows.h>

// Depdendencies | std
#include <string>

// Dependencies | ui
#include "Widget.h"

namespace ui {
	class Text : public Widget {
		// Object
		private:
			// Properties
			std::string string{};

		public:
			// Constructor / Destructor
			Text(Widget* parent = nullptr);
			Text(Widget* parent, const std::string& string);
			Text(const std::string& string);
			virtual ~Text();

			// Getters
			std::string getString() const;
			size_t getLength() const;
			
			// Setters
			void setText(const std::string& string);
	};
}
