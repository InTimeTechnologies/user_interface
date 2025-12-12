# user_interface

A lightweight C++ library providing **Win32-based UI abstractions** aiming to be used by in_time_engine on Windows platform, but it is being designed to be used as a standalon user interface library.  
It wraps core Win32 functionality (windows, fonts, device contexts) and provides type-safe, RAII-managed classes for creating GUI elements and rendering text.

## Disclaimer

user_interface is under early and active development. It is not ready for release nor deployment.

## Features

- **Window abstraction**
  - RAII wrapper for `HWND`
  - Message loop management
  - Input callback handling

- **Font management**
  - Load fonts from system or font files (`.ttf`)
  - RAII-managed `HFONT` objects
  - Supports font weight, size, charset, and color
  - Bitwise operations on `Weight` enum for combined styles

- **Device context handling**
  - Safe `HDC` selection and restoration
  - Easy text rendering via `TextOut` and `DrawText`

- **Widgets (planned / basic)**
  - Labels, buttons, and other UI controls
  - Works with engine’s scene and rendering loop

- **Cross-platform abstraction ready**
  - Core API is designed so Win32-specific details are contained in the library
  - Engine code can remain platform-agnostic

## Building

```bash
git clone --recurse-submodules https://github.com/InTimeTechnologies/user_interface.git
```

## Contributing

Follow RAII and type-safe patterns for all Win32 objects.

Use enum class to wrap around Windows #defines for user convenience and enforce proper usage of the code.

All resources (HFONT, HDC) must be properly released.

License

MIT License © 2025 Christopher Barrios Agosto
