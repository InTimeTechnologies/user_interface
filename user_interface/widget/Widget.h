#pragma once

// Dependencies | std
#include <list>

// Dependencies | ui
#include "UIObject.h"
#include "../core/WindowModality.h"
#include "../core/Rect.h"
#include "../core/SizePolicy.h"

namespace ui {
	class Widget : public UIObject {
		// Object
		protected:
			// Properties
			Widget* parent{ nullptr };
			std::list<Widget*> children{};

			WindowModality modality{ WindowModality::None };
			bool enabled{ true };
			RectI geometry{};
			SizePolicy sizePolicy{ SizePolicy::Preferred, SizePolicy::Preferred, 0, 0 };
			SizeI minimumSize{ 0, 0 };
			SizeI maximumSize{ 16777215, 16777215 };
			SizeI sizeIncrement{ 0, 0 };
			SizeI baseSize{ 0, 0 };
			// Palette palette{};
			// Font font{};
			// Cursor cursor{};
			bool mouseTracking{ false };
			bool tabletTracking{ false };
			// FocusPolicy focusPolicy{ FocusPolicy::NoFocus };
			// ContextMenuPolicy contextMenuPolicy{ ContextMenuPolicy::DefaultContextMenu };
			bool acceptDrops{ false };
			std::string windowTitle{};
			// Icon windowIcon{};
			// ToolTip toolTip{};
			float windowOpacity{ 1.0f };
			std::string toolTip{};
			int toolTipDuration{ -1 };
			// StatusTip statusTip{};
			// WhatsThis whatsThis{};
			// AccessibleName accessibleName{};
			// AccessibleDescription accessibleDescription{};
			// AccessibleIndentifier accessibleIdentifier{};
			// LayoutDirection layoutDirection{ LayoutDirection::LeftToRight };
			bool autoFillBackground{ false };
			// StyleSheet styleSheet{};
			// Locale locale{};
			// std::filesystem::path windowFilePath{};
			// InputMethodHints inputMethodHints{};

		public:
			// Constructor / Destructor
			Widget(Widget* parent = nullptr);
			virtual ~Widget();

			// Getters
			RectI getGeometry() const;

			// Setters
			RectI setGeometry(const RectI& newGeometry);

			// Functions

	};
}
