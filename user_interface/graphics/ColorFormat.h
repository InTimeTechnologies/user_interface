#pragma once

// TODO: Add conversion function to create Gray from other types.
// TODO: Add conversion function to create GrayAlpha from other types.
// TODO: Add conversion function to create RGB from other types.
// TODO: Add conversion function to create RGBA from other types.

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
		Gray operator+(const Gray& other) const;
		Gray operator-(const Gray& other) const;
		Gray operator*(unsigned char scalar) const;
		Gray operator/(unsigned char scalar) const;

		// Operators | arithmetic assignment
		Gray& operator+=(const Gray& other);
		Gray& operator-=(const Gray& other);
		Gray& operator*=(unsigned char scalar);
		Gray& operator/=(unsigned char scalar);

		// Conversion
		Gray& operator=(const GrayAlpha& other);
		Gray& operator=(const RGB& other);
		Gray& operator=(const RGBA& other);
	};
	struct GrayAlpha {
		// Object

		// Properties
		unsigned char r{ 255 }, a{ 255 };

		// Operators | arithmetic
		GrayAlpha operator+(const GrayAlpha& other) const;
		GrayAlpha operator-(const GrayAlpha& other) const;
		GrayAlpha operator*(unsigned char scalar) const;
		GrayAlpha operator/(unsigned char scalar) const;

		// Operators | arithmetic assignment
		GrayAlpha& operator+=(const GrayAlpha& other);
		GrayAlpha& operator-=(const GrayAlpha& other);
		GrayAlpha& operator*=(unsigned char scalar);
		GrayAlpha& operator/=(unsigned char scalar);

		// Conversion
		GrayAlpha& operator=(const Gray& other);
		GrayAlpha& operator=(const RGB& other);
		GrayAlpha& operator=(const RGBA& other);
	};
	struct RGB {
		// Object

		// Properties
		unsigned char r{ 255 }, g{ 255 }, b{ 255 };

		// Arithmetic
		RGB operator+(const RGB& other) const;
		RGB operator-(const RGB& other) const;
		RGB operator*(unsigned char scalar) const;
		RGB operator/(unsigned char scalar) const;

		// Operators | arithmetic assignment
		RGB& operator+=(const RGB& other);
		RGB& operator-=(const RGB& other);
		RGB& operator*=(unsigned char scalar);
		RGB& operator/=(unsigned char scalar);

		// Conversion
		RGB& operator=(const Gray& other);
		RGB& operator=(const GrayAlpha& other);
		RGB& operator=(const RGBA& other);
	};
	struct RGBA {
		// Object

		// Properties
		unsigned char r{ 255 }, g{ 255 }, b{ 255 }, a{ 255 };

		// Operators | arithmetic
		RGBA operator+(const RGBA& other) const;
		RGBA operator-(const RGBA& other) const;
		RGBA operator*(unsigned char scalar) const;
		RGBA operator/(unsigned char scalar) const;

		// Operators | arithmetic assignment
		RGBA& operator+=(const RGBA& other);
		RGBA& operator-=(const RGBA& other);
		RGBA& operator*=(unsigned char scalar);
		RGBA& operator/=(unsigned char scalar);

		// Operators | assignment conversion
		RGBA& operator=(const Gray& other);
		RGBA& operator=(const GrayAlpha& other);
		RGBA& operator=(const RGB & other);
	};
}
