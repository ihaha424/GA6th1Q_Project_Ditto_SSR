#pragma once
#include "ScriptComponent.h"
#include "GameObject.h"

class FaidInFadeOutRenderComponent;

class FadeInFadeOutScript :
    public ScriptComponent
{
public:
    FadeInFadeOutScript(GameObject* pOwner, std::string ObjName);
    virtual void Start();
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime);

    void SetSign(bool ture);
    void SetDoor(bool ture);
    bool m_OnEffect = false;
    //0: ��,���̵��ξƿ�   1: ��    2: ���̵��ξƿ�
    int m_iFlag = 1;

public:
    float m_fElapsedTime = 0.0f;
    float m_fDelayTime = 0.1f;
    int m_iSign = -1;

    int DoorCurIndex = 31;
    int DoorIndexSize = 31;//�� 30��
    int DoorFlag = 1;


private:
    FaidInFadeOutRenderComponent* m_cTexture;
    TextureComponent* m_cDoor;

};

