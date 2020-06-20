#include<iostream>
#include<string>
#include<vector>
using namespace std;
class AbstractBuilding{
public:
	virtual void sale() = 0;
	virtual string mQ() = 0;
};

//¥��A
class BuildingA :public AbstractBuilding{
public:
	BuildingA(){
		mQulity = "��Ʒ��";
	}
	virtual void sale()
	{
		cout << "¥��A" << mQulity << "�Ѿ������꣡" << endl;
	}

	virtual string mQ(){
		return mQulity;
	}
private:
	string mQulity;
};

class BuildingB :public AbstractBuilding{
public:
	BuildingB(){
		mQulity = "��Ʒ��";
	}
	virtual void sale()
	{
		cout << "¥��B" << mQulity << "�Ѿ������꣡" << endl;
	}
	virtual string mQ(){
		return mQulity;
	}
private:
	string mQulity;
};

//�ͻ���
void test01()
{
	BuildingA * ba = new BuildingA;
	if (ba->mQ() == "��Ʒ��")
	{
		ba->sale();
	}
	BuildingB * bb = new BuildingB;
	if (bb->mQ() == "��Ʒ��")
	{
		bb->sale();
	}
}

//�н���
class Mediator{
public:
	Mediator(){
		AbstractBuilding *building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//�����ṩ�ӿ�
	AbstractBuilding * findMyBuilding(string quality){
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if ((*it)->mQ() == quality)
				return *it;
		}
		return NULL;
	}


	~Mediator(){
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if (*it != NULL)
				delete *it;
		}
	}
public:
	vector<AbstractBuilding*> vBuilding;

};
//�ͻ���
void test02(){
	Mediator * mediator = new Mediator;
	AbstractBuilding *building = mediator->findMyBuilding("��Ʒ��");
	if (building == NULL)
	{
		cout << "û������Ҫ��¥��" << endl;
	}
	else
	{
		building->sale();
	}
}

int main()
{
	//test01();
	test02();
	return 0;
}