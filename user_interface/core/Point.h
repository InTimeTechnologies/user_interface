#pragma once

// Dependencies | ui
#include "Size.h"

namespace ui {
	// Forward declarations
	struct PointI;
	struct PointF;

	struct PointI {
		// Properties
		int x{ 0 }, y{ 0 };

		// Constructors
		PointI() = default;
		PointI(int x, int y) : x(x), y(y) {}
		PointI(const PointF& other);

		// Operators | arithmetic
		PointI operator+(const PointI& other) const {
			return PointI{ x + other.x, y + other.y};
		}
		PointI operator-(const PointI& other) const {
			return PointI{ x - other.x, y - other.y};
		}
		PointI operator*(int scalar) const {
			return PointI { x * scalar, y * scalar };
		}
		PointI operator/(int scalar) const {
			return PointI{ x / scalar, y / scalar };
		}
		PointI operator%(int scalar) const {
			return PointI{ x % scalar, y % scalar };
		}
		PointI operator+(const SizeI& other) const {
			return PointI(x + other.width, y + other.height);
		}
		PointI operator-(const SizeI& other) const {
			return PointI(x - other.width, y - other.height);
		}

		// Operators | assignment
		PointI& operator+=(const PointI& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		PointI& operator-=(const PointI& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		PointI& operator*=(int scalar) {
			x *= scalar;
			y *= scalar;
			return *this;
		}
		PointI& operator/=(int scalar) {
			x /= scalar;
			y /= scalar;
			return *this;
		}
		PointI& operator%=(int scalar) {
			x %= scalar;
			y %= scalar;
			return *this;
		}
		PointI& operator+=(const SizeI& other) {
			x += other.width;
			y += other.height;
			return *this;
		}
		PointI& operator-=(const SizeI& other) {
			x -= other.width;
			y -= other.height;
			return *this;
		}

		// Operators | conversions
		PointI& operator=(const PointF& other);
	};
	struct PointF {
		// Properties
		float x{ 0.0f }, y{ 0.0f };

		// Constructors
		PointF() = default;
		PointF(float x, float y) : x(x), y(y) {}
		PointF(const PointI& other);

		// Operators | arithmetic
		PointF operator+(const PointF& other) const {
			return PointF{ x + other.x, y + other.y };
		}
		PointF operator-(const PointF& other) const {
			return PointF{ x - other.x, y - other.y };
		}
		PointF operator*(float scalar) const {
			return PointF{ x * scalar, y * scalar };
		}
		PointF operator/(float scalar) const {
			return PointF{ x / scalar, y / scalar };
		}
		PointF operator+(const SizeI& other) const {
			return PointF(x + other.width, y + other.height);
		}
		PointF operator-(const SizeI& other) const {
			return PointF(x - other.width, y - other.height);
		}

		// Operators | assignment
		PointF& operator+=(const PointF& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		PointF& operator-=(const PointF& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		PointF& operator*=(float scalar) {
			x *= scalar;
			y *= scalar;
			return *this;
		}
		PointF& operator/=(float scalar) {
			x /= scalar;
			y /= scalar;
			return *this;
		}
		PointF& operator+=(const SizeI& other) {
			x += other.width;
			y += other.height;
			return *this;
		}

		// Operators | conversions
		PointF& operator=(const PointI& other);
	};

	// Constructors | conversion
	inline PointI::PointI(const PointF& other) {
		x = static_cast<int>(other.x);
		y = static_cast<int>(other.y);
	}
	inline PointF::PointF(const PointI& other) {
		x = static_cast<float>(other.x);
		y = static_cast<float>(other.y);
	}

	// Operators | conversion
	inline PointI& PointI::operator=(const PointF& other) {
		x = static_cast<int>(other.x);
		y = static_cast<int>(other.y);
		return *this;
	}
	inline PointF& PointF::operator=(const PointI& other) {
		x = static_cast<float>(other.x);
		y = static_cast<float>(other.y);
		return *this;
	}
}
