#pragma once

// Dependencies | std
#include <cassert>

// TODO: Add conversion function to create Gray from other types.

namespace ui {
	// Forward declarations
	struct Gray;
	struct GrayAlpha;
	struct RGB;
	struct RGBA;

	// Struct
	struct Gray {
		// Object

		// Properties
		unsigned char r{ 255 };

		// Constructor | conversion

		// Operators | arithmetic
		Gray operator+(const Gray& other) const {
			return Gray{ static_cast<unsigned char>(r + other.r) };
		}
		Gray operator-(const Gray& other) const {
			return Gray{ static_cast<unsigned char>(r - other.r) };
		}
		Gray operator*(unsigned char scalar) const {
			return Gray{ static_cast<unsigned char>(r * scalar) };
		}
		Gray operator/(unsigned char scalar) const {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			return Gray{ static_cast<unsigned char>(r / scalar) };
		}

		// Operators | arithmetic assignment
		Gray& operator+=(const Gray& other) {
			r += other.r;
			return *this;
		}
		Gray& operator-=(const Gray& other) {
			r -= other.r;
			return *this;
		}
		Gray& operator*=(unsigned char scalar) {
			r *= scalar;
			return *this;
		}
		Gray& operator/=(unsigned char scalar) {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			r /= scalar;
			return *this;
		}

		// Conversion
		Gray& operator=(const GrayAlpha& other); // Defined at the bottom of this header file as inline
		Gray& operator=(const RGB& other); // Defined at the bottom of this header file as inline
		Gray& operator=(const RGBA& other); // Defined at the bottom of this header file as inline
	};
	struct GrayAlpha {
		// Object

		// Properties
		unsigned char r{ 255 }, a{ 255 };

		// Operators | arithmetic
		GrayAlpha operator+(const GrayAlpha& other) const {
			return GrayAlpha {
				static_cast<unsigned char>(r + other.r),
				static_cast<unsigned char>(a + other.a)
			};
		}
		GrayAlpha operator-(const GrayAlpha& other) const {
			return GrayAlpha{
				static_cast<unsigned char>(r - other.r),
				static_cast<unsigned char>(a - other.a)
			};
		}
		GrayAlpha operator*(unsigned char scalar) const {
			return GrayAlpha {
				static_cast<unsigned char>(r * scalar),
				static_cast<unsigned char>(a * scalar)
			};
		}
		GrayAlpha operator/(unsigned char scalar) const {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			return GrayAlpha {
				static_cast<unsigned char>(r / scalar),
				static_cast<unsigned char>(a / scalar)
			};
		}

		// Operators | arithmetic assignment
		GrayAlpha& operator+=(const GrayAlpha& other) {
			r += other.r;
			a += other.a;
			return *this;
		}
		GrayAlpha& operator-=(const GrayAlpha& other) {
			r -= other.r;
			a -= other.a;
			return *this;
		}
		GrayAlpha& operator*=(unsigned char scalar) {
			r *= scalar;
			a *= scalar;
			return *this;
		}
		GrayAlpha& operator/=(unsigned char scalar) {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			r /= scalar;
			a /= scalar;
			return *this;
		}

		// Conversion
		GrayAlpha& operator=(const Gray& other); // Defined at the bottom of this header file as inline
		GrayAlpha& operator=(const RGB& other); // Defined at the bottom of this header file as inline
		GrayAlpha& operator=(const RGBA& other); // Defined at the bottom of this header file as inline
	};
	struct RGB {
		// Object

		// Properties
		unsigned char r{ 255 }, g{ 255 }, b{ 255 };

		// Arithmetic
		RGB operator+(const RGB& other) const {
			return RGB {
				static_cast<unsigned char>(r + other.r),
				static_cast<unsigned char>(g + other.g),
				static_cast<unsigned char>(b + other.b)
			};
		}
		RGB operator-(const RGB& other) const {
			return RGB {
				static_cast<unsigned char>(r - other.r),
				static_cast<unsigned char>(g - other.g),
				static_cast<unsigned char>(b - other.b)
			};
		}
		RGB operator*(unsigned char scalar) const {
			return RGB {
				static_cast<unsigned char>(r * scalar),
				static_cast<unsigned char>(g * scalar),
				static_cast<unsigned char>(b * scalar)
			};
		}
		RGB operator/(unsigned char scalar) const {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			return RGB {
				static_cast<unsigned char>(r / scalar),
				static_cast<unsigned char>(g / scalar),
				static_cast<unsigned char>(b / scalar)
			};
		}

		// Operators | arithmetic assignment
		RGB& operator+=(const RGB& other) {
			r += other.r;
			g += other.g;
			b += other.b;
			return *this;
		}
		RGB& operator-=(const RGB& other) {
			r -= other.r;
			g -= other.g;
			b -= other.b;
			return *this;
		}
		RGB& operator*=(unsigned char scalar) {
			r *= scalar;
			g *= scalar;
			b *= scalar;
			return *this;
		}
		RGB& operator/=(unsigned char scalar) {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			r /= scalar;
			g /= scalar;
			b /= scalar;
			return *this;
		}

