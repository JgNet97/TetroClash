#pragma once
#include "D2DWnd.h"
/********************
	MainWnd
********************/
class MainWnd : public D2DWnd
{
private:
	// 로그인 관련 UI
	HWND _loginPanel;
	HWND _hUserIdInput;
	HWND _hUserPwInput;
	HFONT _hFont;
	D2DBitmap* _loginBg;

public:
	MainWnd(HINSTANCE hInstance);
	virtual ~MainWnd();

	virtual LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

	void CreateMessageHandle();
	virtual bool Create(int width, int height, const WCHAR* className, const WCHAR* title);
};

