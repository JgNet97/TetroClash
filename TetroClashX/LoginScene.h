#pragma once
#include "Scene.h"
/********************
	LoginScene
********************/
class LoginScene : public Scene
{
private:
	HWND _loginPanel = nullptr;
	HWND _hUserIdText = nullptr;
	HWND _hUserPwText = nullptr;
	HWND _hUserIdInput = nullptr;
	HWND _hUserPwInput = nullptr;
	HFONT _hFont = nullptr;
	HWND _hButton = nullptr;
	D2DBitmap* _loginBg = nullptr;
	D2DBitmap* _logo = nullptr;

public:
	LoginScene();
	virtual ~LoginScene();

	virtual void Init(HWND hWnd, HINSTANCE hInstance) override;
	virtual void Clear() override;
	virtual void Update() override;
	virtual void Render(HWND hWnd, HINSTANCE hInstance, ID2D1BitmapRenderTarget* crt) override;
};

