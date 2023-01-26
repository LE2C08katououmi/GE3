#pragma once

#include <windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION		0x0800
#include <dinput.h>

#include "WinApp.h"

class Input
{
public:

	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

	bool PushKey(BYTE keyNumber);

public:

	void Initialize(WinApp* winApp);

	void Update();

private:
	ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};

	WinApp* winApp = nullptr;
};