#include "Boss_02_Scene.h"
#include "PlayerGameObject.h"
#include "CrossHairObject.h"

#include "BossGameObject.h"
#include "PrototypeBackgroundObject.h"
#include "SampleSceneUI.h"
#include "Observer.h"

void Boss_02_Scene::Initialize()
{

}

void Boss_02_Scene::Finalize()
{

}

void Boss_02_Scene::Enter()
{
	//2StageBGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 6, game::eSoundChannel::BGM);

	// �÷��̾�
	PlayerGameObject* Player = new PlayerGameObject(this);
	Observer::GetInstance()->SetPlayer(Player);
	AddObject(Player, game::OBJECT_TYPE::PLAYER);

	// ��� ����Ʈ
	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);

	// ��׶�� ���
	PrototypeBackgroundObject* PrototypeBackground = new PrototypeBackgroundObject(this);
	AddObject(PrototypeBackground, game::OBJECT_TYPE::BACKGROUND);
	Observer::GetInstance()->SetBackground(PrototypeBackground);

	// ����
	BossObject* Boss = new BossObject(this, 2);
	Observer::GetInstance()->SetBoss(Boss);
	AddObject(Boss, game::OBJECT_TYPE::BOSS);
	Boss->m_Transform.SetPosition(1550.f, 560.f, 0);

	BossHPUI* bossHPUI = new BossHPUI(this);
	AddObject(bossHPUI, game::OBJECT_TYPE::UI);
	bossHPUI->m_Transform.SetPosition(1500, 80, 0);

	PlayerHPUI* playerHPUI = new PlayerHPUI(this);
	AddObject(playerHPUI, game::OBJECT_TYPE::UI);
	playerHPUI->m_Transform.SetPosition(460, 80, 0);

	CharacterPlayUI* characterPlayUI = new CharacterPlayUI(this);
	AddObject(characterPlayUI, game::OBJECT_TYPE::UI);
	characterPlayUI->m_Transform.SetPosition(80.f, 80.f, 0);


	m_ColliderManager.CheckGroup(game::OBJECT_TYPE::PLAYER, game::OBJECT_TYPE::ENEMY_WEAPON);
	m_ColliderManager.CheckGroup(game::OBJECT_TYPE::PLAYER, game::OBJECT_TYPE::HOMING_WEAPON);
	m_ColliderManager.CheckGroup(game::OBJECT_TYPE::BOSS, game::OBJECT_TYPE::PLAYER_WEAPON);
	m_ColliderManager.CheckGroup(game::OBJECT_TYPE::MOUSE_CROSSHAIR, game::OBJECT_TYPE::HOMING_WEAPON);
}

void Boss_02_Scene::Exit()
{
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);

	m_ColliderManager.ResetGroup();
}

Boss_02_Scene::Boss_02_Scene() :SceneBase("Boss_02_Scene")
{

}

Boss_02_Scene::~Boss_02_Scene()
{

}
