#pragma once
#include "ProjectileWeaponScript.h"


class MeteorScript : public ProjectileWeaponScript
{
public:
    float animationTimer = 0.0f;
    MeteorScript(GameObject* pOwner, std::string ObjName);
    void Start() override;
    void FixedUpdate(float fixedDeltaTime) override;

    void MoveMissile(float fixedDeltaTime, Vector3 moveDirection) override;
    void Activate();
    void OnCollisionEnter(ColliderComponent* src) {
        m_pOwner->SetStatus(game::Status::InActive);
    }
    void WarningMode();
    void MissileMode();
    void AnimationUpdate(float fixedDeltaTime);
};

