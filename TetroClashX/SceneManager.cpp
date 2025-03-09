#include "pch.h"
#include "Scene.h"
#include "SceneManager.h"

void SceneManager::NextScene(SCENE_TYPE type)
{
	_nowScene->Clear();
	Scene* nextScene = _scenes[type];
	_nowScene = nextScene;
	_nowScene->Init();
}
