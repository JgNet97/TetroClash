#pragma once
class Resources
{
public:
	D2DBitmap* loginBackgroundBitmap;
	D2DBitmap* logoBitmap;

public:
	static Resources* GetInstance() 
	{
		static Resources s_Instacne;
		return &s_Instacne;
	}
};

