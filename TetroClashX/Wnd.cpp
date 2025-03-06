#include "pch.h"
#include "Wnd.h"

Wnd::Wnd(HINSTANCE hInstance, const WCHAR* className, const WCHAR* title) 
	: _hInstance(hInstance), _hWnd(nullptr)
{
	 wcscpy_s(_className, className);
	 wcscpy_s(_title, title);
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
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(_hWnd, &ps);
			TextOut(hdc, 50, 50, L"Hello, OOP!", 12);
			EndPaint(_hWnd, &ps);
			return 0;
		}

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(_hWnd, message, wParam, lParam);
}

bool Wnd::Create(int width, int height)
{

	WNDCLASSEX wecx;
	wecx.cbSize = sizeof(WNDCLASSEX);
	wecx.style = CS_HREDRAW | CS_VREDRAW;
	wecx.cbClsExtra = 0;
	wecx.cbWndExtra = sizeof(LONG_PTR);
	wecx.hInstance = _hInstance;
	wecx.hIcon = LoadIcon(_hInstance, IDI_APPLICATION);
	wecx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wecx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wecx.lpszClassName = _className;
	wecx.hIconSm = LoadIcon(wecx.hInstance, IDI_APPLICATION);
	wecx.lpfnWndProc = Wnd::WndProc;  // �����Լ�
	if (!RegisterClassEx(&wecx))
	{
		MessageBox(NULL,
			L"Call to RegisterClassEx Main failed!",
			L"Windows Desktop Guided Tour",
			NULL);
		return 0;
	}

	_hWnd = CreateWindow(_className, _title, WS_OVERLAPPEDWINDOW
		, 0, 0, width, height
		, NULL, NULL, _hInstance, this);

	if (_hWnd == NULL) 
	{
		DWORD errCode = GetLastError();
		wchar_t errMsg[256];
		swprintf(errMsg, 256, L"CreateWindowEx failed! Error Code: %lu", errCode);
		MessageBox(NULL, errMsg, L"Error", MB_OK | MB_ICONERROR);
	}

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
