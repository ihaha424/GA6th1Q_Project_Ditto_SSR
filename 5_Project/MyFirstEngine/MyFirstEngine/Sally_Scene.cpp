#include "Sally_Scene.h"
#include "Sally_Dialog.h"
// �Լ� ��� ��
#include "Sally_Object.h"
#include "Sally_button.h"

#include "CrossHairObject.h"

void Sally_Scene::Initialize()
{

}

void Sally_Scene::Finalize()
{

}

void Sally_Scene::Enter()
{
	//BGM 04 Space
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 3, game::eSoundChannel::BGM);

	//���
	Sally_Object* _Sally_Object = new Sally_Object(this);
	AddObject(_Sally_Object, game::OBJECT_TYPE::UI);

	////����ũ ���� �� ����
	//Sally_Dialog* sally_Dialog = new Sally_Dialog(this);
	//AddObject(sally_Dialog, game::OBJECT_TYPE::UI);

	//��ư
	Sally_button* sally_button = new Sally_button(this);
	AddObject(sally_button, game::OBJECT_TYPE::UI);

	//���콺 
	CrossHairObject* crossHairObject = new CrossHairObject(this);
	AddObject(crossHairObject, game::OBJECT_TYPE::UI);
}

void Sally_Scene::Exit()
{
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);

}
