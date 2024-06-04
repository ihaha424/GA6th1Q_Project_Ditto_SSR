#pragma once
#include <Windows.h>
#include <Vector>
#include "Define.h"

namespace input
{

#define KEYCHECK(key, state) InputSystem::GetInstance()->GetKeyState(key) == state
#define KEYNONE(key) KEYCHECK(key,input::KEY_STATE::NONE)
#define KEYTAP(key) KEYCHECK(key,input::KEY_STATE::TAP)
#define KEYHOLD(key) KEYCHECK(key,input::KEY_STATE::HOLD)
#define KEYAWAY(key) KEYCHECK(key,input::KEY_STATE::AWAY)

	enum KEY
	{
		LEFT,
		UP,
		DOWN,
		RIGHT,
		Q,
		W,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		A,
		S,
		D,
		F,
		G,
		Z,
		X,
		C,
		V,
		B,
		J,
		L,
		K,
		ALT,
		LSHIFT,
		SPACE,
		CONTROL,
		RETURN,
		ESCAPE,
		L_MOUSE_BUTTON,
		R_MOUSE_BUTTON,
		M_MOUSE_BUTTON,
		F1,
		F2,
		F3,

		LAST
	};

	enum KEY_STATE
	{
		NONE,	// ������ �ʾҰ�, �������� ������ ���� ����
		TAP,	//��������
		HOLD,	//������ �ִ�
		AWAY,	//�� �� ����
	};

	struct KeyInfo
	{
		KEY_STATE	state;
		bool		isPush;
	};

	struct MouseState
	{
		MouseState()
		{
			x = 0;
			y = 0;
			wheel = 0;
			left = false;
			right = false;
			middle = false;
		}

		int x;
		int y;
		int wheel;
		bool left;
		bool right;
		bool middle;
	};

	class InputSystem
	{
	public:
		static InputSystem* GetInstance();
		static void DestroyInstance();

	public:
		void InitInput();
		void InitMouse();
		void Update();
		KEY_STATE GetKeyState(KEY key);
		void ResetInput();

		void UpdateMouse();

		bool IsSame(const MouseState& a, const MouseState& b);

		const MouseState& GetMouseState();
		const MouseState& GetPrevMouseState();

	private:
		static InputSystem* instance;
		std::vector<KeyInfo> keyList;

		HWND hWnd;
		MouseState curMouse;
		MouseState prevMouse;


	private:
		InputSystem();
		~InputSystem();
	};
}