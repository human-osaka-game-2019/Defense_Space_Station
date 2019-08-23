#include "../Header/Main.h"
#include "../Header/Window.h"
#include "../Header/Game.h"

#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "d3dx9.lib")

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/DirectX.lib")
#else
#pragma comment(lib, "../x64/Release/DirectX.lib")
#endif

DirectX dx;
RECT WinRect;

SCENE g_scene = Game;

INT WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ INT nCmdShow) {

	HWND hWnd;
	MSG msg;
	const TCHAR API_NAME[] = "Defence_Space_Station";

	GAME game;

	WindowSettings(hInstance, API_NAME, DISPLAY_WIDTH, DISPLAY_HEIGHT, &hWnd);
	dx.InitDirectX(hWnd, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	DWORD PrevSync = timeGetTime();
	DWORD CurrSync;

	timeBeginPeriod(1);
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			CurrSync = timeGetTime();
			if (CurrSync - PrevSync >= 1000 / 60) {
				dx.pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0f, 0);
				dx.pD3Device->BeginScene();

				dx.UpdateKeyState();

				switch (g_scene)
				{
				case Title:
					break;
				case Game:game.UpdateScene();
					break;
				case GameOver:
					break;
				case GameClear:
					break;
				default:
					break;
				}

				dx.pD3Device->EndScene();
				dx.pD3Device->Present(NULL, NULL, NULL, NULL);
				PrevSync = CurrSync;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);

	dx.AllRelease();
	return (int)msg.wParam;
}
