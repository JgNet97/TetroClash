#include "pch.h"
#include "LoginScene.h"

LoginScene::LoginScene() : Scene(SCENE_TYPE::LOGIN_SCENE)
{
	
}

LoginScene::~LoginScene()
{
}

void LoginScene::Init(HWND hWnd, HINSTANCE hInstance)
{
	if (!_hFont)
	{
		_hFont = CreateFont(
			24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial"
		);
	}

	if (!_loginPanel) 
	{
		_loginPanel = CreateWindowEx(WS_EX_CONTROLPARENT ,L"STATIC", NULL, WS_CHILD | WS_VISIBLE,
			710, 700, 500, 270, hWnd, NULL, hInstance, NULL);
	}

	if (!_hUserIdText) 
	{
		_hUserIdText = CreateWindow(L"STATIC", L"아이디",
			WS_CHILD | WS_VISIBLE | SS_CENTER,
			0, 55, 200, 30,
			_loginPanel, NULL, hInstance, NULL);
		SendMessage(_hUserIdText, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

	if (!_hUserPwText)
	{
		_hUserPwText = CreateWindow(L"STATIC", L"패스워드",
			WS_CHILD | WS_VISIBLE | SS_CENTER,
			0, 125, 200, 30,
			_loginPanel, NULL, hInstance, NULL);
		SendMessage(_hUserPwText, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

	if (!_hUserIdInput)
	{
		_hUserIdInput = CreateWindowEx(
			0, L"EDIT", L"", 
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 
			150, 50, 250, 45, 
			_loginPanel, (HMENU)1, GetModuleHandle(NULL), NULL);
		SendMessage(_hUserIdInput, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

	if (!_hUserPwInput)
	{
		_hUserPwInput = CreateWindowEx(
			0, L"EDIT", L"", 
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 
			150, 120, 250, 45, 
			_loginPanel, (HMENU)1, GetModuleHandle(NULL), NULL);
		SendMessage(_hUserPwInput, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

	if (!_hButton)
	{
		_hButton = CreateWindow(
			L"BUTTON", L"로그인",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			794, 889, 350, 50, 
			hWnd, (HMENU)1, hInstance, NULL);
		SendMessage(_hButton, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

	if (!_loginBg)
	{
		_loginBg = Resources::GetInstance()->loginBackgroundBitmap;
	}

	if (!_logo)
	{
		_logo = Resources::GetInstance()->logoBitmap;
	}

	ShowWindow(_loginPanel, SW_SHOW);
}

void LoginScene::Clear()
{
	ShowWindow(_loginPanel, SW_HIDE);
	ShowWindow(_hButton, SW_HIDE);
}

void LoginScene::Update()
{

}

void LoginScene::Render(HWND hWnd, HINSTANCE hInstance, ID2D1BitmapRenderTarget* crt)
{
	// crt->DrawBitmap(_loginBg->GetD2D1Bitmap()); 배경 너무 못생겨서 삭제 ㅋㅋ
	crt->DrawBitmap(_logo->GetD2D1Bitmap(), { 710,150,710 + 500,150 + 500},1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
}
