#pragma once
#include "Wnd.h"
/********************
	D2DWnd
********************/
class D2DWnd : public Wnd
{
protected:
	ID2D1HwndRenderTarget*							_rt;
	ID2D1BitmapRenderTarget*						_crt;
	std::map<unsigned int, ID2D1SolidColorBrush*>	_colors;

public:
	D2DWnd(HINSTANCE hInstance);
	virtual ~D2DWnd();
	
	virtual bool Create(int width, int height, const WCHAR* className, const WCHAR* title);
	void RegisterColor(unsigned int color, float opacity = 1);
	void BeginDraw();
	void DrawBitmap(ID2D1Bitmap* bitmap);
	void EndDraw(ID2D1Bitmap* bitmap);

	ID2D1BitmapRenderTarget* GetCRT() { return _crt; }
	ID2D1SolidColorBrush* GetColorBrush(unsigned int color);
};

