#include "Main.h"

#pragma comment(lib, "winmm.lib")

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/DirectX.lib")
#else
#pragma comment(lib, "../x64/Release/DirectX.lib")
#endif

DirectX dx;
RECT WinRect;

VOID MainLoop(MSG* msg);

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdlinem, _In_ INT nCmdShow) {
	const TCHAR API_NAME[] = _T("Defence_Space_Station");

	MSG msg;
	HWND hWnd = GenerateWindow(hInstance, API_NAME);
	dx.InitDirectX(hWnd, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	MainLoop(&msg);

	dx.AllRelease();
	return (INT)msg.wParam;
}

VOID MainLoop(MSG* msg) {
	DWORD PrevSync = timeGetTime();
	DWORD CurrSync;

	timeBeginPeriod(1);
	ZeroMemory(msg, sizeof(msg));
	while (msg->message != WM_QUIT) {
		if (PeekMessage(msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(msg);
			DispatchMessage(msg);
		}
		else {
			CurrSync = timeGetTime();
			if (CurrSync - PrevSync >= 1000 / 60) {
				dx.pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0f, 0);
				dx.pD3Device->BeginScene();

				dx.UpdateKeyState();

				dx.pD3Device->EndScene();
				dx.pD3Device->Present(NULL, NULL, NULL, NULL);
				PrevSync = CurrSync;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_ACTIVATE:
		dx.is_Active = (LOWORD(wp) != 0);
		break;

	case WM_DESTROY:
		dx.AllRelease();
		PostQuitMessage(0);
		hWnd = NULL;
		return 0;

	case WM_SIZE:
		if (dx.D3dPresentParameters.Windowed != TRUE)
			break;
		if (dx.pD3Device || wp == SIZE_MINIMIZED)
			break;
		dx.D3dPresentParameters.BackBufferWidth = LOWORD(lp);
		dx.D3dPresentParameters.BackBufferHeight = HIWORD(lp);
		if (dx.DeviceLost)
			break;
		if (wp == SIZE_MAXIMIZED || wp == SIZE_RESTORED)
			dx.ChangeWindowSize(hWnd);
		break;

	case WM_SYSKEYDOWN:
		switch (wp) {
		case VK_RETURN:
			dx.ChangeDisplayMode(hWnd, WinRect);
			return 0;
		case VK_F4:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		default:
			return 0;
		}
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

HWND GenerateWindow(HINSTANCE hInstance, const TCHAR* API_NAME) {
	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDC_ICON);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = API_NAME;

	RegisterClass(&Wndclass);

	if (dx.WinMode) {
		return CreateWindow(
			API_NAME,
			API_NAME,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			DISPLAY_WIDTH,
			DISPLAY_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL
		);
	}
	else {
		return CreateWindow(
			API_NAME,
			API_NAME,
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
}