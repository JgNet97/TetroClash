#include "pch.h"
#include "Wnd.h"

Wnd::Wnd(HINSTANCE hInstance) 
	: _hInstance(hInstance), _hWnd(nullptr)
{

}

Wnd::~Wnd()
{
}

LRESULT Wnd::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Wnd* pThis = nullptr;

	if (message == WM_NCCREATE) 
	{
		LPCREATESTRUCT pCS = (LPCREATESTRUCT) lParam;
		SetLastError(0);
		pThis = (Wnd*)pCS->lpCreateParams;
		pThis->SetHandle(hWnd);

		if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pThis)) 
		{
			if (GetLastError() != 0)
			{
				return E_FAIL;
			}
		}
	}
	else 
	{
		pThis = reinterpret_cast<Wnd*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}

	if (pThis) 
	{
		return pThis->HandleMessage(message, wParam, lParam);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT Wnd::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam)
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
			TextOutW(hdc, 50, 50, L"안녕하세요", 5);
			EndPaint(_hWnd, &ps);
			return 0;
		}

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(_hWnd, message, wParam, lParam);
}

bool Wnd::Create(int width, int height, const WCHAR* className, const WCHAR* title)
{
	WNDCLASSEX wecx = {};
	wecx.cbSize = sizeof(WNDCLASSEX);
	wecx.style = CS_HREDRAW | CS_VREDRAW;
	wecx.cbClsExtra = 0;
	wecx.cbWndExtra = sizeof(LONG_PTR);
	wecx.hInstance = _hInstance;
	wecx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wecx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wecx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wecx.lpszClassName = className;
	wecx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wecx.lpfnWndProc = Wnd::WndProc;  // 정적함수
	RegisterClassEx(&wecx);

	_hWnd = CreateWindow(className, title, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		, 0, 0, width, height
		, NULL, NULL, _hInstance, this);


	return _hWnd != NULL;
}

void Wnd::Show(int nCmdShow)
{
	ShowWindow(_hWnd, nCmdShow);
	UpdateWindow(_hWnd);
}

HWND Wnd::GetHandle()
{
	return _hWnd;
}

void Wnd::SetHandle(HWND hWnd)
{
	_hWnd = hWnd;
}
