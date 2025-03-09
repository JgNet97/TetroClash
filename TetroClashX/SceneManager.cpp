#include "pch.h"
#include "Scene.h"
#include "SceneManager.h"
#include "LoginScene.h"
SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
}
void SceneManager::NextScene(SCENE_TYPE type)
{
	_nowScene->Clear();
	Scene* nextScene = _scenes[type];
	_nowScene = nextScene;
	_nowScene->Init(_hWnd, _hInstance);
}

void SceneManager::Init(HWND hWnd, HINSTANCE hInstance)
{
	_hWnd= hWnd;
	_hInstance = hInstance;
	_scenes[LOGIN_SCENE] = new LoginScene();
	_nowScene = _scenes[LOGIN_SCENE];
	_nowScene->Init(hWnd, hInstance);
}

void SceneManager::Render(ID2D1BitmapRenderTarget* crt)
{
	if (!_nowScene)
		return;

	_nowScene->Render(_hWnd, _hInstance, crt);
}
