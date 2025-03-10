#pragma once
/********************
	LobbyScene
********************/
class LobbyScene : public Scene
{
private:
	D2DBitmap*	_lobbyBg;
	HWND		_hChatPannel;
	HWND		_hChatView;
	HWND		_hChatInput;
	HWND		_hChatSendBtn;
	HFONT		_hFont;
public:
	LobbyScene();
	virtual ~LobbyScene();

	virtual void Init(HWND hWnd, HINSTANCE hInstance) override;
	virtual void Clear() override;
	virtual void Update() override;
	virtual void Render(HWND hWnd, HINSTANCE hInstance, ID2D1BitmapRenderTarget* crt) override;
};

