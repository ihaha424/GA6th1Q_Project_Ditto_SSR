#pragma once
#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "WeaponObject.h"
#include "HomingWeaponObject.h"
#include "CrossAreaWeaponObject.h"
#include "LaserWeaponObject.h"
#include "ProjectileWeaponObject.h"
#include "SlowMissileObject.h"
#include "FastMissileObject.h" // FastMissile ������ �ǵ�Ƚ��ϴ�.
#include "MeteorObject.h"      // MeteorObject ������ �ǵ�Ƚ��ϴ�.

#include <vector>
class Boss_3_Script :
    public ScriptComponent
{
public:
    virtual void Start();
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render() {};
    virtual void OnCollisionEnter(ColliderComponent* src) {};
    virtual void OnCollisionExit(ColliderComponent* src) {};


private:
    TextureComponent* m_cTexture;
    float   m_fTextureRenderTime = 0;

    float elapsedTime = 0.0f;
    float elapsedTime2 = 0.0f;
    float elapsedTime3 = 0.0f;
    int pattern401Index = 0;
    int pattern402Index = 0;


    float floatingVector = 1.0f;
    CrossAreaWeaponObject* area[7][7];
    enum WEAPON_TYPE {
        HOMING,
        PROJECTILE,
        WEAPON_TYPE_END
    };

    ColliderComponent* m_cCollider;
    AnimationComponent* m_cRender;


public:
    std::vector<HomingWeaponObject*>m_vHomingWeaponPool;
    std::vector<SlowMissileObject*>m_vSlowMissilePool;
    std::vector<FastMissileObject*>m_vFastMissilePool;  //���⵵ pool ������ �ǵ�Ƚ��ϴ�.
    std::vector<MeteorObject*>m_vMeteorPool;          //���⵵ pool ������ �ǵ�Ƚ��ϴ�.



public:
    int m_iSlowMissileIndex = 0;
    int m_iFastMissileIndex = 0; //�ǵ帲
    int m_iMeteorIndex = 0;      //�ǵ帲


    Boss_3_Script(GameObject* pOwner, std::string ObjName);
    void Delay(float time);

    void AnimationInitialize();

    void AnimationUpdate(float fixedDeltaTime);

    void Pattern101(int x, int y); // ����
    void Pattern102(int x, int y); // ����
    void Pattern103(int x, int y); // 3x3


    //float 
    void Pattern401(float fixedDeltaTime); // �������� 401
    void Pattern402(float fixedDeltaTime); // �������� 402

    //void Pattern104(Vector3); // ���� ������
    //void Pattern104(Vector3); // ���� ������

    bool b_PizzaPattern401[9][7][7] = {
       {   // 1��
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0}
       },

       {   // 2��
          {0, 0, 0, 0, 0, 0, 0},
          {1, 0, 0, 0, 0, 0, 0},
          {1, 1, 0, 0, 0, 0, 0},
          {0, 0, 1, 1, 1, 0, 0},
          {0, 0, 0, 0, 0, 1, 1},
          {0, 0, 0, 0, 0, 0, 1},
          {0, 0, 0, 0, 0, 0, 0}
       },

       {   // 3��
          {1, 0, 0, 0, 0, 0, 0},
          {0, 1, 0, 0, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 0, 1, 0},
          {0, 0, 0, 0, 0, 0, 1}
       },

       {   // 4��
          {0, 1, 1, 0, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 1, 1, 0}
       },

       {   // 5��
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0}
       },

       {   // 6��
          {0, 0, 0, 0, 1, 1, 0},
          {0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 0},
          {0, 1, 1, 0, 0, 0, 0}
       },

       {   // 7��
          {0, 0, 0, 0, 0, 0, 1},
          {0, 0, 0, 0, 0, 1, 0},
          {0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 0},
          {0, 1, 0, 0, 0, 0, 0},
          {1, 0, 0, 0, 0, 0, 0}
       },

       {   // 8��
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 1},
          {0, 0, 0, 0, 0, 1, 1},
          {0, 0, 1, 1, 1, 0, 0},
          {1, 1, 0, 0, 0, 0, 0},
          {1, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0}
       },

       {   // 9��
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0}
       },
    };
    bool b_PizzaPattern402[9][7][7] = {

       {
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0}
       },

       {
          {0, 0, 0, 0, 1, 1, 0},
          {1, 0, 0, 0, 1, 0, 0},
          {1, 1, 0, 1, 0, 0, 0},
          {0, 0, 1, 1, 1, 0, 0},
          {0, 0, 0, 1, 0, 1, 1},
          {0, 0, 1, 0, 0, 0, 1},
          {0, 1, 1, 0, 0, 0, 0}
       },

       {
          {1, 0, 0, 0, 0, 0, 1},
          {0, 1, 0, 0, 0, 1, 0},
          {0, 0, 1, 0, 1, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 1, 0, 1, 0, 0},
          {0, 1, 0, 0, 0, 1, 0},
          {1, 0, 0, 0, 0, 0, 1}
       },

       {
          {0, 1, 1, 0, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 1},
          {0, 0, 0, 1, 0, 1, 1},
          {0, 0, 1, 1, 1, 0, 0},
          {1, 1, 0, 1, 0, 0, 0},
          {1, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 1, 1, 0}
       },
              {
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0}
       },

       {
          {0, 0, 0, 0, 1, 1, 0},
          {1, 0, 0, 0, 1, 0, 0},
          {1, 1, 0, 1, 0, 0, 0},
          {0, 0, 1, 1, 1, 0, 0},
          {0, 0, 0, 1, 0, 1, 1},
          {0, 0, 1, 0, 0, 0, 1},
          {0, 1, 1, 0, 0, 0, 0}
       },

       {
          {1, 0, 0, 0, 0, 0, 1},
          {0, 1, 0, 0, 0, 1, 0},
          {0, 0, 1, 0, 1, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 1, 0, 1, 0, 0},
          {0, 1, 0, 0, 0, 1, 0},
          {1, 0, 0, 0, 0, 0, 1}
       },

       {
          {0, 1, 1, 0, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 1},
          {0, 0, 0, 1, 0, 1, 1},
          {0, 0, 1, 1, 1, 0, 0},
          {1, 1, 0, 1, 0, 0, 0},
          {1, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 1, 1, 0}
       },
        {
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0},
          {0, 0, 0, 1, 0, 0, 0}
       }


    };
    bool b_Corner403[5][7][7] = {

      {
         {1, 1, 1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0}
      },

      {
         {0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
      },

      {
         {0, 0, 0, 1, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 1},
      },

      {
         {0, 0, 0, 0, 0, 0, 0},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
      },

      {
         {0, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
      }
    };


};

