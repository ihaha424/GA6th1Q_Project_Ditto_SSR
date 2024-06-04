#pragma once
#include "ScriptComponent.h"

class FontScript : public ScriptComponent
{

public:
    FontScript(GameObject* pOwner, std::string ObjName);
    ~FontScript();

    virtual void Start() {};
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime) {};

    void SetRectSizeAndTransform(int _Width, int _Height, float _TransformX, float _TransformY); // ���� ��ġ��
    void SetMyDialog(std::wstring* ObjectDialog, int strArrSize); 
    void SetMyColor(int R, int G, int B); // ��¥ ��
    void SetFontSize(int _FontSize); // ��¥ ũ�� 

    void SetMyTextureTransform(float _PositionX, float _PositionY); // �̹��� ��ġ ������

    game::eSoundChannel m_eSoundChannel = game::eSoundChannel::End;
    game::eSoundList m_eSoundList = game::eSoundList::End;

protected:
    TextureComponent* m_TexComp; // �̹��� ���۳�Ʈ
    TextComponent* m_TextComp;   // �ؽ�Ʈ ���۳�Ʈ

    //����� ��ٸ��� ��� �ؽ�Ʈ
    std::vector<std::wstring*> m_tString;

    std::wstring* m_sDialog = nullptr; // ���ڿ�
    int m_iDialogArrSize;

    float delayTime = 0.f;  // ������ Ÿ�� ����

     
};

