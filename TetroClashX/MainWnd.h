#pragma once
#include "Wnd.h"
/********************
	MainWnd
********************/
class MainWnd : public Wnd
{
private:
	HWND _hEdit;
	HFONT _hFont;
public:
	MainWnd(HINSTANCE hInstance);
	virtual ~MainWnd();

	virtual LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

	void CreateMessageHandle();
};

