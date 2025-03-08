#include "pch.h"
#include "D2DWnd.h"

D2DWnd::D2DWnd(HINSTANCE hInstance) : Wnd(hInstance)
{
}

D2DWnd::~D2DWnd()
{
	if (_rt)
		_rt->Release();

	if (_crt)
		_crt->Release();
}

bool D2DWnd::Create(int width, int height, const WCHAR* className, const WCHAR* title)
{
	bool ok = Wnd::Create(width, height, className, title);

	if (!ok)
		return ok;
	
	D2DCore::GetInstance()->CreateRT(_hWnd, &_rt);
	D2DCore::GetInstance()->CreateCRT(_rt, &_crt);

	return true;
}

void D2DWnd::RegisterColor(unsigned int color, float opacity)
{
	ID2D1SolidColorBrush* brush = nullptr;

	D2DCore::GetInstance()->CreateBrush(_crt, D2D1::ColorF(color, opacity), &brush);
	_colors.insert({ color, brush });
}

void D2DWnd::BeginDraw()
{
	_crt->BeginDraw();
	_crt->Clear(D2D1::ColorF(D2D1::ColorF::DarkSlateGray));
}

void D2DWnd::DrawBitmap(ID2D1Bitmap* bitmap)
{
	D2D1_RECT_F destRect = D2D1::RectF(
		0, 
		0, 
		bitmap->GetSize().width, 
		bitmap->GetSize().height
	);

	_crt->DrawBitmap(bitmap);
}

void D2DWnd::EndDraw(ID2D1Bitmap* bitmap)
{
	_crt->EndDraw();
	_crt->GetBitmap(&bitmap);
	_rt->BeginDraw();

	RECT rect;
	GetClientRect(_hWnd, &rect);
	D2D1_RECT_F rt_dest = { rect.left, rect.top, rect.right, rect.bottom };

	if (bitmap)
		_rt->DrawBitmap(bitmap, rt_dest, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

	_rt->EndDraw();
}

ID2D1SolidColorBrush* D2DWnd::GetColorBrush(unsigned int color)
{
	const auto& ret = _colors.find(color);
	return ret->second;
}
