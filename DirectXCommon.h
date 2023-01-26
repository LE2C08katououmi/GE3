#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

#include "WinApp.h"

class DirectXCommon
{
public:
	void Initialize();

	void InitializeDevice();

	void InitializeCommand();

	void InitializeSwapchain();

private:
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	WinApp* winApp = nullptr;
};

