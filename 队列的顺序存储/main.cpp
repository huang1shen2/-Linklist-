#include"SeqQueue.h"
#include<string.h>

typedef struct PERSON
{
	char name[64];
	int age;
}Person;



int main(void)
{

	//初始化
	SeqQueue* queue = Init_SeqQueue();

	//创建数据
	//Person p1, p2, p3, p4, p5;
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };

	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);
	printf("size= %d\n", Size_SeqQueue(queue));
	while(Size_SeqQueue(queue)>0)
	{
		//取出对头元素
		Person* p = (Person*)Front_SeqQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//从队头弹出元素
		Pop_SeqQueue(queue);
	}

	FreeSpace_SeqQueue(queue);









}