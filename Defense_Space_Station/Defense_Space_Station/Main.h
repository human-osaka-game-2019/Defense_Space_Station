#ifndef MAIN_H_
#define MAIN_H_

#include <windows.h>

#include "../../DirectX/DirectX.h"

#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

using DX::DirectX;

extern DirectX dx;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

HWND GenerateWindow(HINSTANCE hInstance, const TCHAR* API_NAME);

#endif //MAIN_H_

