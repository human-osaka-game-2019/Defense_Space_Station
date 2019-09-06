#include "../Header/Main.h"
#include "../Header/Window.h"
#include "../Header/Title.h"
#include "../Header/Game.h"
#include "../Header/GameClear.h"
#include "../Header/GameOver.h"

#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "d3dx9.lib")

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/DirectX.lib")
#pragma comment(lib, "SoundLib/Debug/x64/SoundLib.lib")
#else
#pragma comment(lib, "../x64/Release/DirectX.lib")
#pragma comment(lib, "SoundLib/Release/x64/SoundLib.lib")
#endif

DirectX dx;
SoundLib::SoundsManager soundsManager;
RECT WinRect;

SCENE g_scene = GameClear;

INT WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ INT nCmdShow) {

	HWND hWnd;
	MSG msg;
	const TCHAR API_NAME[] = "Defence_Space_Station";

	TITLE title;
	GAME game;
	GAME_CLEAR gameclear;
	GAME_OVER gameover;

	WindowSettings(hInstance, API_NAME, DISPLAY_WIDTH, DISPLAY_HEIGHT, &hWnd);
	dx.InitDirectX(hWnd, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	soundsManager.Initialize();

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
				case Title:title.UpdateScene();
					break;
				case Game:game.UpdateScene();
					break;
				case GameOver:gameover.UpdateScene();
					break;
				case GameClear:gameclear.UpdateScene();
					break;
				default:
					MessageBox(0, "シーンエラー\n", "", MB_OK);
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
