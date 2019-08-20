#include"Header/Window.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ INT nCmdShow) {

	HWND hWnd;

	WindowSettings(hInstance, "Defence_Space_Station", 1920, 1080, &hWnd);

	while (true)
	{
		MSG msg;

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

	return 0;

};
