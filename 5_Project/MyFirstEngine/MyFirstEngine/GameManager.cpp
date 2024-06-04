#include "GameManager.h"
#include <Windows.h>
#include <iostream>
#include "InputSystem.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"
#include "Define.h"


GameManager* GameManager::instance = nullptr;
GameManager::GameManager() {}
GameManager::~GameManager() {}

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}
	return instance;
}

void GameManager::DestroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void GameManager::Initialize()
{

	input::InputSystem::GetInstance()->InitInput();
	m_Time.InitTime();
	GameRender::GetInstance()->InitRender();
	ResourceManager::GetInstance()->Initialize();
	SceneManager::GetInstance()->InitSceneManager();
}


void GameManager::Update(float deltaTime)
{
	++m_UpdateCount;

	input::InputSystem::GetInstance()->Update();


	SceneManager::GetInstance()->Update(deltaTime);

	////	���۰��� ���� �ƴ϶� ������������ �翬�ϰ� ����Ǿ�� �ϴ� �͵�
	////	ex> �浹ü�� ������Ʈ�� ���� ���� ��.
	//ColliderManager::GetInstance()->FinalUpdate();
	////�浹ó��
	//ColliderManager::GetInstance()->Update();
	////Destroy object's collider
	//ColliderManager::GetInstance()->DestoryUpdate();
	////Destroy Object
	//SceneManager::GetInstance()->DestoryUpdate();

}

void GameManager::FixeUpdate()
{
	static float elapsedTime;

	elapsedTime += m_Time.GetDeltaTime();

	while (elapsedTime >= FixedUpdateTime) //0.02��
	{
		++m_FixedUpdateCount;
		elapsedTime -= FixedUpdateTime;
		SceneManager::GetInstance()->FixedUpdate(FixedUpdateTime);
	}
}

void GameManager::Render()
{

	GameRender::GetInstance()->BeginDraw();
	SceneManager::GetInstance()->Render();

	if(DebugMode)
		GameRender::GetInstance()->DrawFPS(m_UpdateCount, m_Time.GetDeltaTime());
	GameRender::GetInstance()->EndDraw();
}

void GameManager::Finalize()
{

	input::InputSystem::GetInstance()->DestroyInstance();
	SceneManager::GetInstance()->DestroyInstance();
	GameRender::GetInstance()->DestroyInstance();
	//GameRandom::GetIncetance()->DestroyInstance();
	//SharedData::GetInstance()->DestroyInstance();
	ResourceManager::GetInstance()->DestroyResourceManager();
}

void GameManager::Run()
{
	MSG msg;

	while (true)
	{
		//GetMessage�� ť�� �޽����� ���� �� ���� ���			//��ŷ
		//PeekMessage�� �޽����� ������ ó���ϰ� �ƴϸ� �Ѿ //�ͺ�ŷ
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			if (msg.message == WM_KEYDOWN)
			{
				/*input::KeyDown(msg.wParam);*/
			}
			else if (msg.message == WM_KEYUP)
			{
				/*input::KeyUp(msg.wParam);*/
			}

			else
			{
				//GetMessage�� ������ �� Proc�� ó���ϰڱ� ������ ��.
				DispatchMessage(&msg);
			}
		}
		else
		{
			m_Time.UpdateTime();

			if (DevelopKey)
			{
				if (input::KEYTAP(input::KEY::P))
				{
					m_Time.SetTimeScale(m_Time.GetTimeScale()+1);
				}
				if (input::KEYTAP(input::KEY::O))
				{
					m_Time.SetTimeScale(1);
				}
				if (input::KEYTAP(input::KEY::F1))
				{
					Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::STAGE_NORMAL_01;
				}
				else if (input::KEYTAP(input::KEY::F2))
				{
					Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::STAGE_NORMAL_02;
				}
				else if (input::KEYTAP(input::KEY::F3))
				{
					Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::STAGE_NORMAL_03;
				}
			}

			FixeUpdate();

			Update(m_Time.GetDeltaTime());

			Render();
		}
	}

}

