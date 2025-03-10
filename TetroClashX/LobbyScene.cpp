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
	if (!_lobbyBg)
	{
		_lobbyBg = Resources::GetInstance()->lobbyBackgroundBitamp;
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
