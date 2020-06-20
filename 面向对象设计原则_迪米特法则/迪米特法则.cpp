#include<iostream>
#include<string>
#include<vector>
using namespace std;
class AbstractBuilding{
public:
	virtual void sale() = 0;
	virtual string mQ() = 0;
};

//楼盘A
class BuildingA :public AbstractBuilding{
public:
	BuildingA(){
		mQulity = "高品质";
	}
	virtual void sale()
	{
		cout << "楼盘A" << mQulity << "已经售卖完！" << endl;
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
		mQulity = "低品质";
	}
	virtual void sale()
	{
		cout << "楼盘B" << mQulity << "已经售卖完！" << endl;
	}
	virtual string mQ(){
		return mQulity;
	}
private:
	string mQulity;
};

//客户端
void test01()
{
	BuildingA * ba = new BuildingA;
	if (ba->mQ() == "低品质")
	{
		ba->sale();
	}
	BuildingB * bb = new BuildingB;
	if (bb->mQ() == "低品质")
	{
		bb->sale();
	}
}

//中介类
class Mediator{
public:
	Mediator(){
		AbstractBuilding *building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//对外提供接口
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
//客户端
void test02(){
	Mediator * mediator = new Mediator;
	AbstractBuilding *building = mediator->findMyBuilding("高品质");
	if (building == NULL)
	{
		cout << "没有您需要的楼盘" << endl;
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