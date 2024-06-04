#include "Story_News_Scene.h"
#include "Story_News_ButtonUI.h"


// ���丮 ��
#include "Story01_Dialog_News.h"
#include "Story02_Dialog_Briefing.h"
#include "NewsBackGroundUI.h"
#include "CrossHairObject.h"

void Story_News_Scene::Initialize()
{
}

void Story_News_Scene::Finalize()
{

}

void Story_News_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 1, game::eSoundChannel::BGM);

	// ��׶��� �̹���
	NewsBackGroundUI* newsBackGroundUI = new NewsBackGroundUI(this);
	AddObject(newsBackGroundUI, game::OBJECT_TYPE::UI);

	// ���� �� ��ȭ
	Story01_Dialog_News* story01_Dialog_News = new Story01_Dialog_News(this);
	AddObject(story01_Dialog_News, game::OBJECT_TYPE::UI);
	
	//��ŵ��ư
	Story_News_ButtonUI* story_News_ButtonUI = new Story_News_ButtonUI(this);
	AddObject(story_News_ButtonUI, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);

}

void Story_News_Scene::Exit()
{
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
