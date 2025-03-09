#pragma once
/********************
	Scene
********************/
class Scene
{
protected:
	SCENE_TYPE _sceneType;

public:
	Scene(SCENE_TYPE sceneType);
	virtual ~Scene();

	virtual void Init();
	virtual void Clear();
	virtual void Update();
	virtual void Render();
};

