#pragma once

namespace ui {
	struct MarginsI {
		// Properties
		int top{}, bottom{}, right{}, left{};

		// Operators | arithmetic assignments
		MarginsI& operator+=(const MarginsI& other) {
			top += other.top;
			bottom += other.bottom;
			right += other.right;
			left += other.left;
			return *this;
		}
		MarginsI& operator-=(const MarginsI& other) {
			top -= other.top;
			bottom -= other.bottom;
			right -= other.right;
			left -= other.left;
			return *this;
		}
		MarginsI& operator*=(int scalar) {
			top *= scalar;
			bottom *= scalar;
			right *= scalar;
			left *= scalar;
			return *this;
		}
		MarginsI& operator/=(int scalar) {
			top /= scalar;
			bottom /= scalar;
			right /= scalar;
			left /= scalar;
			return *this;
		}

		// Operators | arithmetic
		MarginsI operator+(const MarginsI& other) const {
			return MarginsI{top + other.top, bottom + other.bottom, right + other.right, left + other.left};
		}
		MarginsI operator-(const MarginsI& other) const {
			return MarginsI{top - other.top, bottom - other.bottom, right - other.right, left - other.left};
		}
		MarginsI operator*(int scalar) const {
			return MarginsI{ top * scalar, bottom * scalar, right * scalar, left * scalar };
		}
		MarginsI operator/(int scalar) const {
			return MarginsI{ top / scalar, bottom / scalar, right / scalar, left / scalar };
		}
	};

	struct MarginsF {
		// Properties
		float top{}, bottom{}, right{}, left{};

		// Operators | arithmetic assignments
		MarginsF& operator+=(const MarginsF& other) {
			top += other.top;
			bottom += other.bottom;
			right += other.right;
			left += other.left;
			return *this;
		}
		MarginsF& operator-=(const MarginsF& other) {
			top -= other.top;
			bottom -= other.bottom;
			right -= other.right;
			left -= other.left;
			return *this;
		}
		MarginsF& operator*=(float scalar) {
			top *= scalar;
			bottom *= scalar;
			right *= scalar;
			left *= scalar;
			return *this;
		}
		MarginsF& operator/=(float scalar) {
			top /= scalar;
			bottom /= scalar;
			right /= scalar;
			left /= scalar;
			return *this;
		}

		// Operators | arithmetic
		MarginsF operator+(const MarginsF& other) const {
			return MarginsF{ top + other.top, bottom + other.bottom, right + other.right, left + other.left };
		}
		MarginsF operator-(const MarginsF& other) const {
			return MarginsF{ top - other.top, bottom - other.bottom, right - other.right, left - other.left };
		}
		MarginsF operator*(float scalar) const {
			return MarginsF{ top * scalar, bottom * scalar, right * scalar, left * scalar };
		}
		MarginsF operator/(float scalar) const {
			return MarginsF{ top / scalar, bottom / scalar, right / scalar, left / scalar };
		}
	};
}