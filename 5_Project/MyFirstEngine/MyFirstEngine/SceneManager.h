#pragma once
#include <array>
#include "Define.h"

class SceneBase;
typedef unsigned int        UINT;

class SceneManager
{
private:
	static SceneManager* instance;

	SceneBase* m_SceneArr[(UINT)(game::SCENE_TYPE::END)];
	SceneBase* m_CurScene;

public:
	static SceneManager* GetInstance();
	static void DestroyInstance();

public:
	void FixedUpdate(float fixedDeltaTime);
	void Update(float deltaTime);
	void Render();
	void Destroy();		//������ EventManager���� �ϸ� �ʿ� ���� -> �������


	// array�� �ϸ� �� �ʱ�ȭ�� �ٲ��־�� �� "Ȯ�� �ٶ�"
	void InitSceneManager();
	// �̰͵� Array�� �ϸ� std::String name���� �޾Ƽ� ã���� �ɵ�
	//	-> Scene�� Object��ӹް� �־ �̸����� ã�� �� ����
	void ChangeScene(game::SCENE_TYPE type);
	SceneBase* GetCurScene();
	void ReloadScene();

private:
	SceneManager();
	~SceneManager();
};

