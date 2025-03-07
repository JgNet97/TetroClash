#pragma once
class D2DBitmap;
/********************
	D2DCore
********************/
class D2DCore
{
private:
	ID2D1Factory*			_d2d1Factory;
	IWICImagingFactory*		_wicFactory;
	IDWriteFactory*			_d2WriteFactory;

public:
	D2DCore();
	~D2DCore();

	static D2DCore* GetInstance() 
	{
		static D2DCore _sInstance;
		return &_sInstance;
	}

	void CreateRT(HWND hWnd, ID2D1HwndRenderTarget** rt);
	void CreateCRT(ID2D1HwndRenderTarget* rt, ID2D1BitmapRenderTarget** crt);
	void CreateBrush(ID2D1BitmapRenderTarget* crt, D2D1::ColorF color, ID2D1SolidColorBrush** brush);
	void CreateTextFormat(
		const WCHAR* fontName
		, DWRITE_FONT_WEIGHT fontWeight
		, DWRITE_FONT_STYLE fontStyle
		, DWRITE_FONT_STRETCH fontStretch
		, FLOAT fontSize, 
		IDWriteTextFormat** textFormat);
	D2DBitmap* CreateD2Bitmap(ID2D1BitmapRenderTarget* crt, const wchar_t* filePath);
};

