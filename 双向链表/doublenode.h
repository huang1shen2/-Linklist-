#ifndef DOUBLENODE_H_
#define DOUBLENODE_H_
#include<stdio.h>
#include<stdlib.h>


//双向链表节点
typedef struct DOUBLENODES
{
	struct DOUBLENODES* front;
	struct DOUBLENODES* next;
}DoubleNode;

//双向链表结构体
typedef struct DOUBLELIST{

	DoubleNode* nextnode;//下一个节点
	size_t size;///存储节点的个数
}DoubleList;

//比较函数指针
typedef int(*COMPARENODE)(DoubleNode*, DoubleNode*);
//打印函数指针
typedef void(*PRINTNODE)(DoubleNode*);
//初始化链表结构体
DoubleList* Init_DoubleList();
//添加节点
void Add_DoubleList(DoubleList* list,int pos, DoubleNode* value);
//删除节点
void Delete_DoubleList(DoubleList* list, int pos);
//查找
int Find_LinkList(DoubleList* list, DoubleNode* data, COMPARENODE compare);
//返回链表大小
int Size_LinkList(DoubleList* list);
//正向打印
void Print_LinkList(DoubleList* list, PRINTNODE print);
//反向打印
void Print_LinkList_f(DoubleList* list, PRINTNODE print);
//释放链表内存
void FreeSpace_LinkList(DoubleList*list);

#endif