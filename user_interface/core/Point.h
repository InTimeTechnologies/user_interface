#pragma once

// Dependencies | glm
#include <glm/vec2.hpp>

namespace ui {
	struct PointI {
		// Properties
		glm::ivec2 point{};

		// Constructors
		PointI() = default;
		PointI(int x, int y) : point(x, y) {}
		PointI(const glm::ivec2& vec) : point(vec) {}
	};
	struct PointF {
		// Properties
		glm::vec2 point{};

		// Constructors
		PointF() = default;
		PointF(float x, float y) : point(x, y) {}
		PointF(const glm::vec2& vec) : point(vec) {}
	};
}
