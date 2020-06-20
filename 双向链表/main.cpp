#include"doublenode.h"
#include<string.h>

#define M 8
#define N 3
//typedef struct PERSON{
//
//	DoubleNode node;
//	char name[64];
//	int age;
//}Person;
//
//void MyPrint(DoubleNode* data)
//{
//	Person* p = (Person*)data;
//	printf("Name:%s Age:%d\n", p->name, p->age);
//}

typedef struct PERSON
{
	
    DoubleNode node;
    //char name[64];
	int age;
}Person;
	
void MyPrint(DoubleNode* data)
{
	Person* p = (Person*)data;
	printf("%d ",p->age);
}

int Compare(DoubleNode* data1, DoubleNode* data2)
{
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;
	if (p1->age == p2->age)
		return 1;
	return -1;
}

//int Compare(DoubleNode* data1, DoubleNode* data2)
//{
//	Person* p1 = (Person*)data1;
//	Person* p2 = (Person*)data2;
//	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
//		return 1;
//	return -1;
//
//}

int main()
{
	DoubleList* list = Init_DoubleList();

	//创建数据
	//Person p1, p2, p3, p4, p5;

	//strcpy_s(p1.name, "aaa");
	//strcpy_s(p2.name, "bbb");
	//strcpy_s(p3.name, "ccc");
	//strcpy_s(p4.name, "ddd");
	//strcpy_s(p5.name, "eee");
	//p1.age = 10;
	//p2.age = 20;
	//p3.age = 30;
	//p4.age = 40;
	//p5.age = 50;


	//Add_DoubleList(list, 0, (DoubleNode*)&p1);
	//Add_DoubleList(list, 0, (DoubleNode*)&p2);
	//Add_DoubleList(list, 0, (DoubleNode*)&p3);
	//Add_DoubleList(list, 0, (DoubleNode*)&p4);
	//Add_DoubleList(list, 0, (DoubleNode*)&p5);

	//Print_LinkList(list,MyPrint);

	//printf("-----------------------\n");
	////反向输出
	//Print_LinkList_f(list, MyPrint);


	////查找
	//Person temp;
	//strcpy_s(temp.name, "ccc");
	//temp.age = 30;
	//int pos = Find_LinkList(list,(DoubleNode*)&temp,Compare);
	//printf("-----------------------\n");
	//Print_LinkList(list, MyPrint);
	//printf("temp的序号为%d,size = %d\n", pos, Size_LinkList(list));


	////删除一个节点
	//Delete_DoubleList(list, pos);
	//printf("--------删除后size = %d-----------\n", Size_LinkList(list));
	////删除后反向输出
	//Print_LinkList_f(list, MyPrint);

	Person p[M];
	for (int i = 0; i < M; i++)
	{
		p[i].age = i+1;
		Add_DoubleList(list,i,(DoubleNode*)&p[i]);
	}


	Print_LinkList(list,MyPrint);
	printf("\n");
	////约瑟夫问题
	int index = 1;
	//辅助指针
	DoubleNode* pCurrent = list->nextnode->next;
	while (Size_LinkList(list) > 1)
	{
		if (index == N)
		{
			Person* temp=(Person*)pCurrent;
			printf("%d ", temp->age);

			//缓存待删除节点的下一个节点
			DoubleNode* pCurrent_next = pCurrent->next;

			//根据值删除
			Delete_DoubleList(list,Find_LinkList(list, pCurrent, Compare));
			pCurrent = pCurrent_next;
			if (pCurrent == NULL)
			{
				pCurrent = list->nextnode->next;
			}
			index = 1;
		}
		pCurrent = pCurrent->next;
		if (pCurrent == NULL)
		{
			pCurrent = list->nextnode->next;
		}
		index++;

	}
	if (Size_LinkList(list) == 1)
	{
		Person* temp = (Person*)pCurrent;
		printf("%d ", temp->age);
	}
	else
	{
		printf("出错！\n");
	}
	printf("\n");


	//析构资源
	FreeSpace_LinkList(list);



	return 0;
}