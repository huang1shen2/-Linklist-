#ifndef LINKLIST_H
#define LINKLIST_H

//����ڵ�
typedef struct LINKNODE{
	void* data;//ָ���κ���������
	struct LINKNODE *next;
}LinKNode;

//����ṹ��
typedef struct LINKLIST{

	LinKNode *head;
	int size;
	//û�������ĸ���

}LinkList;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);

//��ʼ������
LinkList* Init_LinkList();
//ָ��λ�ò�������
void Insert_LinkList(LinkList * list, int pos, void *data);
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos);
//���������
int Size_ListList(LinkList* list);
//���ص�һ���ڵ�
void *Front_LinkList(LinkList* list);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);
//���Ҹ���ָ��
int Find_LinkList(LinkList* list, void* data);
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print);






#endif