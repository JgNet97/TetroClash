#pragma once
/********************
	Scene
********************/
class Scene
{
protected:
	SCENE_TYPE _sceneType;

public:
	Scene() {};
	Scene(SCENE_TYPE sceneType);
	virtual ~Scene();

	virtual void Init(HWND hWnd, HINSTANCE hInstance);
	virtual void Clear();
	virtual void Update();
	virtual void Render(HWND hWnd, HINSTANCE hInstance, ID2D1BitmapRenderTarget* crt);
};