		// Conversion
		RGB& operator=(const Gray& other); // Defined at the bottom of this header file as inline
		RGB& operator=(const GrayAlpha& other); // Defined at the bottom of this header file as inline
		RGB& operator=(const RGBA& other); // Defined at the bottom of this header file as inline
	};
	struct RGBA {
		// Object

		// Properties
		unsigned char r{ 255 }, g{ 255 }, b{ 255 }, a{ 255 };

		// Operators | arithmetic
		RGBA operator+(const RGBA& other) const {
			return RGBA{
				static_cast<unsigned char>(r + other.r),
				static_cast<unsigned char>(g + other.g),
				static_cast<unsigned char>(b + other.b),
				static_cast<unsigned char>(a + other.a)
			};
		}
		RGBA operator-(const RGBA& other) const {
			return RGBA {
				static_cast<unsigned char>(r - other.r),
				static_cast<unsigned char>(g - other.g),
				static_cast<unsigned char>(b - other.b),
				static_cast<unsigned char>(a - other.a)
			};
		}
		RGBA operator*(unsigned char scalar) const {
			return RGBA {
				static_cast<unsigned char>(r * scalar),
				static_cast<unsigned char>(g * scalar),
				static_cast<unsigned char>(b * scalar),
				static_cast<unsigned char>(a * scalar)
			};
		}
		RGBA operator/(unsigned char scalar) const {
			return RGBA{
				static_cast<unsigned char>(r / scalar),
				static_cast<unsigned char>(g / scalar),
				static_cast<unsigned char>(b / scalar),
				static_cast<unsigned char>(a / scalar)
			};
		}

		// Operators | arithmetic assignment
		RGBA& operator+=(const RGBA& other) {
			r += other.r;
			g += other.g;
			b += other.b;
			a += other.a;
			return *this;
		}
		RGBA& operator-=(const RGBA& other) {
			r -= other.r;
			g -= other.g;
			b -= other.b;
			a -= other.a;
			return *this;
		}
		RGBA& operator*=(unsigned char scalar) {
			r *= scalar;
			g *= scalar;
			b *= scalar;
			a *= scalar;
			return *this;
		}
		RGBA& operator/=(unsigned char scalar) {
			assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
			r /= scalar;
			g /= scalar;
			b /= scalar;
			a /= scalar;
			return *this;
		}

		// Operators | assignment conversion
		RGBA& operator=(const Gray& other); // Defined at the bottom of this header file as inline
		RGBA& operator=(const GrayAlpha& other); // Defined at the bottom of this header file as inline
		RGBA& operator=(const RGB & other); // Defined at the bottom of this header file as inline
	};

	// Struct | Gray

	// Operator | assignment conversions
	inline Gray& Gray::operator=(const GrayAlpha& other) {
		r = other.r;
		return *this;
	}
	inline Gray& Gray::operator=(const RGB& other) {
		// Using liminance formula to convert RGB to grayscale
		r = static_cast<unsigned char>(
			other.r * 0.299f +
			other.g * 0.587f +
			other.b * 0.114f
			);
		return *this;
	}
	inline Gray& Gray::operator=(const RGBA& other) {
		// Using liminance formula to convert RGB to grayscale (ignore alpha)
		r = static_cast<unsigned char>(
			other.r * 0.299f +
			other.g * 0.587f +
			other.b * 0.114f
			);
		return *this;
	}

	// Struct | GrayAlpha

	// Operator | assignment conversion
	inline GrayAlpha& GrayAlpha::operator=(const Gray& other) {
		r = other.r;
		a = 255;
		return *this;
	}
	inline GrayAlpha& GrayAlpha::operator=(const RGB& other) {
		r = static_cast<unsigned char>(
			other.r * 0.299f +
			other.g * 0.587f +
			other.b * 0.114f
			);
		a = 255;
		return *this;
	}
	inline GrayAlpha& GrayAlpha::operator=(const RGBA& other) {
		r = static_cast<unsigned char>(
			other.r * 0.299f +
			other.g * 0.587f +
			other.b * 0.114f
			);
		a = other.a;
		return *this;
	}

	// Struct | RGB

	// Operator | assignment conversion
	inline RGB& RGB::operator=(const Gray& other) {
		r = other.r;
		g = other.r;
		b = other.r;
		return *this;
	}
	inline RGB& RGB::operator=(const GrayAlpha& other) {
		r = other.r;
		g = other.r;
		b = other.r;
		return *this;
	}
	inline RGB& RGB::operator=(const RGBA& other) {
		r = other.r;
		g = other.g;
		b = other.b;
		return *this;
	}

	// Struct | RGBA

	// Operator | assignment conversion
	inline RGBA& RGBA::operator=(const Gray& other) {
		r = other.r;
		g = other.r;
		b = other.r;
		a = 255;
		return *this;
	}
	inline RGBA& RGBA::operator=(const GrayAlpha& other) {
		r = other.r;
		g = other.r;
		b = other.r;
		a = other.a;
		return *this;
	}
	inline RGBA& RGBA::operator=(const RGB& other) {
		r = other.r;
		g = other.g;
		b = other.b;
		a = 255;
		return *this;
	}
}
