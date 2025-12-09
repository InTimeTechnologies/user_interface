#pragma once

// Dependencies | glm
#include <glm/vec2.hpp>

namespace ui {
	struct SizeI {
		// Properties
		glm::ivec2 vec{};

		// Constructors
		SizeI() = default;
		SizeI(int width, int height) : vec(width, height) {}
		SizeI(const glm::ivec2& vec) : vec(vec) {}
	};

	struct SizeF {
		// Properties
		glm::vec2 vec{};

		// Constructors
		SizeF() = default;
		SizeF(int width, int height) : vec(width, height) {}
		SizeF(const glm::vec2& vec) : vec(vec) {}
	};
}
