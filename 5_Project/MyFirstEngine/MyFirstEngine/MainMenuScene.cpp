#include "MainMenuScene.h"

// ���
#include "MainMenuBackGroundUI.h"

// ��ư
#include "TutorialButtonUI.h"
#include "NormalButtonUI.h"
#include "HardButtonUI.h"
#include "Ending_Button.h"

#include "CrossHairObject.h"

void MainMenuScene::Initialize()
{

}

void MainMenuScene::Finalize()
{

}

void MainMenuScene::Enter()
{
	//BGM
	//ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 0, game::eSoundChannel::BGM);

	// ���
	MainMenuBackGroundUI* mainMenuBackGroundUI = new MainMenuBackGroundUI(this);
	AddObject(mainMenuBackGroundUI, game::OBJECT_TYPE::UI);

	// Ʃ�丮�� ��ư
	TutorialButtonUI* tutorialButtonUI = new TutorialButtonUI(this);
	AddObject(tutorialButtonUI, game::OBJECT_TYPE::UI);

	// �븻 ���̵� ��ư
	NormalButtonUI* normalButtonUI = new NormalButtonUI(this);
	AddObject(normalButtonUI, game::OBJECT_TYPE::UI);

	// �ϵ� ���̵� ��ư
	HardButtonUI* hardButtonUI = new HardButtonUI(this);
	AddObject(hardButtonUI, game::OBJECT_TYPE::UI);

	Ending_Button* ending_Button = new Ending_Button(this);
	AddObject(ending_Button, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);

}

void MainMenuScene::Exit()
{
	//ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
	m_ColliderManager.ResetGroup();
}
