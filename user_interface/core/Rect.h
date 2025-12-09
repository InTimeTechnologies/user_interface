#pragma once

// Dependencies | glm
#include <glm/vec2.hpp>

// Dependencies | ui
#include "Size.h"
#include "Point.h"
#include "Margins.h"

namespace ui {
	struct RectI {
		// Properties
		glm::ivec2 topLeft{}, size{};

		// Constructors
		RectI() = default;
		RectI(int topLeftX, int topLeftY, int width, int height) : topLeft(topLeftX, topLeftY), size(width, height) {}
		RectI(const glm::ivec2& topLeft, const glm::ivec2& size) : topLeft(topLeft), size(size) {}
		RectI(const PointI& topLeft, const PointI& bottomRight) : topLeft(topLeft.point), size(bottomRight.point - topLeft.point) {}

		// Getters
		glm::ivec2 getCenter() const {
			return topLeft + size / 2;
		}
		glm::vec2 getCenterF() const {
			return glm::vec2(topLeft) + glm::vec2(size) / 2.0f;
		}
		glm::ivec2 getSize() const {
			return size;
		}

		int getTop() const {
			return topLeft.y;
		}
		int getBottom() const {
			return topLeft.y + size.y;
		}
		int getRight() const {
			return topLeft.x + size.x;
		}
		int getLeft() const {
			return topLeft.x;
		}

		glm::ivec2 getTopRight() const {
			return glm::ivec2(topLeft.x + size.x, topLeft.y);
		}
		glm::ivec2 getBottomRight() const {
			return topLeft + size;
		}
		glm::ivec2 getTopLeft() const {
			return topLeft;
		}
		glm::ivec2 getBottomLeft() const {
			return glm::ivec2(topLeft.x, topLeft.y + size.y);
		}

		int getHeight() const {
			return size.y;
		}
		int getWidth() const {
			return size.x;
		}

		// Functions
		bool isValid() const {
			return size.x >= 0 && size.y >= 0;
		}
		void translate(const glm::ivec2& translation) {
			topLeft += translation;
		}
		bool isEmpty() const {
			return size.x == 0 || size.y == 0;
		}

		// Operators | arithmetic assignments
		RectI& operator+=(const MarginsI& margins) {
			topLeft.x -= margins.left;
			topLeft.y -= margins.top;
			size.x += margins.left + margins.right;
			size.y += margins.top + margins.bottom;
			return *this;
		}
		RectI& operator-=(const MarginsI& margins) {
			topLeft.x += margins.left;
			topLeft.y += margins.top;
			size.x -= margins.left + margins.right;
			size.y -= margins.top + margins.bottom;
			return *this;
		}

		// Operators | arithmetic
		RectI operator+(const MarginsI& margins) const {
			return RectI(
				topLeft.x - margins.left,
				topLeft.y - margins.top,
				size.x + margins.left + margins.right,
				size.y + margins.top + margins.bottom
			);
		}
		RectI operator-(const MarginsI& margins) const {
			return RectI(
				topLeft.x + margins.left,
				topLeft.y + margins.top,
				size.x - (margins.left + margins.right),
				size.y - (margins.top + margins.bottom)
			);
		}
	};
	struct RectF {
		// Properties
		glm::vec2 topLeft{}, size{};

		// Constructors
		RectF() = default;
		RectF(float topLeftX, float topLeftY, float width, float height) : topLeft(topLeftX, topLeftY), size(width, height) {}
		RectF(const glm::vec2& topLeft, const glm::vec2& size) : topLeft(topLeft), size(size) {}
		RectF(const PointI& topLeft, const PointI& bottomRight) : topLeft(topLeft.point), size(bottomRight.point - topLeft.point) {}

		// Getters
		glm::vec2 getCenter() const {
			return topLeft + size / 2.0f;
		}
		glm::vec2 getSize() const {
			return size;
		}

		float getTop() const {
			return topLeft.y;
		}
		float getBottom() const {
			return topLeft.y + size.y;
		}
		float getRight() const {
			return topLeft.x + size.x;
		}
		float getLeft() const {
			return topLeft.x;
		}

