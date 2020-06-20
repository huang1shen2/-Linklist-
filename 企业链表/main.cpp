#include<string.h>
#include"LinkList.h"
using namespace std;
typedef struct PERSON{

	LinkNode node;
	char name[64];
	int age;
}Person;


void MyPrint(LinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d\n", p->name, p->age);
}

int MyCompare(LinkNode* node1, LinkNode* node2){
	Person* p1 = (Person*)node1;
	Person* p2 = (Person*)node2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
		return 0;
	return -1;
}
int main()
{
	//创建链表
	LinkList* list = Init_LinkList();

	//创建数据
	Person p1, p2, p3, p4, p5;
	
	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	strcpy_s(p5.name, "eee");
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;


	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	Print_LinkList(list, MyPrint);

	Remove_LinkList(list, 1);
	Print_LinkList(list, MyPrint);

	////查找
	Person findP;
	strcpy_s(findP.name, "ccc");
	findP.age = 30;
	int pos=Find_LinkList(list, (LinkNode*)&findP,MyCompare);
	printf("位置是：%d\n", pos);
	////释放内存
	free(list);
	return 0;
}