#include "SceneManager.h"
#include "SceneBase.h"
#include "Observer.h"
#include "PrototypeScene.h"
// �� ����
#include "SceneSet.h"
SceneManager* SceneManager::instance = nullptr;
SceneManager* SceneManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new SceneManager();
    }
    return instance;
}
void SceneManager::DestroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}
void SceneManager::FixedUpdate(float fixedDeltaTime)
{
    m_CurScene->FixedUpdate(fixedDeltaTime);
}
void SceneManager::Update(float deltaTime)
{
    m_CurScene->Update(deltaTime);
}
void SceneManager::Render()
{
    m_CurScene->Render();
}
void SceneManager::Destroy()
{
    m_CurScene->Destroy();
}
void SceneManager::InitSceneManager()
{
    m_SceneArr[(UINT)game::SCENE_TYPE::START] = new Start_Menu;                                    // ���� ȭ��
    m_SceneArr[(UINT)game::SCENE_TYPE::MAIN_MENU] = new MainMenuScene;                             // ���� �޴� (���̵� ��ư Ŭ���Ͽ� ���̵�)
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_TUTORIAL] = new Tutorial_Scene;                       // Ʃ�丮��
    m_SceneArr[(UINT)game::SCENE_TYPE::SALLY] = new Sally_Scene;                                   // ��ݾ�
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_NORMAL_01] = new Boss_01_Scene;                       // ����1
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_NORMAL_02] = new Boss_02_Scene;                       // ����2
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_NORMAL_03] = new Boss_03_Scene;                       // ����3
    m_SceneArr[(UINT)game::SCENE_TYPE::INTRODUCTION_STORY_NEWS] = new Story_News_Scene;            // ���� ���丮(����)
    m_SceneArr[(UINT)game::SCENE_TYPE::INTRODUCTION_STORY_BRIEFING] = new Story_Briefing_Scene;    // ���� ���丮(��� ����)
    m_SceneArr[(UINT)game::SCENE_TYPE::PLAY] = new SampleScene;                                    // �ϴ� �׽�Ʈ�� �����  ���� �����ҿ���
    m_SceneArr[(UINT)game::SCENE_TYPE::UPGRADE] = new Upgrade_Scene;                               // ���׷��̵� ��
    m_SceneArr[(UINT)game::SCENE_TYPE::MIDDLE_STORY_01] = new Middle_Story_01_Scene;               // 1�������� Ŭ���� �߰� ���丮
    m_SceneArr[(UINT)game::SCENE_TYPE::MIDDLE_STORY_02] = new Middle_Story_02_Scene;               // 2�������� Ŭ���� �߰� ���丮
    m_SceneArr[(UINT)game::SCENE_TYPE::ENDING_STORY] = new Ending_Story_Scene;                     // ���� ���丮
    m_SceneArr[(UINT)game::SCENE_TYPE::SHIP_DIRECTING_BOSS_01] = new Ship_Directing_Boss_01_Scene; // �Լ� ����1 �ִϸ��̼� ����
    m_SceneArr[(UINT)game::SCENE_TYPE::SHIP_DIRECTING_BOSS_02] = new Ship_Directing_Boss_02_Scene; // �Լ� ����2 �ִϸ��̼� ����
    m_SceneArr[(UINT)game::SCENE_TYPE::SHIP_DIRECTING_BOSS_03] = new Ship_Directing_Boss_03_Scene; // �Լ� ����3 �ִϸ��̼� ����
    m_SceneArr[(UINT)game::SCENE_TYPE::COKPIT] = new Cokpit_Script;                                // �Լ� ����3 �ִϸ��̼� ����	// �����
    m_SceneArr[(UINT)game::SCENE_TYPE::ENDING] = new Ending_Credits_Scene;                         // ����ũ����
    
    
    m_CurScene = m_SceneArr[(UINT)game::SCENE_TYPE::START];
    // ���� �� ����
    m_CurScene->Enter();
}
void SceneManager::ChangeScene(game::SCENE_TYPE type)
{
    m_CurScene->Exit();
    m_CurScene->Clear();
    m_CurScene = m_SceneArr[(UINT)type];
    m_CurScene->Enter();
    Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::CHANGE_EFFECT;
    Observer::GetInstance()->m_CurSceneFlag = type;
}
SceneBase* SceneManager::GetCurScene()
{
    return m_CurScene;
}
SceneManager::SceneManager() : m_SceneArr{}, m_CurScene(nullptr)
{
}
SceneManager::~SceneManager()
{
}