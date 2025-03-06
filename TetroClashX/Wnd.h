#pragma once
/***********
	Wnd
***********/
class Wnd
{
protected:
	HINSTANCE	_hInstance;
	HWND		_hWnd;

public:
	Wnd(HINSTANCE hInstance);
	~Wnd();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

	bool Create(int width, int height, const WCHAR* className, const WCHAR* title);
	void Show(int nCmdShow);
	HWND GetHandle();
	void SetHandle(HWND hWnd);
};