		glm::vec2 getTopRight() const {
			return glm::vec2(topLeft.x + size.x, topLeft.y);
		}
		glm::vec2 getBottomRight() const {
			return topLeft + size;
		}
		glm::vec2 getTopLeft() const {
			return topLeft;
		}
		glm::vec2 getBottomLeft() const {
			return glm::vec2(topLeft.x, topLeft.y + size.y);
		}

		float getHeight() const {
			return size.y;
		}
		float getWidth() const {
			return size.x;
		}

		// Functions
		bool isValid() const {
			return size.x >= 0.0f && size.y >= 0.0f;
		}
		void translate(const glm::vec2& translation) {
			topLeft += translation;
		}
		bool isEmpty() const {
			return size.x == 0.0f || size.y == 0.0f;
		}

		// Operators | arithmetic assignments
		RectF& operator+=(const MarginsI& margins) {
			topLeft.x -= margins.left;
			topLeft.y -= margins.top;
			size.x += margins.left + margins.right;
			size.y += margins.top + margins.bottom;
			return *this;
		}
		RectF& operator-=(const MarginsI& margins) {
			topLeft.x += margins.left;
			topLeft.y += margins.top;
			size.x -= margins.left + margins.right;
			size.y -= margins.top + margins.bottom;
			return *this;
		}

		// Operators | arithmetic
		RectF operator+(const MarginsI& margins) const {
			return RectF(
				topLeft.x - margins.left,
				topLeft.y - margins.top,
				size.x + margins.left + margins.right,
				size.y + margins.top + margins.bottom
			);
		}
		RectF operator-(const MarginsI& margins) const {
			return RectF(
				topLeft.x + margins.left,
				topLeft.y + margins.top,
				size.x - (margins.left + margins.right),
				size.y - (margins.top + margins.bottom)
			);
		}
	};

