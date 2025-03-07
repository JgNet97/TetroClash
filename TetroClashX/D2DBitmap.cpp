#include "pch.h"
#include "D2DBitmap.h"

D2DBitmap::D2DBitmap(ID2D1Bitmap* id2d1Bitamp, IWICFormatConverter* converter, BYTE* buffer)
	:_id2d1Bitmap(id2d1Bitamp), _converter(converter), _pBuffer(buffer)
{
}

D2DBitmap::~D2DBitmap()
{
	if (_pBuffer)
		delete[] _pBuffer;

	if (_id2d1Bitmap)
		_id2d1Bitmap->Release();

	if (_converter)
		_converter->Release();
}
