#pragma once
#include "Scene.h"
class Scene;
/********************
	SceneManager
********************/
class SceneManager
{
private:
	Scene*		_nowScene = nullptr;
	Scene*		_scenes[SCENE_COUNT];
	HWND		_hWnd;
	HINSTANCE	_hInstance;

public:
	SceneManager();
	~SceneManager();

	static SceneManager* GetInstance() 
	{
		static SceneManager s_Instacne;
		return &s_Instacne;
	}

	void NextScene(SCENE_TYPE type);
	void Init(HWND hWnd, HINSTANCE hInstance);
	Scene* NowScene() { return _nowScene; }
	void Render(ID2D1BitmapRenderTarget* crt);
};

