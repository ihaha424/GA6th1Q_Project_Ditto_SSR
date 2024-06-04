#pragma once

#define DebugModeFlag 0

namespace game
{
#define DebugMode 0
#define DevelopKey 1
#define FixedUpdateTime 0.02 //0.02��
#define ScreenWidth 1920 
#define ScreenHeight 1080

	enum class COMPONENT_LAYER
	{
		Script,
		Collider,
		Render,
		ENd
	};
	
	enum class OBJECT_TYPE
	{
		DEFAULT,
		BACKGROUND,
		FACTORY,
		BOSS,
		ITEM,
		WEAPON,
		ENEMY_WEAPON,
		HOMING_WEAPON,
		PLAYER_WEAPON,
		PLAYER,
		UI,
		MOUSE_CROSSHAIR,

		END//�ִ� 32
	};

	enum class SCENE_TYPE
	{
		START,								// ���� ȭ��
		MAIN_MENU,							// ���� �޴� (���̵� ��ư Ŭ���Ͽ� ���̵�)
		STAGE_TUTORIAL,						// Ʃ�丮��
		SALLY,								// ��ݾ�
		STAGE_NORMAL_01,					// �븻 ��� ����1
		STAGE_NORMAL_02,					// �븻 ��� ����2
		STAGE_NORMAL_03,					// �븻 ��� ����3
		STAGE_HARD_01,						// �ϵ� ��� ����1
		STAGE_HARD_02,						// �ϵ� ��� ����2
		STAGE_HARD_03,						// �ϵ� ��� ����3
		INTRODUCTION_STORY_NEWS,			// ���� ���丮(����)
		INTRODUCTION_STORY_BRIEFING,		// ���� ���丮(��� ����)
		PLAY,								// �ϴ� �׽�Ʈ�� �����  ���� �����ҿ���
		UPGRADE,							// ���׷��̵� ��
		MIDDLE_STORY_01,					// 1�������� Ŭ���� �߰� ���丮
		MIDDLE_STORY_02,					// 2�������� Ŭ���� �߰� ���丮
		ENDING_STORY,						// ���� ���丮				
		SHIP_DIRECTING_BOSS_01,				// �Լ� ����1 �ִϸ��̼� ����
		SHIP_DIRECTING_BOSS_02,				// �Լ� ����2 �ִϸ��̼� ����
		SHIP_DIRECTING_BOSS_03,				// �Լ� ����3 �ִϸ��̼� ����
		SPARE,								// �����
		COKPIT,								// ����� Ÿ�� ��
		ENDING,								// ����ũ����
		CHANGE_EFFECT,						// �� ��ȯ ȿ��
		END
	};

	//
	//����	//�̰� ������Ʈ�� ���� ������Ʈ �� �������� ����� ���� ���� �����ϰ�
	//		//���� ������Ʈ������ ���� �� ������ Ű�� �� ������
	//
	enum class Status
	{
		InActive,
		Active,
		Destroy
	};

	enum class eSoundChannel
	{
		BGM,
		UI,
		Voice,
		//�÷��̾� �Ϲ� ����
		SFX_Player_Attack,
		//�÷��̾� ���� ����
		SFX_Player_Attack_Charge,
		//�÷��̾� �� �̻��� ���
		SFX_Player_Intercept,
		//�÷��̾� �ǰ�
		SFX_Player_Hitted,
		//�÷��̾� ���
		SFX_Player_Dead,
		//�÷��̾� ����
		SFX_Player_Skill_Shield,
		//�÷��̾� ���� ���
		SFX_Player_Skill_Invincible,
		//�÷��̾� ��Ż ���
		SFX_Player_Skill_Portal,
		//���� �Ϲ� ���� �̻��� �߻�
		SFX_Boss_Missile_Slow_1,
		SFX_Boss_Missile_Slow_2,
		//���� �Ϲ� ��� �̻��� �߻�
		SFX_Boss_Missile_Fast_1,
		SFX_Boss_Missile_Fast_2,
		//���� ���� �̻��� �߻�
		SFX_Boss_Missile_Guided_1,
		SFX_Boss_Missile_Guided_2,
		//���� ������ ����(�غ�, �߻�, ĵ��)
		SFX_Boss_Laser,
		SFX_Boss_Laser_Click,
		//���� ���� ���
		SFX_Warning_Area_1,
		SFX_Warning_Area_2,
		SFX_Warning_Area_3,
		SFX_Warning_Area_4,
		//������
		SFX_Explosion_1,
		SFX_Explosion_2,
		SFX_Explosion_3,
		SFX_Explosion_4,
		//���׿� ���� ���
		SFX_Warning_Meteo,
		//������ ���� ���
		SFX_Warning_Danger,
		//�÷��̾� ���� �̻���
		SFX_Support_Missile,
	
		End
	};

	enum class eSoundList
	{
		BGM,
		Battle,
		UI,

		STORY_Story01_News,
		STORY_Story02_Briefing,
		STORY_Story03_Takeoff,
		STORY_Story04_Encounters,
		STORY_Story05_Briefing,
		STORY_Story06_Encounters,
		STORY_Story07_Briefing,
		STORY_Story08_Encounters,
		STORY_Story09_News,
		STORY_Story10_Briefing,
		STORY_Story11_Bombing,
	


		STORY_Stage01_Battle,
		STORY_Stage02_Battle,
		STORY_Stage03_Battle,

		End
	};

	enum class EVENT_TYPE
	{
		//�ӽ÷� �̸� �̷��� ������� �ʿ��ϸ� �߰��ؼ� ��������
		event1,
		event2,
		event3,

		End
	};

}