	/*
		struct RectI {
		// Properrties
		glm::ivec2 topLeft{}, bottomRight{};

		// Constructors
		RectI() = default;
		RectI(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) : topLeft(topLeftX, topLeftY), bottomRight(bottomRightX, bottomRightY) {}
		RectI(const glm::ivec2& topLeft, const glm::ivec2& bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {}
		RectI(const PointI& topLeft, const PointI& bottomRight) : topLeft(topLeft.point), bottomRight(bottomRight.point) {}
		RectI(const glm::ivec2 topLeft, const SizeI& size) : topLeft(topLeft), bottomRight({ topLeft.x + size.vec.x,  topLeft.y - size.vec.y }) {}

		// Getters
		glm::ivec2 getCenter() const {
			return (topLeft + bottomRight) / 2;
		}
		glm::ivec2 getSize() const {
			return bottomRight - topLeft;
		}
		glm::vec2 getCenterF() const {
			return glm::vec2((topLeft + bottomRight)) / 2.0f;
		}
		glm::vec2 getSizeF() const {
			return glm::vec2(bottomRight - topLeft);
		}

		int getTop() const {
			return topLeft.y;
		}
		int getBottom() const {
			return bottomRight.y;
		}
		int getRight() const {
			return bottomRight.x;
		}
		int getLeft() const {
			return topLeft.x;
		}

		glm::vec2 getTopRight() const {
			return glm::vec2(bottomRight.x, topLeft.y);
		}
		glm::vec2 getBottomRight() const {
			return bottomRight;
		}
		glm::vec2 getTopLeft() const {
			return topLeft;
		}
		glm::vec2 getBottomLeft() const {
			return glm::vec2(topLeft.x, bottomRight.y);
		}

		int getHeight() const {
			return bottomRight.y - topLeft.y;
		}
		int getWidth() const {
			return bottomRight.x - topLeft.x;
		}

		// Functions
		bool isValid() const {
			return (topLeft.x <= bottomRight.x) && (topLeft.y <= bottomRight.y);
		}
		void fix() {
			if (topLeft.x > bottomRight.x) {
				int temp = topLeft.x;
				topLeft.x = bottomRight.x;
				bottomRight.x = temp;
			}
			if (topLeft.y > bottomRight.y) {
				int temp = topLeft.y;
				topLeft.y = bottomRight.y;
				bottomRight.y = temp;
			}
		}
		void translate(const glm::ivec2& delta) {
			topLeft += delta;
			bottomRight += delta;
		}
		bool isEmpty() const {
			return (topLeft.x == bottomRight.x) || (topLeft.y == bottomRight.y);
		}

		// Operators | arithmetic assignments
		RectI& operator+=(const MarginsI& margins) {
			topLeft.x -= margins.left;
			topLeft.y -= margins.top;
			bottomRight.x += margins.right;
			bottomRight.y += margins.bottom;
			return *this;
		}
		RectI& operator-=(const MarginsI& margins) {
			topLeft.x += margins.left;
			topLeft.y += margins.top;
			bottomRight.x -= margins.right;
			bottomRight.y -= margins.bottom;
			return *this;
		}

		// Operators | arithmetic
		RectI operator+(const MarginsI& margins) const {
			return RectI(
				topLeft.x - margins.left,
				topLeft.y - margins.top,
				bottomRight.x + margins.right,
				bottomRight.y + margins.bottom
			);
		}
		RectI operator-(const MarginsI& margins) const {
			return RectI(
				topLeft.x + margins.left,
				topLeft.y + margins.top,
				bottomRight.x - margins.right,
				bottomRight.y - margins.bottom
			);
		}
	};
	struct RectF {
		// Properrties
		glm::vec2 topLeft{}, bottomRight{};

		// Constructors
		RectF() = default;
		RectF(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY) : topLeft(topLeftX, topLeftY), bottomRight(bottomRightX, bottomRightY) {}
		RectF(const glm::vec2& topLeft, const glm::vec2& bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {}
		RectF(const PointF& topLeft, const PointF& bottomRight) : topLeft(topLeft.point), bottomRight(bottomRight.point) {}
		RectF(const glm::vec2 topLeft, const SizeF& size) : topLeft(topLeft), bottomRight({ topLeft.x + size.vec.x,  topLeft.y - size.vec.y }) {}

		// Getters
		glm::vec2 getCenter() const {
			return (topLeft + bottomRight) / 2.0f;
		}
		glm::vec2 getSize() const {
			return bottomRight - topLeft;
		}

		float getTop() const {
			return topLeft.y;
		}
		float getBottom() const {
			return bottomRight.y;
		}
		float getRight() const {
			return bottomRight.x;
		}
		float getLeft() const {
			return topLeft.x;
		}

		glm::vec2 getTopRight() const {
			return glm::vec2(bottomRight.x, topLeft.y);
		}
		glm::vec2 getBottomRight() const {
			return bottomRight;
		}
		glm::vec2 getTopLeft() const {
			return topLeft;
		}
		glm::vec2 getBottomLeft() const {
			return glm::vec2(topLeft.x, bottomRight.y);
		}

		float getHeight() const {
			return bottomRight.y - topLeft.y;
		}
		float getWidth() const {
			return bottomRight.x - topLeft.x;
		}

		// Functions
		bool isValid() const {
			return (topLeft.x <= bottomRight.x) && (topLeft.y <= bottomRight.y);
		}
		void fix() {
			if (topLeft.x > bottomRight.x)
				std::swap(topLeft.x, bottomRight.x);
			if (topLeft.y > bottomRight.y)
				std::swap(topLeft.y, bottomRight.y);
		}
		void translate(const glm::vec2& delta) {
			topLeft += delta;
			bottomRight += delta;
		}
		bool isEmpty() const {
			return (topLeft.x == bottomRight.x) || (topLeft.y == bottomRight.y);
		}

		// Operators | arithmetic assignments
		RectF& operator+=(const MarginsF& margins) {
			topLeft.x -= margins.left;
			topLeft.y -= margins.top;
			bottomRight.x += margins.right;
			bottomRight.y += margins.bottom;
			return *this;
		}
		RectF& operator-=(const MarginsF& margins) {
			topLeft.x += margins.left;
			topLeft.y += margins.top;
			bottomRight.x -= margins.right;
			bottomRight.y -= margins.bottom;
			return *this;
		}

		// Operators | arithmetic
		RectF operator+(const MarginsF& margins) const {
			return RectF(
				topLeft.x - margins.left,
				topLeft.y - margins.top,
				bottomRight.x + margins.right,
				bottomRight.y + margins.bottom
			);
		}
		RectF operator-(const MarginsF& margins) const {
			return RectF(
				topLeft.x + margins.left,
				topLeft.y + margins.top,
				bottomRight.x - margins.right,
				bottomRight.y - margins.bottom
			);
		}
	};
	*/
}
