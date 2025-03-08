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


public:
	MainWnd(HINSTANCE hInstance);
	virtual ~MainWnd();

	virtual LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

	void CreateMessageHandle();
};

