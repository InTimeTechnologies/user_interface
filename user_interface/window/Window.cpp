#include "Window.h"

// Dependencies | std
#include <iostream>
#include <cassert>

namespace ui {
	// Windows Procedure function
	static LRESULT CALLBACK windowProcedure(HWND windowHandle, UINT messageId, WPARAM wordParameter, LPARAM longParameter) {
		Window* window = reinterpret_cast<Window*>(GetWindowLongPtr(windowHandle, GWLP_USERDATA));
		WindowMessage message = static_cast<WindowMessage>(messageId);

		switch (message) {
			case WindowMessage::NON_CLIENT_CREATE:
				{
					// Setup before the window exists visually
					CREATESTRUCT* createStruct = reinterpret_cast<CREATESTRUCT*>(longParameter);
					window = reinterpret_cast<Window*>(createStruct->lpCreateParams);
					SetWindowLongPtr(windowHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
				}
				break;
			case WindowMessage::CREATE:
				// Create child controls
				// Create device contexts, gdi objects, or drawing resources
				// Allocate bitmaps or other graphics resources
				// Set up internal state, position, size or other data your window needs
				// Set the style of the window
				break;
			case WindowMessage::KEY_DOWN:
				{
					BYTE keyboardState[256]{};
					bool successfullyGotKeyboardState = GetKeyboardState(keyboardState);
					assert(successfullyGotKeyboardState && "Failed to get keyboard state.");

					UINT scanCode = (longParameter >> 16) & 0xFF;
					WORD asciiChar;
					int result = ToAscii(static_cast<UINT>(wordParameter), scanCode, keyboardState, &asciiChar, 0);

					if (result > 0) {
						char c = static_cast<char>(asciiChar);
						std::cout << "Character typed: " << c << std::endl;
					}
				}
				break;
			case WindowMessage::KEY_UP:
				break;
			case WindowMessage::LEFT_BUTTON_DOWN:
				{
					//RectI windowRect = window->getRect();
					//windowRect.topLeft += glm::vec2(10, 0);
					//window->setRect(windowRect);
				}
				break;
			case WindowMessage::LEFT_BUTTON_UP:
				break;
			case WindowMessage::CLOSE:
				std::cout << "Exit button pressed" << std::endl;
				DestroyWindow(windowHandle);
				return 0; // Prevents the default behavior of closing the window
			case WindowMessage::DESTROY: // Window is being destroyed
				std::cout << "Destroying window" << std::endl;
				PostQuitMessage(0); // Tells the message loop to end.
				return 0;
			case WindowMessage::PAINT:
			{

				PAINTSTRUCT paintStruct{};
				HDC deviceContext = BeginPaint(windowHandle, &paintStruct);

				// Your drawing code goes here
				{
					// Place any drawing code here
					HBRUSH backgroundBrush = CreateSolidBrush(RGB(38, 38, 38));
					FillRect(deviceContext, &paintStruct.rcPaint, backgroundBrush);
					{
						HFONT hFont = CreateFontA(
							32,                // Height in logical units (controls size)
							0,                 // Width (0 = auto)
							0, 0,              // Angle/orientation
							FW_NORMAL,         // Weight (FW_BOLD for bold)
							FALSE, FALSE, FALSE,
							ANSI_CHARSET,
							OUT_DEFAULT_PRECIS,
							CLIP_DEFAULT_PRECIS,
							DEFAULT_QUALITY,
							DEFAULT_PITCH | FF_SWISS,
							"Arial"
						);

						// Select font into the DC
						HFONT oldFont = (HFONT)SelectObject(deviceContext, hFont);

						TextOutA(deviceContext, 5, 5, "Hello, Win32!", 13);

						// Restore old font (important!)
						SelectObject(deviceContext, oldFont);
						DeleteObject(hFont);

					}
					DeleteObject(backgroundBrush);
				}
				// Your drawing code ends here
				EndPaint(windowHandle, &paintStruct);

			}
			return 0;

		}

		return DefWindowProc(windowHandle, messageId, wordParameter, longParameter);
	}

	// class Window

	// Static | public

	// Properties
	const std::wstring Window::S_CLASS_NAME{ L"Window" };
	HBRUSH Window::s_backgroundBrush{ nullptr };
	std::wstring Window::s_defaultWindowTitle{ L"Window" };
	int Window::defaultX{ 0 }, Window::defaultY{ 0 }, Window::defaultWidth{ 800 }, Window::defaultHeight{ 600 };

	// Static | private

	// Properties
	size_t Window::s_windowCount{ 0 };

	// Static | public

	// Functions
	bool Window::s_registerWindowClass() {
		// Create and register window class
		WNDCLASSEX windowClass{};
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClass.lpfnWndProc = windowProcedure;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = GetModuleHandle(nullptr);
		windowClass.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
		windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		s_backgroundBrush = CreateSolidBrush(RGB(38, 38, 38));
		windowClass.hbrBackground = s_backgroundBrush;
		windowClass.lpszMenuName = nullptr;
		windowClass.lpszClassName = S_CLASS_NAME.c_str();
		windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
		bool registedClassSuccessfully = RegisterClassEx(&windowClass);
		assert(registedClassSuccessfully && "Failed to register window class.");

		// Set window style and canvas rectangle
		WindowStyle windowStyle = WindowStyle::CAPTION | WindowStyle::SYS_MENU | WindowStyle::MINIMIZE_BOX | WindowStyle::MAXIMIZE_BOX | WindowStyle::THICK_FRAME;
		RECT canvasRect{ defaultX, defaultY, defaultY + defaultWidth, defaultY + defaultHeight };
		bool canvasAdjustedSuccessfully = AdjustWindowRect(&canvasRect, static_cast<DWORD>(windowStyle), false);
		assert(canvasAdjustedSuccessfully && "Failed to adjust window rectangle.");

		return true;
	}
	bool Window::s_unregisterWindowClass() {
		bool unregisteredClassSuccessfully = UnregisterClass(S_CLASS_NAME.c_str(), GetModuleHandle(nullptr));
		assert(unregisteredClassSuccessfully && "Failed to unregister window class.");
		DeleteObject(s_backgroundBrush);
		return unregisteredClassSuccessfully;
	}
	bool Window::s_windowClassIsRegistered() {
		WNDCLASSEX windowClassEx{};
		bool foundClass = GetClassInfoEx(GetModuleHandle(nullptr), S_CLASS_NAME.c_str(), &windowClassEx);
		return foundClass;
	}
	WNDCLASSEX Window::s_getWindowClass() {
		WNDCLASSEX windowClassEx{};
		bool foundClass = GetClassInfoEx(GetModuleHandle(nullptr), S_CLASS_NAME.c_str(), &windowClassEx);
		assert(foundClass && "Window class not registered.");
		return windowClassEx;
	}
	size_t Window::s_getWindowCount() {
		return s_windowCount;
	}

	// Object | publie

	// Constructor / Destructor
	Window::Window() : applicationInstance(GetModuleHandle(nullptr)), windowHandle(nullptr) {
		// Create and register window class
		if (!s_windowClassIsRegistered())
			s_registerWindowClass();

		// Set window style and canvas rectangle
		DWORD style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME;
		RECT canvasRect{ defaultX, defaultY, defaultX + defaultWidth, defaultY + defaultHeight };
		bool canvasAdjustedSuccessfully = AdjustWindowRect(&canvasRect, style, false);
		assert(canvasAdjustedSuccessfully && "Failed to adjust window rectangle.");

		windowHandle = CreateWindowEx(0, S_CLASS_NAME.c_str(), s_defaultWindowTitle.c_str(), style, defaultX, defaultY, defaultWidth, defaultHeight, nullptr, nullptr, applicationInstance, this);
		assert(windowHandle != nullptr && "windowHandle == nullptr. Failed to create window.");
		ShowWindow(windowHandle, SW_SHOW);

		s_windowCount++;
	}
	Window::~Window() {
		if (windowHandle) {
			// UnregsiterClass(className.c_str()) could be called here if needed
			DestroyWindow(windowHandle);
			windowHandle = nullptr;
		}

		s_windowCount--;
	}

	// Getters
	std::wstring Window::getTitle() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		std::wstring title(256, L'\0');
		int length = GetWindowTextW(windowHandle, title.data(), static_cast<int>(title.size()));
		return title.substr(0, length);
	}
	WindowStyle Window::getStyle() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		LONG style = GetWindowLong(windowHandle, GWL_STYLE);
		return static_cast<WindowStyle>(style);
	}
	WindowStyle Window::getExtendedStyle() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		LONG exStyle = GetWindowLong(windowHandle, GWL_EXSTYLE);
		return static_cast<WindowStyle>(exStyle);
	}
	RectI Window::getRect() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		RECT rect{};
		GetWindowRect(windowHandle, &rect);
		return RectI(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
	}
	int Window::getx() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		RECT rect{};
		GetWindowRect(windowHandle, &rect);
		return rect.left;
	}
	int Window::gety() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		RECT rect{};
		GetWindowRect(windowHandle, &rect);
		return rect.top;
	}
	int Window::getWidth() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		RECT rect{};
		GetWindowRect(windowHandle, &rect);
		return rect.right - rect.left;
	}
	int Window::getHeight() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		RECT rect{};
		GetWindowRect(windowHandle, &rect);
		return rect.bottom - rect.top;
	}
	HDC Window::getDeviceContext() const {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			return GetDC(windowHandle);
		}
		return nullptr;
	}

	
	// Setters
	void Window::setTitle(const std::string& newTitle) {
		std::wstring title = std::wstring(newTitle.begin(), newTitle.end());
		if (windowHandle)
			SetWindowText(windowHandle, title.c_str());
	}
	void Window::setStyle(WindowStyle style) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			SetWindowLong(windowHandle, GWL_STYLE, static_cast<LONG>(style));
			SetWindowPos(windowHandle, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
		}
	}
	void Window::setRect(const RectI& rect) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			SetWindowPos(windowHandle, nullptr, rect.topLeft.x, rect.topLeft.y, rect.size.x, rect.size.y, SWP_NOZORDER | SWP_NOACTIVATE);
		}
	}
	void Window::setPosition(int x, int y) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			RECT rect{};
			GetWindowRect(windowHandle, &rect);
			int width = rect.right - rect.left;
			int height = rect.bottom - rect.top;
			SetWindowPos(windowHandle, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
		}
	}
	void Window::setSize(int width, int height) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			RECT rect{};
			GetWindowRect(windowHandle, &rect);
			int x = rect.left;
			int y = rect.top;
			SetWindowPos(windowHandle, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
		}
	}
	
	// Functions
	bool Window::processMessages() {
		MSG message{};
		while (PeekMessage(&message, nullptr, 0U, 0U, PM_REMOVE)) {
			if (message.message == WM_QUIT)
				return false;

			TranslateMessage(&message);
			DispatchMessage(&message); // Calls the windowProcedure function
		}

		return true;
	}
	bool Window::addStyle(WindowStyle style) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			WindowStyle currentWindowStyle = getStyle();
			WindowStyle newWindowStyle = currentWindowStyle | style;
			SetWindowLong(windowHandle, GWL_STYLE, static_cast<long>(newWindowStyle));
			SetWindowPos(windowHandle, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

			return true;
		}
		return false;
	}
	bool Window::removeStyle(WindowStyle style) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			WindowStyle currentWindowStyle = getStyle();
			WindowStyle newWindowStyle = currentWindowStyle & ~style;
			SetWindowLong(windowHandle, GWL_STYLE, static_cast<long>(newWindowStyle));
			SetWindowPos(windowHandle, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

			return true;
		}
		return false;
	}
	void Window::redraw() {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		if (windowHandle != nullptr) {
			InvalidateRect(windowHandle, nullptr, TRUE);
			UpdateWindow(windowHandle);
		}
	}
	void Window::releaseDeviceContext(HDC deviceContext) {
		assert(windowHandle != nullptr && "windowHandle == nullptr");
		assert(deviceContext != nullptr && "deviceContext == nullptr");
		if (windowHandle != nullptr && deviceContext != nullptr) {
			ReleaseDC(windowHandle, deviceContext);
		}
	}
}
