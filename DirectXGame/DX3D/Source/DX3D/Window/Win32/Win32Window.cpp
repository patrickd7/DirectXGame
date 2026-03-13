#include "DX3D/Window/Window.h"
#include "Windows.h"
#include <stdexcept>

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	
}




dx3d::Window::Window(): Base()
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindow";
			wc.lpfnWndProc = &WindowProc;
			return RegisterClassEx(&wc);
		};

	
	static const auto windowClassId = std::invoke(registerWindowClassFunction);
	if (!windowClassId)
	{
		throw std::runtime_error("RegisterClassEx - Failed to register window class");
	}

	RECT rc{ 0,0,1280,720 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
	m_windowHandle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"DirectXGame | C++ 3D Game Tutorial Series", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

	if (!m_windowHandle)
	{
		throw std::runtime_error("CreateWindowEx - Failed to create window");
	}

	ShowWindow(static_cast<HWND>(m_windowHandle), SW_SHOW);
}

dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_windowHandle));
}
