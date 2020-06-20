#ifndef DOUBLENODE_H_
#define DOUBLENODE_H_
#include<stdio.h>
#include<stdlib.h>


//˫������ڵ�
typedef struct DOUBLENODES
{
	struct DOUBLENODES* front;
	struct DOUBLENODES* next;
}DoubleNode;

//˫������ṹ��
typedef struct DOUBLELIST{

	DoubleNode* nextnode;//��һ���ڵ�
	size_t size;///�洢�ڵ�ĸ���
}DoubleList;

//�ȽϺ���ָ��
typedef int(*COMPARENODE)(DoubleNode*, DoubleNode*);
//��ӡ����ָ��
typedef void(*PRINTNODE)(DoubleNode*);
//��ʼ������ṹ��
DoubleList* Init_DoubleList();
//��ӽڵ�
void Add_DoubleList(DoubleList* list,int pos, DoubleNode* value);
//ɾ���ڵ�
void Delete_DoubleList(DoubleList* list, int pos);
//����
int Find_LinkList(DoubleList* list, DoubleNode* data, COMPARENODE compare);
//���������С
int Size_LinkList(DoubleList* list);
//�����ӡ
void Print_LinkList(DoubleList* list, PRINTNODE print);
//�����ӡ
void Print_LinkList_f(DoubleList* list, PRINTNODE print);
//�ͷ������ڴ�
void FreeSpace_LinkList(DoubleList*list);

#endif