#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>

#include "WinApp.h"

class DirectXCommon
{
public:
	void Initialize();

	void InitializeDevice();

	void InitializeCommand();

	void InitializeSwapchain();

	void InitializeRenderTargetView();

	void InitializeDepthBuffer();

	void InitializeFence();

	void PreDraw();

	void PostDraw();

	ID3D12Device* GetDevice() const { return device.Get(); }
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

private:

	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	// デスクリプタヒープの設定
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	// 頂点バッファビューの作成
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	// インデックスバッファビューの作成
	D3D12_INDEX_BUFFER_VIEW ibView{};

	D3D12_RESOURCE_BARRIER barrierDesc{};

	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
	Microsoft::WRL::ComPtr<ID3D12Resource> constBuffMaterial;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvHeap;
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;

	WinApp* winApp = nullptr;

	size_t textureIndex = 0;

	UINT64 fenceVal = 0;
};

