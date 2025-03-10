#pragma once
class Resources
{
public:
	D2DBitmap* loginBackgroundBitmap;
	D2DBitmap* logoBitmap;
	D2DBitmap* lobbyBackgroundBitamp;

public:
	static Resources* GetInstance() 
	{
		static Resources s_Instacne;
		return &s_Instacne;
	}
};

