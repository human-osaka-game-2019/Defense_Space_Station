#include <Windows.h>

#include "../Main.h"

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam) {
	switch (uMsg) {
	case WM_ACTIVATE:
		dx.is_Active = (LOWORD(wParam) != 0);
		break;

	case WM_DESTROY:
		dx.AllRelease();
		PostQuitMessage(0);
		hwnd = NULL;
		return 0;

	case WM_SIZE:
		if (dx.D3dPresentParameters.Windowed != TRUE)
			break;
		if (dx.pD3Device || wParam == SIZE_MINIMIZED)
			break;
		dx.D3dPresentParameters.BackBufferWidth = LOWORD(lParam);
		dx.D3dPresentParameters.BackBufferHeight = HIWORD(lParam);
		if (dx.DeviceLost)
			break;
		if (wParam == SIZE_MAXIMIZED || wParam == SIZE_RESTORED)
			dx.ChangeWindowSize(hwnd);
		break;

	case WM_SYSKEYDOWN:
		switch (wParam) {
		case VK_RETURN:
			dx.ChangeDisplayMode(hwnd, WinRect);
			return 0;
		case VK_F4:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			return 0;
		default:
			return 0;
		}
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void WindowSettings(HINSTANCE hInstance, CONST CHAR* WindowName, int WindowWidth, int WindowHeight, HWND* hWnd) {

	WNDCLASSEX windowclass;

	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hInstance = hInstance;
	windowclass.lpszClassName = WindowName;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.style = CS_HREDRAW | CS_VREDRAW;
	windowclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowclass.hIconSm = NULL;
	windowclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowclass.lpszMenuName = NULL;
	windowclass.cbClsExtra = 0;
	windowclass.cbWndExtra = 0;
	windowclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClassEx(&windowclass);

	if (dx.WinMode) {
		*hWnd = CreateWindow(
			WindowName,
			WindowName,
			WS_OVERLAPPEDWINDOW,
			0,
			0,
			WindowWidth,
			WindowHeight,
			NULL,
			NULL,
			hInstance,
			NULL);
	}
	else {
		*hWnd = CreateWindow(
			WindowName,
			WindowName,
			WS_POPUP | WS_VISIBLE,
			0,
			0,
			DISPLAY_WIDTH,
			DISPLAY_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL
		);
	}

	ShowWindow(*hWnd, SW_SHOW);
	UpdateWindow(*hWnd);

}