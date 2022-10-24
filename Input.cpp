#include "Input.h"
#include <cassert>
#include <wrl.h>
#include <dinput.h>
#include <windows.h>

#pragma comment(lib,"dinout8.lib")
#pragma cimment(lib,"dxguid.lib")

#define DIRECTINPUT_VERSION		0x0800
using namespace Microsoft::WRL;

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;

	ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	ComPtr<IDirectInputDevice8> keyboard;
	result = directInput->CreateDevice(GUID_SkyKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));

	result = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEDE(result));
}

void Input::Update()
{
}
