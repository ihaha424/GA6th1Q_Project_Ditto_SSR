#include "Upgrade_Scene.h"
#include "CrossHairObject.h"
#include "UpgradeButtonUI_01.h"
#include "UpgradeBackGroundUI.h"
void Upgrade_Scene::Initialize()
{
}

void Upgrade_Scene::Finalize()
{

}

void Upgrade_Scene::Enter()
{
	srand((unsigned)time(NULL));
	UpgradeBackGroundUI* upgradeBackGroundUI = new UpgradeBackGroundUI(this);
	AddObject(upgradeBackGroundUI, game::OBJECT_TYPE::UI);
	
	UpgradeButtonUI_01* upgradeButtonUI_01[3]; 
	struct UpgradeInfo upgradeInfo[5] =
	{
		{0,L"DamageIncreaseImage",L"\\Image\\20. UPGRADE\\Damage_increase.bmp",L"������ ���ط� +50% ����"},
		{1,L"IncreasedChargeSpeedImage",L"\\Image\\20. UPGRADE\\Increased_charge_speed.bmp",L"���� �ӵ� +50% ����"},
		{2,L"ShieldImage",L"\\Image\\20. UPGRADE\\shield.bmp",L"10�ʸ��� ����Ǹ� ���� ������ 1ȸ �����ִ� ��"},
		{3,L"InvincibilityImage",L"\\Image\\20. UPGRADE\\invincibility.bmp",L"2.5�ʰ� ���� ������ �� ����\n\t(���: Space Bar)"},
		{4,L"PortalImage",L"\\Image\\20. UPGRADE\\portal.bmp",L"����ĭ ������ �ݴ��� ������ \n�̵��� ����������. "},
	};

	bool isPortal = Observer::GetInstance()->m_sPlayerInfo.m_bPortal;
	bool isInvincible = Observer::GetInstance()->m_sPlayerInfo.m_bInvincibility;
	int showList[3] = { -1, -1,-1 };
	for (size_t i = 0; i < 3; i++)
	{
		bool dubCheck = false;
		do
		{
			dubCheck = false;
			showList[i] = rand() % 5;
			for (size_t j = 0; j < i; j++)
			{
				if (showList[i] == showList[j])
				{
					dubCheck = true;
				}
			}
			if (isInvincible && showList[i] == 3)
			{
				dubCheck = true;
				continue;
			}
			if (isPortal && showList[i] == 4)
			{
				dubCheck = true;
				continue;
			}
		} 
		while (dubCheck);
	}

	for (int i = 0; i < 3; i++)
	{
		upgradeButtonUI_01[i] = new UpgradeButtonUI_01(this,upgradeInfo[showList[i]]);
		upgradeButtonUI_01[i]->m_Transform.SetPosition(460 + 500 * i, 800, 0);
		upgradeButtonUI_01[i]->m_cText->SetRectSize(470 + 500 * i-125, 790, 250, 150);

		AddObject(upgradeButtonUI_01[i], game::OBJECT_TYPE::UI);
	}

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);
}


void Upgrade_Scene::Exit()
{
	m_ColliderManager.ResetGroup();

}
