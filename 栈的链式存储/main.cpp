#include"LinkStack.h"
#include<string.h>

static char* k;
typedef struct MYCHAR{

	LinkNode node;
	char* p;
}MyChar;


typedef struct MYINT{

	LinkNode node;
	int p;
}MyInt;



//����MyChar
MyChar* CreateMyChar(char* p)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

void SaveNumber(LinkStack* stack, char *p)
{
	char temp = *p;
	k = (char*)malloc(sizeof(int));
	*k = temp;
	
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(k));
}


//�ж��Ƿ�������
int IsNumber(char c)
{
	return c >= '0'&&c <= '9';
}


//���ֲ���
void NumberOperate(char *p,LinkStack* stack1)
{
	printf("%c", p);
	SaveNumber(stack1,p);
}

//�����Ҳ�����



//�����Ų���
void LeftOperator(LinkStack* stack, char* p)
{
	Push_LinkStack(stack,(LinkNode*)CreateMyChar(p));
}
//�ж��ǲ���������
int IsLeft(char c)
{
	return c == '(';
}
//�ж��ǲ���������
int IsRight(char c)
{
	return c == ')';
}

//�ж����������
int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//����������ŵ����ȼ�
int GetPrioty(char c){
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

//�����Ų���
void RightOperate(LinkStack* stack, LinkStack* stack1)
{
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//���ƥ�䵽������
		if (IsLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		//�������������
		printf("%c", *(mychar->p));
		SaveNumber(stack1, mychar->p);
		Pop_LinkStack(stack);
		//�ͷ��ڴ�
		free(mychar);
	}
}

void OperatorOperate(LinkStack* stack, char* p, LinkStack* stack1)
{
	//��ȡ��ջ������
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;

	}
	if (GetPrioty(*mychar->p) < GetPrioty(*p))
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	else
	{
		while (Size_LinkStack(stack)>=0)
		{
			MyChar* mychar2=(MyChar*)Top_LinkStack(stack);
			//������ȼ��� ��ǰ������ջ
			if (GetPrioty(*mychar2->p)< GetPrioty(*p))
			{
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				break;
			}
			//���
			printf("%c", *(mychar2->p));
			SaveNumber(stack1, mychar2->p);
			//����
			Pop_LinkStack(stack);
			//�ͷ�
		}
	}
	free(mychar);

}




int finish(int c1, int c2, char result)
{
	if (result == '+')
	{
		int sum = c1 + c2;
		return sum;
	}
	if (result == '-')
	{
		int sum = c2 - c1;
		return sum;
	}
	if (result == '*')
	{
		int sum = c1 * c2;
		return sum;
	}
	if (result == '/')
	{
		int sum = c2/c1;
		return sum;
	}
}
int main(void)
{

	//����ջ
	LinkStack* stack = Init_LinkStack();

	char* str = "8+(9-1)*5";
	char* p = str;
	LinkStack* stack1 = Init_LinkStack();
	char result[30];
	while (*p != '\0')
	{ 
		//���������
		if (IsNumber(*p))
		{
			NumberOperate(p,stack1);
		}
		//�����������
		if (IsLeft(*p))
		{
			LeftOperator(stack, p);
		}
		//�����������
		if (IsRight(*p))
		{
			RightOperate(stack,stack1);
		}
		//����������
		if (IsOperator(*p))
		{
			OperatorOperate(stack, p,stack1);
		}
		p++;
	}

    while(Size_LinkStack(stack) > 0)
	{
		printf("%c", *((MyChar*)Top_LinkStack(stack))->p);
		SaveNumber(stack1, ((MyChar*)Top_LinkStack(stack))->p);
		Pop_LinkStack(stack);
	}
	printf("\n");
	int i =Size_LinkStack(stack1)-1;
	int temp = Size_LinkStack(stack1);
	while (Size_LinkStack(stack1) > 0)
	{
		result[i] = *((MyChar*)Top_LinkStack(stack1))->p;
		Pop_LinkStack(stack1);
		i--;
	}
	result[temp] = '\0';
	for (int i = 0; i < temp; i++)
	{
		printf("%c", result[i]);
	}
	printf("\n");
	LinkStack* sum = Init_LinkStack();
	int count1 = 0;
	//MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
	while (result[count1]!='\0')
	{
		///printf("%c",result[count1]);
		 MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
		if (result[count1]>='0'&&result[count1]<='9')
		{
			//MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
			mi->p = int(result[count1] - '0');
			Push_LinkStack(sum, (LinkNode*)mi);
			//printf("%c", *((MyChar*)Top_LinkStack(stack1))->p);
			//free(mi);
		}
		else
		{
			    int c1 = ((MyInt*)Top_LinkStack(sum))->p;
			    Pop_LinkStack(sum);
			    int c2 = ((MyInt*)Top_LinkStack(sum))->p;
			    Pop_LinkStack(sum);
			    int pf = finish(c1, c2,result[count1]);
			    //MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
			    mi->p = pf;
				Push_LinkStack(sum, (LinkNode*)mi);
			    //free(mi);
		}
		if (result[count1+1]=='\0')
		{
			printf("���Ϊ��%d\n", ((MyInt*)Top_LinkStack(sum))->p);
		}
		count1++;
	}
	FreeSpace_LinkStack(stack);
	FreeSpace_LinkStack(stack1);
	FreeSpace_LinkStack(sum);
	//if (Size_LinkStack(stack1)==0)
	//{
	//	printf("true\n");
	//	
	//}
	//else
	//{
	//	printf("false\n");
	//	printf("%c", *((MyChar*)Top_LinkStack(stack1))->p);
	//}

    
}