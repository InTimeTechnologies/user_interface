#pragma once

// Dependencies | std
#include <cmath>

// Dependencies | ui
#include "Point.h"

namespace ui {
	struct LineI {
		// Properties
		PointI p1{}, p2{};

		// Constructors
		LineI() = default;
		LineI(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}
		LineI(const PointI& p1, const PointI& p2) : p1(p1), p2(p2) {}

		// Functions
		int length() const {
			int dx = p2.x - p1.x;
			int dy = p2.y - p1.y;
			return static_cast<int>(std::sqrt(dx * dx + dy * dy));
		}
		float lengthF() const {
			float dx = p2.x - p1.x;
			float dy = p2.y - p1.y;
			return std::sqrt(dx * dx + dy * dy);
		}
		PointI middle() const {
			return (p1 + p2) / 2;
		}
		PointF middleF() const {
			return static_cast<PointF>(p1 + p2) / 2.0f;
		}
		void translate(const PointI& translation) {
			p1 += translation;
			p2 += translation;
		}
		LineI translated(const PointI& translation) const {
			return LineI{ p1 + translation, p2 + translation };
		}
	};

	struct LineF {
		// Properties
		PointF p1{}, p2{};

		// Constructors
		LineF() = default;
		LineF(float x1, float y1, float x2, float y2) : p1(x1, y1), p2(x2, y2) {}
		LineF(const PointF& p1, const PointF& p2) : p1(p1), p2(p2) {}

		// Functions
		float length() const {
			float dx = p2.x - p1.x;
			float dy = p2.y - p1.y;
			return std::sqrt(dx * dx + dy * dy);
		}
		PointF middle() const {
			return (p1 + p2) / 2.0f;
		}
		void translate(const PointF& translation) {
			p1 += translation;
			p2 += translation;
		}
		LineF translated(const PointF& translation) const {
			return LineF{ p1 + translation, p2 + translation };
		}
	};
}
