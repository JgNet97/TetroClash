#include "pch.h"
#include "D2DCore.h"
#include "D2DBitmap.h"
D2DCore::D2DCore()
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_d2d1Factory);

	if (FAILED(hr))
	{
		CRUSH;
	}

	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&_d2WriteFactory));

	if (FAILED(hr))
	{
		CRUSH
	}
		
	hr = CoInitialize(NULL);

	if (FAILED(hr))
	{
		CRUSH
	}

	hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_wicFactory));

	if (FAILED(hr))
	{
		CRUSH
	}
}

D2DCore::~D2DCore()
{
	if (_d2d1Factory)
		_d2d1Factory->Release();

	if (_wicFactory)
		_wicFactory->Release();
}

void D2DCore::CreateRT(HWND hWnd, ID2D1HwndRenderTarget** rt)
{
	HRESULT hr;
	RECT rc;
	GetClientRect(hWnd, &rc);

	hr = _d2d1Factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties()
		, D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top))
		, rt
	);

	if (FAILED(hr))
		CRUSH
}

void D2DCore::CreateCRT(ID2D1HwndRenderTarget* rt, ID2D1BitmapRenderTarget** crt)
{
	HRESULT hr;
	hr = rt->CreateCompatibleRenderTarget(crt);

	if (FAILED(hr))
		CRUSH
}

void D2DCore::CreateBrush(ID2D1BitmapRenderTarget* crt, D2D1::ColorF color, ID2D1SolidColorBrush** brush)
{
	HRESULT hr;
	hr = crt->CreateSolidColorBrush(color, brush);

	if (FAILED(hr))
		CRUSH
}

void D2DCore::CreateTextFormat(const WCHAR* fontName, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, FLOAT fontSize, IDWriteTextFormat** textFormat)
{
	_d2WriteFactory->CreateTextFormat(fontName, NULL, fontWeight, fontStyle, fontStretch, fontSize, L"en-us", textFormat);
}

D2DBitmap* D2DCore::CreateD2Bitmap(ID2D1BitmapRenderTarget* crt, const wchar_t* filePath)
{
	IWICBitmapDecoder* pDecoder = nullptr;
	_wicFactory->CreateDecoderFromFilename(filePath, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &pDecoder);

	IWICBitmapFrameDecode* pFrame = nullptr;
	pDecoder->GetFrame(0, &pFrame);

	IWICFormatConverter* pConverter = nullptr;
	_wicFactory->CreateFormatConverter(&pConverter);
	pConverter->Initialize(pFrame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0f, WICBitmapPaletteTypeCustom);

	UINT width = 0, height = 0;
	pConverter->GetSize(&width, &height);

	UINT bufferSize = width * height * 4;
	BYTE* pBuffer = new BYTE[bufferSize];
	pConverter->CopyPixels(nullptr, width * 4, bufferSize, pBuffer);

	D2D1_BITMAP_PROPERTIES bitmapProperties = D2D1::BitmapProperties(
		D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)
	);

	ID2D1Bitmap* bitmap;
	crt->CreateBitmap(D2D1::SizeU(width, height), pBuffer, width * 4, &bitmapProperties, &bitmap);

	D2DBitmap* d2Bitmap = new D2DBitmap(bitmap, pConverter, pBuffer);

	if (pFrame)		pFrame->Release();
	if (pDecoder)	pDecoder->Release();

	return d2Bitmap;
}
