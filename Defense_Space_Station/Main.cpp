#include "Main.h"
#include "Header/Window.h"

#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "d3dx9.lib")

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/DirectX.lib")
#else
#pragma comment(lib, "../x64/Release/DirectX.lib")
#endif

DirectX dx;
RECT WinRect;

INT WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ INT nCmdShow) {

	HWND hWnd;
	MSG msg;
	const TCHAR API_NAME[] = "Defence_Space_Station";

	WindowSettings(hInstance, API_NAME, DISPLAY_WIDTH, DISPLAY_HEIGHT, &hWnd);
	dx.InitDirectX(hWnd, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	while (true)
	{
		ZeroMemory(&msg, sizeof(msg));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				//ÉÅÉCÉìèàóù
			}
		}
	}

	dx.AllRelease();
	return (int)msg.wParam;

};
