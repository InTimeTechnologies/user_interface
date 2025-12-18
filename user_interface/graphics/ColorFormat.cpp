#include "ColorFormat.h"

// Dependencies | std
#include <cassert>

namespace ui {
	// struct Gray

	// Object | public

	// Operators | arithmetic
	Gray Gray::operator+(const Gray& other) const {
		return Gray{ static_cast<unsigned char>(r + other.r) };
	}
	Gray Gray::operator-(const Gray& other) const {
		return Gray{ static_cast<unsigned char>(r - other.r) };
	}
	Gray Gray::operator*(unsigned char scalar) const {
		return Gray{ static_cast<unsigned char>(r * scalar) };
	}
	Gray Gray::operator/(unsigned char scalar) const {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		return Gray{ static_cast<unsigned char>(r / scalar) };
	}

	// Operators | arithmetic assignment
	Gray& Gray::operator+=(const Gray& other) {
		r += other.r;
		return *this;
	}
	Gray& Gray::operator-=(const Gray& other) {
		r -= other.r;
		return *this;
	}
	Gray& Gray::operator*=(unsigned char scalar) {
		r *= scalar;
		return *this;
	}
	Gray& Gray::operator/=(unsigned char scalar) {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		r /= scalar;
		return *this;
	}

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

	// struct GrayAlpha
	
	// Object | public

	// Operators | arithmetic
	GrayAlpha GrayAlpha::operator+(const GrayAlpha& other) const {
		return GrayAlpha{
			static_cast<unsigned char>(r + other.r),
			static_cast<unsigned char>(a + other.a)
		};
	}
	GrayAlpha GrayAlpha::operator-(const GrayAlpha& other) const {
		return GrayAlpha{
			static_cast<unsigned char>(r - other.r),
			static_cast<unsigned char>(a - other.a)
		};
	}
	GrayAlpha GrayAlpha::operator*(unsigned char scalar) const {
		return GrayAlpha{
			static_cast<unsigned char>(r * scalar),
			static_cast<unsigned char>(a * scalar)
		};
	}
	GrayAlpha GrayAlpha::operator/(unsigned char scalar) const {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		return GrayAlpha{
			static_cast<unsigned char>(r / scalar),
			static_cast<unsigned char>(a / scalar)
		};
	}

	// Operators | arithmetic assignment
	GrayAlpha& GrayAlpha::operator+=(const GrayAlpha& other) {
		r += other.r;
		a += other.a;
		return *this;
	}
	GrayAlpha& GrayAlpha::operator-=(const GrayAlpha& other) {
		r -= other.r;
		a -= other.a;
		return *this;
	}
	GrayAlpha& GrayAlpha::operator*=(unsigned char scalar) {
		r *= scalar;
		a *= scalar;
		return *this;
	}
	GrayAlpha& GrayAlpha::operator/=(unsigned char scalar) {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		r /= scalar;
		a /= scalar;
		return *this;
	}

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

	// struct RGB

	// Object | public

	// Arithmetic
	RGB RGB::operator+(const RGB & other) const {
		return RGB{
			static_cast<unsigned char>(r + other.r),
			static_cast<unsigned char>(g + other.g),
			static_cast<unsigned char>(b + other.b)
		};
	}
	RGB RGB::operator-(const RGB& other) const {
		return RGB{
			static_cast<unsigned char>(r - other.r),
			static_cast<unsigned char>(g - other.g),
			static_cast<unsigned char>(b - other.b)
		};
	}
	RGB RGB::operator*(unsigned char scalar) const {
		return RGB{
			static_cast<unsigned char>(r * scalar),
			static_cast<unsigned char>(g * scalar),
			static_cast<unsigned char>(b * scalar)
		};
	}
	RGB RGB::operator/(unsigned char scalar) const {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		return RGB{
			static_cast<unsigned char>(r / scalar),
			static_cast<unsigned char>(g / scalar),
			static_cast<unsigned char>(b / scalar)
		};
	}

	// Operators | arithmetic assignment
	RGB& RGB::operator+=(const RGB& other) {
		r += other.r;
		g += other.g;
		b += other.b;
		return *this;
	}
	RGB& RGB::operator-=(const RGB& other) {
		r -= other.r;
		g -= other.g;
		b -= other.b;
		return *this;
	}
	RGB& RGB::operator*=(unsigned char scalar) {
		r *= scalar;
		g *= scalar;
		b *= scalar;
		return *this;
	}
	RGB& RGB::operator/=(unsigned char scalar) {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		r /= scalar;
		g /= scalar;
		b /= scalar;
		return *this;
	}

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

	// struct RGBA

	// Object | public

	// Operators | arithmetic
	RGBA RGBA::operator+(const RGBA& other) const {
		return RGBA{
			static_cast<unsigned char>(r + other.r),
			static_cast<unsigned char>(g + other.g),
			static_cast<unsigned char>(b + other.b),
			static_cast<unsigned char>(a + other.a)
		};
	}
	RGBA RGBA::operator-(const RGBA& other) const {
		return RGBA{
			static_cast<unsigned char>(r - other.r),
			static_cast<unsigned char>(g - other.g),
			static_cast<unsigned char>(b - other.b),
			static_cast<unsigned char>(a - other.a)
		};
	}
	RGBA RGBA::operator*(unsigned char scalar) const {
		return RGBA{
			static_cast<unsigned char>(r * scalar),
			static_cast<unsigned char>(g * scalar),
			static_cast<unsigned char>(b * scalar),
			static_cast<unsigned char>(a * scalar)
		};
	}
	RGBA RGBA::operator/(unsigned char scalar) const {
		return RGBA{
			static_cast<unsigned char>(r / scalar),
			static_cast<unsigned char>(g / scalar),
			static_cast<unsigned char>(b / scalar),
			static_cast<unsigned char>(a / scalar)
		};
	}

	// Operators | arithmetic assignment
	RGBA& RGBA::operator+=(const RGBA& other) {
		r += other.r;
		g += other.g;
		b += other.b;
		a += other.a;
		return *this;
	}
	RGBA& RGBA::operator-=(const RGBA& other) {
		r -= other.r;
		g -= other.g;
		b -= other.b;
		a -= other.a;
		return *this;
	}
	RGBA& RGBA::operator*=(unsigned char scalar) {
		r *= scalar;
		g *= scalar;
		b *= scalar;
		a *= scalar;
		return *this;
	}
	RGBA& RGBA::operator/=(unsigned char scalar) {
		assert(scalar != 0 && "scalar == 0. scalar must not be 0.");
		r /= scalar;
		g /= scalar;
		b /= scalar;
		a /= scalar;
		return *this;
	}

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
