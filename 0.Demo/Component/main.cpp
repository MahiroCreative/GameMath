#include <iostream>
#include <List>
#include <string>
#include <memory>

class Object
{
public:
	virtual void ShowComponentName() = 0;
};


class GameObject
{
private:
	std::list<Object*> list;
	std::string name = "";

public:
	template<class T> T AddComponent()
	{
		T* buff = new T();
		list.push_back(buff);
		return *buff;
	}

	template<class T> T* GetComponent()
	{
		for (auto item : list)
		{
			T* buff = dynamic_cast<T*>(item);
			if (buff != nullptr)
				return buff;
		}
		return nullptr;
	}

	template<class T> void DelComponent()
	{
		T* ret = nullptr;

		for (auto& item : list)
		{
			T* buff = dynamic_cast<T*>(item);
			if (buff != nullptr)
			{
				ret = buff;
			}
		}

		list.remove(ret);
	}

	void ShowComponents()
	{
		for (auto& item : list)
		{
			item->ShowComponentName();
		}
	}
};

class Text : public Object
{
public:

	void ShowComponentName()override
	{
		printf("Text�ł��B\n");
	}
};

class UI : public Object
{
public:

	void ShowComponentName()override
	{
		printf("UI�ł��B\n");
	}
};

class Pos : public Object
{
	public:
	void ShowComponentName()override
	{
		printf("Pos�ł��B\n");
	}
};


int main()
{
	/*Unity��GetComponent�̕��@�I�Č�*/
	GameObject* obj1 = new GameObject();
	GameObject* obj2 = new GameObject();;

	//Add
	obj1->AddComponent<UI>();
	obj2->AddComponent<Text>();
	obj2->AddComponent<Pos>();

	//GetComponent
	printf("[GetComponent:]\n");
	UI* temp1 = obj1->GetComponent<UI>();
	temp1->ShowComponentName();
	Text* temp2 = obj2->GetComponent<Text>();
	temp2->ShowComponentName();
	Pos* temp3 = obj2->GetComponent<Pos>();
	temp3->ShowComponentName();

	//��L�Ɠ����Ӗ��ł�.
	printf("[��L�Ɠ���:]\n");
	obj1->GetComponent<UI>()->ShowComponentName();
	obj2->GetComponent<Text>()->ShowComponentName();
	obj2->GetComponent<Pos>()->ShowComponentName();

	//DelComponent
	obj2->DelComponent<Pos>();

	//�m�F
	printf("[�S�̂̊m�F:]\n");
	obj1->ShowComponents();
	obj2->ShowComponents();


	delete obj1;
	obj1 = nullptr;
	delete obj2;
	obj2 = nullptr;
	delete temp1;
	temp1 = nullptr;
	delete temp2;
	temp2 = nullptr;
	delete temp3;
	temp3 = nullptr;

}