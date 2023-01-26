#pragma once

#include <Windows.h>

class WinApp
{
public:
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	static const int window_width = 1280;

	static const int window_height = 720;

public:
	void Initialize();

	void Update();

	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstace() const { return w.hInstance; }

private:
	HWND hwnd = nullptr;

	WNDCLASSEX w{};
};