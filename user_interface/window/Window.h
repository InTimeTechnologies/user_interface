#pragma once

// Dependenncies | OS
#include <Windows.h>

// Dependencies | std
#include <string>

// Dependencies | ui
#include "WindowMessage.h"
#include "WindowStyle.h"

#include "../core/Rect.h"

namespace ui {
	class Window {
		// Static
		public:
			// Properties
			static const std::wstring S_CLASS_NAME;
			static HBRUSH s_backgroundBrush;
			static std::wstring s_defaultWindowTitle;
			static int defaultX, defaultY, defaultWidth, defaultHeight;

		private:
			// Properties
			static size_t s_windowCount;

		private:
			// Functions
			static bool s_registerWindowClass();
			static bool s_unregisterWindowClass();
			static bool s_windowClassIsRegistered();
			static WNDCLASSEX s_getWindowClass();
			static size_t s_getWindowCount();

		// Object
		private:
			// Properties
			HINSTANCE applicationInstance{};
			HWND windowHandle{};

		public:
			// Constructor / Destrcutor
			Window();
			Window(const Window& other) = delete;
			Window(const Window&& other) = delete;
			Window& operator=(const Window& other) = delete;
			Window& operator=(Window&& other) = delete;
			~Window();

			// Getters
			std::wstring getTitle() const;
			WindowStyle getStyle() const;
			WindowStyle getExtendedStyle() const;
			RectI getRect() const;
			int getx() const;
			int gety() const;
			int getWidth() const;
			int getHeight() const;
			HDC getDeviceContext() const;

			// Setters
			void setTitle(const std::string& title);
			void setStyle(WindowStyle style);
			void setRect(const RectI& rect);
			void setPosition(int x, int y);
			void setSize(int width, int height);

			// Functions
			bool processMessages();
			bool addStyle(WindowStyle style);
			bool removeStyle(WindowStyle style);
			void redraw();
			void releaseDeviceContext(HDC deviceContext);

			void renderText();
			void renderLine();
			void renderRectangle();
			void renderEllipse();
			void renderFilledRectangle();
	};
}
