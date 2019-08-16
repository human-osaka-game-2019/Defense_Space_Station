#ifndef WINDOW_H_
#define WINDOW_H_

#include<windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void WindowSettings(HINSTANCE hInstance, CONST CHAR* WindowName, int WindowWidth, int WindowHeight, HWND* hWnd);


#endif 
