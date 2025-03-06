#include "pch.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Wnd myWnd(hInstance);
    if (!myWnd.Create(500, 300, L"ddd", L"ddd")) 
        return 0;

    myWnd.Show(nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
