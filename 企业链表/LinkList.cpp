#include"LinkList.h"


//初始化链表
LinkList * Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));//分配内存
	list->head.next = NULL;
	list->size = 0;
	return list;
}

//插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	if (pos<0 || pos>list->size) 
	{
		pos = list->size;
	}

	//查找插入位置
	LinkNode* pCurrent = &(list->head);
	//data = (LinkNode*)malloc(sizeof(LinkNode));
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//插入
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++; 

}

//删除
void Remove_LinkList(LinkList* list, int pos)
{

	if (list == NULL)
		return;
	if (pos<0 || pos>=list->size)
	{
		return;
	}
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	LinkNode* temp = pCurrent->next;
	pCurrent->next = temp->next;
	list->size--;
	//free(temp);

}
 

//打印
void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
		return;

	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		free(pCurrent);
	}
	free(list);
}


//查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare)
{
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	LinkNode* pCurrent = list->head.next;
	int index = 0;
	int flag = -1;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent, data) == 0)
		{
			flag = index;
			break;
		}
		pCurrent = pCurrent->next;
		index++;
	}
	return flag;

}