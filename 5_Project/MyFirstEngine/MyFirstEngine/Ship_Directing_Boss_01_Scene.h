#pragma once
#include "SceneBase.h"

class Ship_Directing_Boss_01_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;


public:
    Ship_Directing_Boss_01_Scene() : SceneBase("Ship_Directing_Boss_01_Scene") {};
    virtual ~Ship_Directing_Boss_01_Scene() {};

};
