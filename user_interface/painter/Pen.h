#pragma once

// Dependencies | OS
#include <Windows.h>

// Dependencies | ui
#include "../graphics/ColorFormat.h"

namespace ui {
	class Pen {
		// Enums
		public:
			enum class Style : int{
				SOLID = PS_SOLID,
				DASH = PS_DASH,
				DOT = PS_DOT,
				DASHDOT = PS_DASHDOT,
				DASHDOTDOT = PS_DASHDOTDOT,
				NULL_ = PS_NULL,
				INSIDEFRAME = PS_INSIDEFRAME,
				USERSTYLE = PS_USERSTYLE,
				ALTERNATE_ = PS_ALTERNATE,
				STYLE_MASK = PS_STYLE_MASK,

				ENDCAP_ROUND = PS_ENDCAP_ROUND,
				ENDCAP_SQUARE = PS_ENDCAP_SQUARE,
				ENDCAP_FLAT = PS_ENDCAP_FLAT,
				ENDCAP_MASK = PS_ENDCAP_MASK,

				JOIN_ROUND = PS_JOIN_ROUND,
				JOIN_BEVEL = PS_JOIN_BEVEL,
				JOIN_MITER = PS_JOIN_MITER,
				JOIN_MASK = PS_JOIN_MASK,

				COSMETIC = PS_COSMETIC,
				GEOMETRIC = PS_GEOMETRIC,
				TYPE_MASK = PS_TYPE_MASK
			};

		// Object
		private:
			// Properties
			HPEN handle{ nullptr };

		public:
			// Properties
			Style style{ Style::SOLID };
			int thickness{ 2 };
			RGB rgb{};

			// Constructor / Destructor
			Pen() = default;
			Pen(const Pen& other) = delete;
			Pen(Pen&& other) = delete;
			~Pen();

			// Operators | assignment
			Pen& operator=(const Pen& other) = delete;
			Pen& operator=(Pen&& other) = delete;

			// Getters
			HPEN getHandle() const;

			// Functions
			HPEN createHandle();
			void destroyHandle();
	};
}
