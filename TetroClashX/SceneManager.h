#pragma once
class Scene;
/********************
	SceneManager
********************/
class SceneManager
{
private:
	Scene*  _nowScene;
	Scene*  _scenes[SCENE_COUNT];

public:
	SceneManager* GetInstance() 
	{
		static SceneManager s_Instacne;
		return &s_Instacne;
	}

	void NextScene(SCENE_TYPE type);
};

