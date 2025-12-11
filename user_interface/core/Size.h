#pragma once

namespace ui {
	// Forward declarations
	struct SizeI;
	struct SizeF;

	struct SizeI {
		// Properties
		int width{ 0 }, height{ 0 };

		// Constructors
		SizeI() = default;
		SizeI(int width, int height) : width(width), height(height) {}
		SizeI(const SizeF& other);

		// Operators | arithmetic
		SizeI operator+(const SizeI& other) const {
			return SizeI(width + other.width, height + other.height);
		}
		SizeI operator-(const SizeI& other) const {
			return SizeI(width - other.width, height - other.height);
		}
		SizeI operator*(int scalar) const {
			return SizeI(width * scalar, height * scalar);
		}
		SizeI operator/(int scalar) const {
			return SizeI(width / scalar, height / scalar);
		}
		SizeI operator%(int scalar) const {
			return SizeI(width % scalar, height % scalar);
		}

		// Operators | arithmetic assignment
		SizeI& operator+=(const SizeI& other) {
			width += other.width;
			height += other.height;
			return *this;
		}
		SizeI& operator-=(const SizeI& other) {
			width -= other.width;
			height -= other.height;
			return *this;
		}
		SizeI& operator*=(int scalar) {
			width *= scalar;
			height *= scalar;
			return *this;
		}
		SizeI& operator/=(int scalar) {
			width /= scalar;
			height /= scalar;
			return *this;
		}
		SizeI& operator%=(int scalar) {
			width %= scalar;
			height %= scalar;
			return *this;
		}

		// Operators | conversions
		SizeI& operator=(const SizeF& other);
	};

	struct SizeF {
		// Properties
		float width{ 0.0f }, height{ 0.0f };

		// Constructors
		SizeF() = default;
		SizeF(float width, float height) : width(width), height(height) {}
		inline SizeF(const SizeI& other);

		// Operators | arithmetic
		SizeF operator+(const SizeF& other) const {
			return SizeF(width + other.width, height + other.height);
		}
		SizeF operator-(const SizeF& other) const {
			return SizeF(width - other.width, height - other.height);
		}
		SizeF operator*(float scalar) const {
			return SizeF(width * scalar, height * scalar);
		}
		SizeF operator/(float scalar) const {
			return SizeF(width / scalar, height / scalar);
		}

		// Operators | arithmetic assignment
		SizeF& operator+=(const SizeF& other) {
			width += other.width;
			height += other.height;
			return *this;
		}
		SizeF& operator-=(const SizeF& other) {
			width -= other.width;
			height -= other.height;
			return *this;
		}
		SizeF& operator*=(float scalar) {
			width *= scalar;
			height *= scalar;
			return *this;
		}
		SizeF& operator/=(float scalar) {
			width /= scalar;
			height /= scalar;
			return *this;
		}

		// Operators | conversions
		inline SizeF& operator=(const SizeI& other);
	};

	// Constructors | conversions
	inline SizeI::SizeI(const SizeF& other) {
		width = static_cast<int>(other.width);
		height = static_cast<int>(other.height);
	}
	inline SizeF::SizeF(const SizeI& other) {
		width = static_cast<float>(other.width);
		height = static_cast<float>(other.height);
	}

	// Operators | conversions
	inline SizeI& SizeI::operator=(const SizeF& other) {
		width = static_cast<int>(other.width);
		height = static_cast<int>(other.height);
		return *this;
	}
	inline SizeF& SizeF::operator=(const SizeI& other) {
		width = static_cast<float>(other.width);
		height = static_cast<float>(other.height);
		return *this;
	}
}
