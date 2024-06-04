#pragma once
#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "SceneBase.h"

class TextureUIScript : public ScriptComponent
{
public :
    TextureUIScript(GameObject* pOwner, std::string ObjName);

    virtual void Start(); // ���� ������Ʈ
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Update(float deltaTime){};

    TextureComponent* m_TexComp;

    std::wstring m_sObjName; // �뵵 ������Ʈ �̸�
    std::wstring m_sRoute;   // ��� �̸�

    void SetMyLoadScene(game::SCENE_TYPE name); // ��ȯ �� ���޿�
    void SetMySceneChange(); // �� ü����

    void SetMyTextureTransform(float _PositionX, float _PositionY); // �̹��� ������ ��ġ �����

    // ���� �뵵 ���� �̹��� �ݺ��ؼ� �ֱ� ���� ���� �Լ�
    void SetMyPoldeo(std::wstring _m_sObjName, std::wstring _m_sRoute, int _m_iTextureSize); 
    // ������Ʈ �̸�, �����ġ, ������ ���� ���� ���� : ���ϰ�� �����̸� �ѹ� ���ڰ� ���������� �ö󰡾� �Ѵ�

    //##### �߿� 
    bool m_bObjectType = 0;     // 0 ���� ��� �̹��� ���� ������ 1���� ��� ���� �ִϸ��̼�ó�� �̹��� ����

    int m_iTextureSize = 0;    // �̹��� ������ ����� ���� �ؾ� ��
    float m_fMovieMAXDelayTime = 0.f; // �̹��� ���� ������ Ÿ�� ����

    float m_fSceneDelayTime = 0.f; // �� ��ȯ ���� ������ Ÿ��

    game::SCENE_TYPE m_eScene_Type; // �� Ÿ�� ��ȯ��

    void PlayMusic();

protected:
    float m_fDelayTime = 0; // �̹��� ���� �ʱ�ȭ��
};

