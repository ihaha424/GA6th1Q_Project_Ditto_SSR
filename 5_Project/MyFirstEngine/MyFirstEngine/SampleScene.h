#pragma once
#include "SceneBase.h"

class SampleScene :
    public SceneBase
{
public:
    // SceneBase��(��) ���� ��ӵ�
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;
public:
    SampleScene();
    ~SampleScene();
};

