//#pragma once
//#include <unordered_map>
//#include <list>
//#include "Define.h"
//class Event;
//class IEventListener;
//
//	/*
//	* 1. ������ ����
//	* 2. �̺�Ʈ �߻��� ��ε�ĳ��Ʈ
//	* 3. �̺�Ʈ Ÿ�� ���� / ������ ����
//	*/
//class EventManager
//{
//private :
//	static EventManager* instance;
//	std::unordered_map < game::EVENT_TYPE, std::list<IEventListener> > m_eventListeners;
//
//public :
//	static EventManager* GetInstance();
//	static void DestroyInstance();
//
//	void AddEventListener(Event* target,IEventListener* listener);
//	void RemoveEventListener(Event* target, IEventListener* listener);
//
//	//game::OBJECT_TYPE GetEventType(Event* event);
//	Event* getEventType(Event* event);
//
//	void logEvent(Event* event);
//
//
//
//private :
//	EventManager();
//	~EventManager();
//};
//
