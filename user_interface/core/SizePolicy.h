#pragma once

namespace ui {
	struct SizePolicy {
		public:
			// Enums
			enum Policy {
				Fixed,
				Expanding,
				Minimum,
				Maximum,
				Preferred,
				Ignored
			};

			enum ControlType { // You might not need this. You could use type_info instead.
				DefaultType,
				ButtonBox,
				CheckBox,
				ComboBox,
				Frame,
				Label,
				Line,
				LineEdit,
				PushButton,
				RadioButton,
				Slider,
				SpinBox,
				TabWidget,
				ToolBotton
			};

		// Object
		public:
			// Properties
			Policy horizontalPolicy{ Preferred };
			Policy verticalPolicy{ Preferred };
			int horizontalStretch{ 0 };
			int verticalStretch{ 0 };

			// Constructors
			SizePolicy(Policy hPolicy = Preferred, Policy vPolicy = Preferred, int horizontalStretch = 0, int verticalStretch = 0) :
				horizontalPolicy(hPolicy),
				verticalPolicy(vPolicy),
				horizontalStretch(horizontalStretch),
				verticalStretch(verticalStretch) {}
	};
}
