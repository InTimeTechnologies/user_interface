#pragma once

// Dependencies | std
#include <cmath>

// Dependencies | glm
#include <glm/vec2.hpp>

namespace ui {
	struct LineI {
		// Properties
		glm::vec2 p1{}, p2{};

		// Constructors
		LineI() = default;
		LineI(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}
		LineI(const glm::ivec2& p1, const glm::ivec2& p2) : p1(p1), p2(p2) {}

		// Functions
		int length() const {
			return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
		}
		glm::ivec2 middle() const {
			return (p1 + p2) / 2.0f;
		}
		void translate(const glm::ivec2& translation) {
			p1 += translation;
			p2 += translation;
		}
		LineI translated(const glm::ivec2& translation) const {
			LineI result{ p1, p2 };
			result.p1 += translation;
			result.p2 += translation;
			return result;
		}
	};

	struct LineF {
		// Properties
		glm::vec2 p1{}, p2{};

		// Constructors
		LineF() = default;
		LineF(float x1, float y1, float x2, float y2) : p1(x1, y1), p2(x2, y2) {}
		LineF(const glm::vec2& p1, const glm::vec2& p2) : p1(p1), p2(p2) {}

		// Functions
		float length() const {
			return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
		}
		glm::vec2 middle() const {
			return (p1 + p2) / 2.0f;
		}
		void translate(const glm::vec2& translation) {
			p1 += translation;
			p2 += translation;
		}
		LineF translated(const glm::vec2& translation) const {
			LineF result{ p1, p2 };
			result.p1 += translation;
			result.p2 += translation;
			return result;
		}
	};
}