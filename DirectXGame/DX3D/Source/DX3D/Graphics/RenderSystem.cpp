#include <DX3D/Graphics/RenderSystem.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	auto hr = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION, &m_device, &featureLevel, &m_context);

	if FAILED(hr) {
		getLogger().log(Logger::LogLevel::Error, "Direct3D11 Initialization Failed - Failed to create D3D11 device and context.");
		throw std::runtime_error("Direct3D11 Initialization Failed - Failed to create D3D11 device and context.");
	}
}

dx3d::RenderSystem::~RenderSystem()
{
}

