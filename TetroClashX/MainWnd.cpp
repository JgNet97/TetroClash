#include "pch.h"
#include "MainWnd.h"

MainWnd::MainWnd(HINSTANCE hInstance) : Wnd(hInstance)
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
		TextOutW(hdc, 50, 50, L"�ȳ��ϼ���2", 6);
		EndPaint(_hWnd, &ps);
		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(_hWnd, message, wParam, lParam);
}

/*********
	INIT
**********/
void MainWnd::CreateMessageHandle()
{
	_hFont = CreateFont(
		24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial"
	);

	_hEdit = CreateWindowEx(
		0, L"EDIT", L"", // �� �Է� â
		WS_CHILD | WS_VISIBLE  | ES_AUTOHSCROLL, // �⺻ �Ӽ�
		50, 50, 200, 100, // ��ġ�� ũ��
		_hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);

	// �Է� �ڽ��� ��Ʈ ����
	SendMessage(_hEdit, WM_SETFONT, (WPARAM)_hFont, TRUE);
}
