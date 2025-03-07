#include "pch.h"
#include "D2DCore.h"

D2DCore::D2DCore()
{
}

D2DCore::~D2DCore()
{
}

void D2DCore::CreateRT(HWND hWnd, ID2D1HwndRenderTarget** rt)
{
}

void D2DCore::CreateCRT(ID2D1HwndRenderTarget* rt, ID2D1BitmapRenderTarget** crt)
{
}

void D2DCore::CreateBrush(ID2D1BitmapRenderTarget* crt, D2D1::ColorF color, ID2D1SolidColorBrush** brush)
{
}

void D2DCore::CreateTextFormat(const WCHAR* fontName, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, FLOAT fontSize, IDWriteTextFormat** textFormat)
{
}

D2DBitmap* D2DCore::CreateD2Bitmap(ID2D1BitmapRenderTarget* crt, const wchar_t* filePath)
{
	return nullptr;
}
