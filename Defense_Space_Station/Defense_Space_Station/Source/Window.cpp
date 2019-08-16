#include<Windows.h>

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam) {

	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);

		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
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

	ShowWindow(*hWnd, SW_SHOW);
	UpdateWindow(*hWnd);

}