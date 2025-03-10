#include "pch.h"
#include "LobbyScene.h"

LobbyScene::LobbyScene() : Scene(LOBBY_SCENE)
{
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init(HWND hWnd, HINSTANCE hInstance)
{
	// ㅋㅋ 이거 안넣으면 RichEdit 안나옴 
	static bool richEditLoaded = false;
	if (!richEditLoaded) 
	{
		LoadLibrary(L"Msftedit.dll");
		richEditLoaded = true;
	}

	if (!_hFont)
	{
		_hFont = CreateFont(
			24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial"
		);
	}

	if (!_lobbyBg)
	{
		_lobbyBg = Resources::GetInstance()->lobbyBackgroundBitamp;
	}

	if (!_hChatPannel)
	{
		_hChatPannel = CreateWindowEx(WS_EX_CONTROLPARENT, L"STATIC", NULL, WS_CHILD | WS_VISIBLE,
			26, 681, 1274, 258, hWnd, NULL, hInstance, NULL);
	}

	if (!_hChatView) 
	{
		_hChatView = CreateWindowEx(WS_EX_CLIENTEDGE, MSFTEDIT_CLASS, L"",
			WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL | ES_READONLY,
			0, 0, 1274, 230, _hChatPannel, (HMENU)NULL, hInstance, NULL);
		SendMessage(_hChatView, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

	if (!_hChatInput)
	{
		_hChatInput = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"",
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
			0, 230, 1274, 28, _hChatPannel, (HMENU)NULL, hInstance, NULL);
		SendMessage(_hChatInput, WM_SETFONT, (WPARAM)_hFont, TRUE);
	}

}

void LobbyScene::Clear()
{
}

void LobbyScene::Update()
{
}

void LobbyScene::Render(HWND hWnd, HINSTANCE hInstance, ID2D1BitmapRenderTarget* crt)
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	crt->DrawBitmap(_lobbyBg->GetD2D1Bitmap(), D2D1_RECT_F{ (float)rc.left,(float)rc.top,(float)rc.right,(float)rc.bottom}, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
}
