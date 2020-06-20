#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

typedef struct PERSON{
	char name[64];
	int age;
	int score;

}Person;

void MyPrint(void* data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}
int main()
{
	LinkList * st = Init_LinkList();
	
	Person p1 = { "aaa", 18, 100 };
	Person p2= { "bbb", 19, 55};
	Person p3 = { "ccc", 20, 44 };
	Person p4 = { "ddd", 12, 33 };

	//
	Insert_LinkList(st, 0, &p1);
	Insert_LinkList(st, 2, &p2);
	Insert_LinkList(st, 3, &p3);
	Insert_LinkList(st, 4, &p4);

	Print_LinkList(st, MyPrint);

	printf("\n---------ɾ��֮��----------\n");
	RemoveByPos_LinkList(st, 1);

	//��ӡ
	Print_LinkList(st, MyPrint);

	//������
	printf("����ĳ���Ϊ��%d\n", Size_ListList(st));

	//���������Ԫ��
	printf("����������Ԫ��Ϊ��\n");

	MyPrint(Front_LinkList(st));

	//�������ݲ�����Ӧ���±�
	printf("p3���ڵ�λ���±�Ϊ��%d\n", Find_LinkList(st, &p3));
	//��������
	FreeSpace_LinkList(st);


	return 0;
}


