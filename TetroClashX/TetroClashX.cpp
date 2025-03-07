#include "pch.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    MainWnd myWnd(hInstance);
    if (!myWnd.Create(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, L"mainWnd", L"TextroClash"))
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
