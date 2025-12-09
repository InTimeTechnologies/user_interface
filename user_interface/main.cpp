// Dependencies | std
#include <iostream>

// Dependencies | ui
#include "window/Window.h"

int main(int argc, char* argv[]) {
	std::cout << "Program operating." << std::endl;

	for (UINT vk = 0x01; vk <= 0xFE; ++vk) {
		UINT scan = MapVirtualKey(vk, MAPVK_VK_TO_VSC);

		if (scan == 0)
			continue;

		LONG lParam = (scan << 16);
		char name[64]{};

		int len = GetKeyNameTextA(lParam, name, sizeof(name));
		if (len > 0) {
			printf("VK: 0x%02X  Name: %s\n", vk, name);
		}
	}

	ui::Window* window = new ui::Window();
	ui::Window* window1 = new ui::Window();
	bool running = true;
	while (running) {
		static bool titlePrinted = false;
		if (!titlePrinted) {
			window->setTitle("My First Window");
			std::wstring title = window->getTitle();
			std::cout << "Window title: " << std::string(title.begin(), title.end()) << std::endl;
			titlePrinted = true;
		}
		if (!window->processMessages()) {
			running = false;
			std::cout << "Closing window" << std::endl;
		}
		if (!window->processMessages()) {
			running = false;
			std::cout << "Closing window1" << std::endl;
		}
		Sleep(10); // Sleep for 10 milliseconds to reduce CPU usage

	}


	std::cout << "Program terminating." << std::endl;
	return 0;
}


/*
// Dependencies | OS
#include <windows.h>

// Dependencies | std
#include <iostream>

LRESULT CALLBACK windowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hwnd, &ps);
				FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
				EndPaint(hwnd, &ps);
			}
			return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// hPreviousInstance is always NULL in Win32 apps
// lpCmdLine is the command line as a single string
// nCmdShow is a flag that says whether the main application window will be minimized, maximized, or shown normally
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpCmdLine, int nCmdShow) {
	// Typical Windows application structure
	// 1. initialization
	// 2. message loop
	// 3. cleanup

	// Initialization goes here
	const wchar_t CLASS_NAME[] = L"MyWindowClass";

	WNDCLASS wc = {};
	wc.lpfnWndProc = windowProcedure;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClass(&wc)) return -1;

	HWND hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"My First Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		nullptr, nullptr, hInstance, nullptr
	);

	if (hwnd == nullptr)
		return -1;

	ShowWindow(hwnd, nCmdShow);

	// Message loop
	MSG message = {};
	while (GetMessage(&message, nullptr, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return static_cast<int>(message.wParam);
}
*/

/*
 * Typical Windows application structure
 * 1. initialization
 * 2. message loop
 * 3. cleanup
 * 
 * Message related functions:
 * GetMessage (blocks until a message is available)
 * PeekMessage (non-blocking, checks for a message and returns immediately)
 * PostMessage (asynchronous, places a message in the message queue)
 * SendMessage 
 * 
 * Handle types:
 * HWND (handle to a window)
 * HINSTANCE (handle to an instance) (running instance of your application)
 * HDC (hanlde to a device context)
 * HBITMAP (handle to a bitmap)
 * HICON (handle to an icon)
 * HFONT (handle to a font)
 * HANDLE (generic handle often used for files, events, processes, threads, etc.)
 * 
 * Functions for windows:
 * CreateWindowEx
 * CreateWindow
 * FindWindow
 * GetForegroundWindow
 * SetForegroundWindow
 * SetWindowText
 * MoveWindow
 * ShowWindow
 * SendMEssage
 * PostMessage
 * DestroyWindow
 * 
 * Handle related functions:
 * CloseHandle
 * DestroyWindow
 * Some handle types have their own specific functions for releasing resources, e.g., DeleteObject for GDI objects.
 * 
 * Messages:
 * uMsg (message identifier) predefined numerical value that identifies the type of message (parameter in WindowProc)
 * wParam (word parameter) (additional message information) additional information about the message (parameter in WindowProc) e.g., which key was pressed WM_KEYDOWN
 * lParam (long parameter) (additional message information) additional information about the message (parameter
 * 
 * Notes:
 * Window Procedure (WindowProc) is a callback function that processes messages sent to a window.
 */

/*
// Dependencies | std
#include <iostream>

// Dependencies | core
#include "core/Rect.h"

int main(int argc, char* argv[]) {
	std::cout << "Program operating." << std::endl;
	
	ui::RectI recti{ -4, -4, 4, 4 };
	int top = recti.getTop();
	int bottom = recti.getBottom();
	int right = recti.getRight();
	int left = recti.getLeft();
	std::cout << "RectI top: " << top << ", bottom: " << bottom << ", right: " << right << ", left: " << left << std::endl;
	
	std::cout << "Program terminating." << std::endl;
	return 0;
}
*/

