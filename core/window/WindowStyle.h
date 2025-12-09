#pragma once

// Dependenncies | OS
#include <Windows.h>

namespace ui {
	enum class WindowStyle : unsigned int {
		// Standard window styles
		OVERLAPPED = WS_OVERLAPPED,
		POPUP = WS_POPUP,
		CHILD = WS_CHILD,
		MINIMIZE = WS_MINIMIZE,
		VISIBLE = WS_VISIBLE,
		DISABLED = WS_DISABLED,
		CLIP_SIBLINGS = WS_CLIPSIBLINGS,
		CLIP_CHILDREN = WS_CLIPCHILDREN,
		MAXIMIZE = WS_MAXIMIZE,
		CAPTION = WS_CAPTION,
		BORDER = WS_BORDER,
		DLG_FRAME = WS_DLGFRAME,
		VERTICAL_SCROLL = WS_VSCROLL,
		HORIZONTAL_SCROLL = WS_HSCROLL,
		SYS_MENU = WS_SYSMENU,
		THICK_FRAME = WS_THICKFRAME,
		GROUP = WS_GROUP,
		TAB_STOP = WS_TABSTOP,

		MINIMIZE_BOX = WS_MINIMIZEBOX,
		MAXIMIZE_BOX = WS_MAXIMIZEBOX,

		TILED = WS_OVERLAPPED,
		ICONIC = WS_MINIMIZE,
		SIZE_BOX = WS_THICKFRAME,
		TILED_WINDOW = WS_OVERLAPPEDWINDOW,

		// Common composite styles
		OVERLAPPED_WINDOW = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,

		POPUP_WINDOW = WS_POPUP | WS_BORDER | WS_SYSMENU,
		CHILD_WINDOW = WS_CHILD,

		// Extended window styles
		EX_DLG_MODAL_FRAME = WS_EX_DLGMODALFRAME,
		EX_NO_PARENT_NOTIFY = WS_EX_NOPARENTNOTIFY,
		EX_TOPMOST = WS_EX_TOPMOST,
		EX_ACCEPT_FILES = WS_EX_ACCEPTFILES,
		EX_TRANSPARENT = WS_EX_TRANSPARENT,
		EX_MDI_CHILD = WS_EX_MDICHILD,
		EX_TOOL_WINDOW = WS_EX_TOOLWINDOW,
		EX_WINDOW_EDGE = WS_EX_WINDOWEDGE,
		EX_CLIENT_EDGE = WS_EX_CLIENTEDGE,
		EX_CONTEXT_HELP = WS_EX_CONTEXTHELP,

		EX_RIGHT = WS_EX_RIGHT,
		EX_LEFT = WS_EX_LEFT,
		EX_RTL_READING = WS_EX_RTLREADING,
		EX_LTR_READING = WS_EX_LTRREADING,
		EX_LEFTS_CROLLBAR = WS_EX_LEFTSCROLLBAR,
		EX_RIGHT_SCROLLBAR = WS_EX_RIGHTSCROLLBAR,

		EX_CONTROL_PARENT = WS_EX_CONTROLPARENT,
		EX_STATIC_EDGE = WS_EX_STATICEDGE,
		EX_APP_WINDOW = WS_EX_APPWINDOW,

		EX_OVERLAPPED_WINDOW = WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE,
		EX_PALETTE_WINDOW = WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST

		// Refer to WinUser.h for more extended styles that you might have missed.
		// They are after EX_PALETTE_WINDOW
	};

	constexpr WindowStyle operator|(WindowStyle a, WindowStyle b) {
		return static_cast<WindowStyle>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));
	}
	constexpr WindowStyle operator&(WindowStyle a, WindowStyle b) {
		return static_cast<WindowStyle>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b));
	}
	constexpr WindowStyle& operator|=(WindowStyle& a, WindowStyle b) {
		a = a | b;
		return a;
	}
	constexpr WindowStyle& operator&=(WindowStyle& a, WindowStyle b) {
		a = a & b;
		return a;
	}
	constexpr WindowStyle operator~(WindowStyle a) {
		return static_cast<WindowStyle>(~static_cast<unsigned int>(a));
	}
}

/*
Common Composite Styles
Style	Combination
WS_OVERLAPPEDWINDOW	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
WS_POPUPWINDOW	WS_POPUP | WS_BORDER | WS_SYSMENU
WS_CHILDWINDOW	WS_CHILD
*/