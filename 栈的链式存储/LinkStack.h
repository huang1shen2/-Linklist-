#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct LINKNODE{
	struct LINKNODE* next;
}LinkNode;

//链式栈
typedef struct LINKSTACK{

	LinkNode head;
	int size;

}LinkStack;

//初始化函数
LINKSTACK* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//出栈
void Pop_LinkStack(LinkStack* stack);
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
//返回栈元素的个数
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁
void  FreeSpace_LinkStack(LinkStack* stack);
#endif