#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

//链表初始化
LinkList* Init_LinkList()
{
	//malloc一个空间
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinKNode*)malloc(sizeof(LinKNode));
	list->head->data = NULL;
	list->head->next = NULL;
	list->size = 0;
	return list;
}

//指定位置插入数据
void Insert_LinkList(LinkList * list, int pos, void *data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	LinKNode* temp = (LinKNode*)malloc(sizeof(LinKNode));
	temp->data = data;
	temp->next = NULL;
	
	if (pos > list->size)
	{
		pos = list->size;
	}
	if (pos < 0)
	{
		free(temp);
		printf("pos小于零，不符合条件！\n");
		return;
	}
	LinKNode *pCourrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCourrent = pCourrent->next;
	}
	temp->next = pCourrent->next;
	pCourrent->next = temp;
	list->size++;
	return;




}

//删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos)
{
	if (pos < 0 || pos >= list->size)
		return;
	LinKNode *pCourrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCourrent = pCourrent->next;
	}
	LinKNode* temp = pCourrent->next;
	pCourrent->next = temp->next;
	free(temp);
	list->size--;
	

}

//获得链表长度
int Size_ListList(LinkList* list)
{
	return list->size;
}

//返回第一个节点
void *Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}

//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{

	if (list == NULL)
		return;

	LinKNode* pCurrent = list->head;
	while (pCurrent->next!= NULL)
	{
		LinKNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	free(list);

}
	
///查找根据指针
int Find_LinkList(LinkList* list, void* data)
{
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	int i = 1;
	LinKNode* pCurrent = list->head;
	while (pCurrent->next != NULL)
	{
		if (pCurrent->next->data == data)
			break;
		i++;
		pCurrent = pCurrent->next;
	}
	return i;
}

//打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
		return;
	LinKNode * pCurrent = list->head;

		while (pCurrent->next!= NULL)
		{
			print(pCurrent->next->data);
			pCurrent = pCurrent->next;
		}


}