#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

//�����ʼ��
LinkList* Init_LinkList()
{
	//mallocһ���ռ�
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinKNode*)malloc(sizeof(LinKNode));
	list->head->data = NULL;
	list->head->next = NULL;
	list->size = 0;
	return list;
}

//ָ��λ�ò�������
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
		printf("posС���㣬������������\n");
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

//ɾ��ָ��λ�õ�ֵ
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

//���������
int Size_ListList(LinkList* list)
{
	return list->size;
}

//���ص�һ���ڵ�
void *Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}

//�ͷ������ڴ�
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
	
///���Ҹ���ָ��
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

//��ӡ����ڵ�
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