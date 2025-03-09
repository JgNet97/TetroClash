#include "pch.h"
#include "MainWnd.h"
MainWnd::MainWnd(HINSTANCE hInstance) : D2DWnd(hInstance)
{
}

MainWnd::~MainWnd()
{
}

LRESULT MainWnd::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		return 0;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(_hWnd, &ps);
		ID2D1Bitmap* id2d1Bitmap = nullptr;
		BeginDraw();
		SceneManager::GetInstance()->Render(_crt);
		EndDraw(id2d1Bitmap);
		EndPaint(_hWnd, &ps);
		return 0;
	}

	case WM_LBUTTONDOWN:
	{
		return 0;
	}

	case WM_MOUSEMOVE:
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		wchar_t buffer[64];
		swprintf_s(buffer, L"Mouse Position: (%d, %d)", xPos, yPos);
		SetWindowText(_hWnd, buffer);
		return 0;
	}

	case WM_COMMAND:
	{
		int code = LOWORD(wParam);
		switch (code)
		{
		case 1:
			// 로그인 버튼
			break;
		}


		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(_hWnd, message, wParam, lParam);
}

bool MainWnd::Create(int width, int height, const WCHAR* className, const WCHAR* title)
{
	bool ok = D2DWnd::Create(width, height, className, title);
	if (!ok)
		return ok;
	Resources::GetInstance()->loginBackgroundBitmap = D2DCore::GetInstance()->CreateD2Bitmap(_crt, L"./image/login_bg.png");
	Resources::GetInstance()->logoBitmap = D2DCore::GetInstance()->CreateD2Bitmap(_crt, L"./image/logo.png");
	SceneManager::GetInstance()->Init(_hWnd, _hInstance);
	return true;
}
