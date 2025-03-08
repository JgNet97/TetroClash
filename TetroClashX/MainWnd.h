#pragma once
#include "D2DWnd.h"
/********************
	MainWnd
********************/
class MainWnd : public D2DWnd
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

