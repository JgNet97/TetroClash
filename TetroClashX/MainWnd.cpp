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
		CreateMessageHandle();
		return 0;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(_hWnd, &ps);
		ID2D1Bitmap* id2d1Bitmap = nullptr;
		BeginDraw();
		_crt->DrawBitmap(_loginBg->GetD2D1Bitmap(), {0,0,1920,1080});


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

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(_hWnd, message, wParam, lParam);
}

void MainWnd::CreateMessageHandle()
{
	_loginPanel = CreateWindow(L"STATIC", NULL, WS_CHILD | WS_VISIBLE,
		710, 700, 500, 270, _hWnd, NULL, _hInstance, NULL);

	_hFont = CreateFont(
		24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial"
	);

	HWND hUserIdText = CreateWindow(L"STATIC", L"���̵�",
		WS_CHILD | WS_VISIBLE | SS_CENTER, 
		0, 55, 200, 30, 
		_loginPanel, NULL, _hInstance, NULL);

	HWND hUserPwText = CreateWindow(L"STATIC", L"�н�����",
		WS_CHILD | WS_VISIBLE | SS_CENTER,
		0, 125, 200, 30,
		_loginPanel, NULL, _hInstance, NULL);

	_hUserIdInput = CreateWindowEx(
		0, L"EDIT", L"", // �� �Է� â
		WS_CHILD | WS_VISIBLE  | ES_AUTOHSCROLL, // �⺻ �Ӽ�
		150, 50, 250, 45, // ��ġ�� ũ��
		_loginPanel, (HMENU)1, GetModuleHandle(NULL), NULL);

	_hUserPwInput = CreateWindowEx(
		0, L"EDIT", L"", // �� �Է� â
		WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, // �⺻ �Ӽ�
		150, 120, 250, 45, // ��ġ�� ũ��
		_loginPanel, (HMENU)1, GetModuleHandle(NULL), NULL);

	HWND hButton = CreateWindow(
		L"BUTTON", L"�α���",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		50, 190, 350, 50,  // (X, Y, Width, Height)
		_loginPanel, (HMENU)1, _hInstance, NULL);

	SendMessage(_hUserIdInput, WM_SETFONT, (WPARAM)_hFont, TRUE);
	SendMessage(_hUserPwInput, WM_SETFONT, (WPARAM)_hFont, TRUE);
	SendMessage(hUserIdText, WM_SETFONT, (WPARAM)_hFont, TRUE);
	SendMessage(hUserPwText, WM_SETFONT, (WPARAM)_hFont, TRUE);
	SendMessage(hButton, WM_SETFONT, (WPARAM)_hFont, TRUE);
}

bool MainWnd::Create(int width, int height, const WCHAR* className, const WCHAR* title)
{
	bool ok = D2DWnd::Create(width, height, className, title);
	
	if (!ok)
		return ok;
	
	_loginBg = D2DCore::GetInstance()->CreateD2Bitmap(_crt, L"./image/login_bg.png");
	return true;
}
