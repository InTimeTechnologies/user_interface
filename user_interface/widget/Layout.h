#pragma once

namespace ui {
	class Layout {
		public:
			// Constructor / Destructor
			Layout() = default;
			virtual ~Layout() = default;
			virtual void addWidget(class Widget* widget) = 0;
			virtual void removeWidget(class Widget* widget) = 0;

			// Functions
	};
}
