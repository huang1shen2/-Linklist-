#include"doublenode.h"
#include<string.h>





//初始化链表结构体
DoubleList* Init_DoubleList()
{
	DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
	list->nextnode = (DoubleNode*)malloc(sizeof(DoubleNode)); 
	list->nextnode->front = NULL;
	list->nextnode->next = NULL;
	list->size = 0;
	return list;
}


//添加节点
void Add_DoubleList(DoubleList* list, int pos, DoubleNode* value)
{
	if (list == NULL)
		return;
	if (value == NULL)
		return;
	if (pos<0 || pos>list->size)
		pos = list->size;
	DoubleNode* Currentnext = list->nextnode;
	for (int i = 0; i <pos; i++)
	{
		Currentnext = Currentnext->next;
	}
	if (Currentnext->next== NULL)
	{
		value->front = Currentnext;
		Currentnext->next = value;
		value->next = NULL;
	}
	else
	{
		DoubleNode* Currentnext_next = Currentnext->next;
		Currentnext->next = value;
		value->front = Currentnext;
		value->next = Currentnext_next;
		Currentnext_next->front = value;
	}
	
	list->size++;
}

//正向打印
void Print_LinkList(DoubleList* list, PRINTNODE print)
{
	if (list == NULL)
		return;

	DoubleNode* pCurrent = list->nextnode->next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//反向打印
void Print_LinkList_f(DoubleList* list, PRINTNODE print)
{
	if (list == NULL)
		return;

	DoubleNode* Currentnext = list->nextnode;
	for (int i = 0; i <list->size; i++)
	{
		Currentnext = Currentnext->next;
	}
	DoubleNode* Currentfront = Currentnext;
	while (Currentfront!=list->nextnode)
	{
		print(Currentfront);
		Currentfront = Currentfront->front;
	}



}

//释放链表内存
void FreeSpace_LinkList(DoubleList*list)
{
	if (list == NULL)
		return;
	free(list->nextnode);
	free(list);
}

//删除节点
void Delete_DoubleList(DoubleList* list, int pos)
{
	if (list == NULL)
		return;
	if (pos < 0 || pos >= list->size)
		return;
	DoubleNode* CurrentNode = list->nextnode;
	for (int i = 0; i < pos; i++)
	{
		CurrentNode = CurrentNode->next;
	}
	DoubleNode* CurrentNode_next = CurrentNode->next;
	if (CurrentNode_next->next == NULL)
	{
		CurrentNode->next = NULL;
		CurrentNode_next->front = NULL;
	}
	else
	{
		CurrentNode->next = CurrentNode_next->next;
		CurrentNode_next->next->front = CurrentNode;
		CurrentNode_next->front = NULL;
		CurrentNode_next->next = NULL;

	}
	list->size--;
	return;

}

//查找
int Find_LinkList(DoubleList* list, DoubleNode* data, COMPARENODE compare)
{
	if (list == NULL||data==NULL)
		return -1;
	DoubleNode* CurrentNode = list->nextnode->next;
	int value = 0;
	while (CurrentNode!= NULL)
	{
		if (compare(CurrentNode, data) == 1)
		{
			return value;
		}
		CurrentNode = CurrentNode->next;
		value++;
	}

	return -1;

}

//返回链表大小
int Size_LinkList(DoubleList* list)
{
	if (list == NULL)
		return -1;
	return list->size;
}