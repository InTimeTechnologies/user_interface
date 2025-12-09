#pragma once

// Dependencies | std
#include <string>
#include <list>

namespace ui {
	class UIObject {
		// Object
		protected:
			// Properties
			UIObject* parent{ nullptr };
			std::list<UIObject*> children{};

		public:
			// Properties
			std::string name{};

			// Constructor / Destructor
			UIObject(UIObject* parent = nullptr);
			virtual ~UIObject();

			// Getters
			UIObject* getParent() const;

			// Setters
			void setParent(UIObject* newParent);
	};
}
