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

#include<cstdlib> // �ǵ帲
#include<ctime>   // �ǵ帲

#include <vector>
class Boss_1_Script :
    public ScriptComponent
{
public:
    virtual void Start();
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render() {};
    virtual void OnCollisionEnter(ColliderComponent* src);
    virtual void OnCollisionExit(ColliderComponent* src) {};

    //Status
public:
    float m_fHP = 100.0f;
    float m_fMaxHP = m_fHP;

private:
    //Damage
    void GetDamage(float Damage);

private:
    TextureComponent* m_cTexture;
    float   m_fTextureRenderTime = 0;

    float elapsedTime = 0.0f;
    float elapsedTime2 = 0.0f; // ����ID : 401
    float elapsedTime3 = 0.0f; // ����ID : 402
    float elapsedTime4 = 0.0f; // ����ID : 403
    float elapsedTime5 = 0.0f;
    float elapsedTime6 = 0.0f;
    int pattern401Index = 0;
    int pattern402Index = 0;
    int pattern403Index = 0;
    int pattern404Index = 0;
    int pattern404PlusIndex = 0;
    int pattern404Count = 30;
    int pattern405Index = 0;


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
    static float floatingVector;// = 1.0f;


    Boss_1_Script(GameObject* pOwner, std::string ObjName);

    void Delay(float time);

    void AnimationInitialize();

    void AnimationUpdate(float fixedDeltaTime);

    void Pattern101(int x, int y); // ����
    void Pattern102(int x, int y); // ����
    void Pattern103(int x, int y); // 3x3


    //float 
    void Pattern401(float fixedDeltaTime); // �������� 401
    void Pattern402(float fixedDeltaTime); // �������� 402
    void Pattern403(float fixedDeltaTime); // �������� 403
    void Pattern404(float fixedDeltaTime, float interval); // �̷����� 404
    void Pattern405(float fixedDeltaTime);// ���� ���� 405
    

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
    bool b_CornerPattern403[5][7][7] = {

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
    bool b_Mazepattern404[27][7] = 
    {
		{0,1,1,1,0,1,1},
		{0,0,0,0,0,0,0},
		{0,0,0,1,0,0,1},
		{1,1,0,0,1,0,0},
		{0,0,0,0,0,0,1},
		{1,1,1,0,0,0,0},
		{0,0,0,0,1,1,1},
		{1,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,0,1,1,0},
		{0,1,0,0,0,0,0},
		{0,0,0,0,0,1,0},
		{0,0,0,1,0,0,0},
		{1,1,1,0,0,0,0},
		{0,0,0,1,0,1,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,0,0,0,0,1},
		{0,0,1,1,1,0,0},
		{0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0},
		{0,1,0,0,1,1,1},
		{0,0,1,0,0,0,0},
		{0,0,0,0,0,1,0},
		{1,0,1,1,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,1,0,0,1,1}
	};


    

};
