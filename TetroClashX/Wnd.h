#pragma once
/***********
	Wnd
***********/
class Wnd
{
protected:
	WCHAR		_className[30] = L"";
	WCHAR		_title[30] = L"";
	HINSTANCE	_hInstance;
	HWND		_hWnd;

public:
	Wnd(HINSTANCE hInstance, const WCHAR* className, const WCHAR* title);
	~Wnd();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

	bool Create(int width, int height);
	void Show(int nCmdShow);
	HWND GetHandle();
};