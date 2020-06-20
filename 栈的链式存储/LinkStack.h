#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct LINKNODE{
	struct LINKNODE* next;
}LinkNode;

//��ʽջ
typedef struct LINKSTACK{

	LinkNode head;
	int size;

}LinkStack;

//��ʼ������
LINKSTACK* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);
//����ջԪ�صĸ���
int Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����
void  FreeSpace_LinkStack(LinkStack* stack);
#endif