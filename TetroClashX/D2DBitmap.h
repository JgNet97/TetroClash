#pragma once
/********************
	D2DBitmap
********************/
class D2DBitmap
{
private:
	BYTE*				 _pBuffer;
	ID2D1Bitmap*		 _id2d1Bitmap;
	IWICFormatConverter* _converter;

public:
	D2DBitmap(
		ID2D1Bitmap* id2d1Bitamp
		, IWICFormatConverter* converter
		, BYTE* buffer);
	~D2DBitmap();

	ID2D1Bitmap* GetD2D1Bitmap() { return _id2d1Bitmap; }
	void SetD2D1Bitmap(ID2D1Bitmap* bitmap) { _id2d1Bitmap = bitmap; }
	BYTE* GetBuffer() { return _pBuffer; }
};

